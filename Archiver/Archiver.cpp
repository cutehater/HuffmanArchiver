#include "Archiver.h"

Archiver::Archiver(std::ostream& output_stream) : archive_writer_(output_stream){};

void Archiver::AddFile(std::istream& input_stream, const std::string_view& input_stream_name) {
    if (is_archive_end_) {
        throw std::invalid_argument("can't write to the closed archive");
    }

    if (!symbols_codes_.empty()) {
        FileEnd();
    }

    Reader input_reader(input_stream);

    GetCodes(input_reader, input_stream_name);
    WriteMetadata();
    WriteFileName(input_stream_name);
    WriteFileData(input_reader);
}

void Archiver::GetCodes(Reader& input_reader, const std::string_view& input_stream_name) {
    std::vector<size_t> symbols_priority = CountSymbolsPriority(input_reader, input_stream_name);
    Trie trie(symbols_priority);

    symbols_codes_ = trie.GetCanonicalSymbolsCodes();

    for (const auto& encoded_symbol : symbols_codes_) {
        symbols_codes_fast_access_.emplace(encoded_symbol.symbol_, encoded_symbol);
    }
}

std::vector<size_t> Archiver::CountSymbolsPriority(Reader& input_reader, const std::string_view& input_stream_name) {
    std::vector<size_t> symbols_frequency(MAX_SYMBOLS_COUNT);

    symbols_frequency[FILENAME_END] = 1;
    symbols_frequency[ONE_MORE_FILE] = 1;
    symbols_frequency[ARCHIVE_END] = 1;

    for (char c : input_stream_name) {
        ++symbols_frequency[static_cast<unsigned char>(c)];
    }

    char c;
    while (input_reader.GetChar(c)) {
        ++symbols_frequency[static_cast<unsigned char>(c)];
    }

    input_reader.FlushInput();

    return symbols_frequency;
}

void Archiver::WriteMetadata() {
    archive_writer_.WriteNineBitsValue(symbols_codes_.size());

    for (const auto& encoded_symbol : symbols_codes_) {
        archive_writer_.WriteNineBitsValue(encoded_symbol.symbol_);
    }

    for (size_t symbol_code_length = 1; symbol_code_length <= symbols_codes_.back().code_length_;
         ++symbol_code_length) {
        size_t current_length_counter = 0;
        for (const auto& encoded_symbol : symbols_codes_) {
            if (encoded_symbol.code_length_ == symbol_code_length) {
                ++current_length_counter;
            }
        }

        archive_writer_.WriteNineBitsValue(current_length_counter);
    }
}

void Archiver::WriteFileName(const std::string_view& input_stream_name) {
    for (char c : input_stream_name) {
        const auto& symbol = symbols_codes_fast_access_[static_cast<unsigned char>(c)];
        archive_writer_.WriteSymbol(symbol.code_value_, symbol.code_length_);
    }

    archive_writer_.WriteSymbol(symbols_codes_fast_access_[FILENAME_END].code_value_,
                                symbols_codes_fast_access_[FILENAME_END].code_length_);
}

void Archiver::WriteFileData(Reader& input_reader) {
    char c;
    while (input_reader.GetChar(c)) {
        const auto& symbol = symbols_codes_fast_access_[static_cast<unsigned char>(c)];
        archive_writer_.WriteSymbol(symbol.code_value_, symbol.code_length_);
    }
}

void Archiver::FileEnd() {
    archive_writer_.WriteSymbol(symbols_codes_fast_access_[ONE_MORE_FILE].code_value_,
                                symbols_codes_fast_access_[ONE_MORE_FILE].code_length_);

    symbols_codes_.clear();
    symbols_codes_fast_access_.clear();
}

void Archiver::ArchiveEnd() {
    archive_writer_.WriteSymbol(symbols_codes_fast_access_[ARCHIVE_END].code_value_,
                                symbols_codes_fast_access_[ARCHIVE_END].code_length_);

    archive_writer_.ForceOutputByte();

    is_archive_end_ = true;
}
