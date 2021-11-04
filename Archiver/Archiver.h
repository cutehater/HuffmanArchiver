#pragma once

#include "../Reader/Reader.h"
#include "../Writer/Writer.h"
#include "../Trie/Trie.h"

#include <iostream>
#include <string_view>
#include <vector>
#include <unordered_map>

class Archiver {
public:
    const size_t FILENAME_END = 256;
    const size_t ONE_MORE_FILE = 257;
    const size_t ARCHIVE_END = 258;
    const size_t MAX_SYMBOLS_COUNT = 259;

    explicit Archiver(std::ostream& output_stream);

    void AddFile(std::istream& input_stream, const std::string_view& input_stream_name);

    void ArchiveEnd();

private:
    void GetCodes(Reader& input_reader, const std::string_view& input_stream_name);

    std::vector<size_t> CountSymbolsPriority(Reader& input_reader, const std::string_view& input_stream_name);

    void WriteMetadata();
    void WriteFileName(const std::string_view& input_stream_name);
    void WriteFileData(Reader& input_reader);

    void FileEnd();

    Writer archive_writer_;
    std::vector<Trie::EncodedSymbol> symbols_codes_;
    std::unordered_map<size_t, Trie::EncodedSymbol> symbols_codes_fast_access_;
    bool is_archive_end_ = false;
};