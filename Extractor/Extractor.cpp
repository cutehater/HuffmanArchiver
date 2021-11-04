#include "Extractor.h"
#include "../Messenger/Messenger.h"

#include <ostream>
#include <fstream>

Extractor::Extractor(std::istream& input_stream) : archive_reader_(input_stream){};

size_t Extractor::ExtractArchive() {
    size_t number_of_files = 1;

    while (ExtractFile()) {
        ++number_of_files;
    };

    return number_of_files;
}

bool Extractor::ExtractFile() {
    size_t symbols_count = archive_reader_.ReadNineBits();

    if (symbols_count > MAX_SYMBOLS_COUNT) {
        throw std::invalid_argument("archive data is damaged");
    }

    std::vector<Trie::EncodedSymbol> encoded_symbols(symbols_count);

    for (auto& encoded_symbol : encoded_symbols) {
        encoded_symbol.symbol_ = archive_reader_.ReadNineBits();
    }

    size_t current_code_length = 0;
    size_t current_code_length_counter = 0;
    size_t current_code_value = 0;

    for (auto& encoded_symbol : encoded_symbols) {
        while (current_code_length_counter == 0) {
            ++current_code_length;
            current_code_value <<= 1;
            current_code_length_counter = archive_reader_.ReadNineBits();
        }

        encoded_symbol.code_length_ = current_code_length;
        encoded_symbol.code_value_ = current_code_value++;
        --current_code_length_counter;

        if (static_cast<size_t>(1 << encoded_symbol.code_length_) <= encoded_symbol.code_value_) {
            throw std::invalid_argument("archive data is damaged");
        }
    }

    if (current_code_length_counter != 0) {
        throw std::invalid_argument("archive data is damaged");
    }

    Trie trie(encoded_symbols);

    std::string new_file_name;

    size_t current_symbol = GetSymbol(trie);

    while (current_symbol != FILENAME_END) {
        new_file_name.push_back(static_cast<unsigned char>(current_symbol));
        current_symbol = GetSymbol(trie);
    }

    std::ofstream new_file(new_file_name);

    current_symbol = GetSymbol(trie);

    while (current_symbol != ONE_MORE_FILE && current_symbol != ARCHIVE_END) {
        new_file << static_cast<unsigned char>(current_symbol);
        current_symbol = GetSymbol(trie);
    }

    new_file.close();

    if (current_symbol == ARCHIVE_END) {
        char c;
        if (archive_reader_.GetChar(c)) {
            throw std::invalid_argument("archive data is damaged");
        }
    }

    return current_symbol == ONE_MORE_FILE;
}

size_t Extractor::GetSymbol(Trie& trie) {
    while (!trie.IsCurrentNodeTerminal()) {
        if (!trie.GoDown(archive_reader_.ReadBit())) {
            throw std::invalid_argument("archive data is damaged");
        }
    }

    return trie.GetDecodedSymbol();
}