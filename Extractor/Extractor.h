#pragma once

#include "../Reader/Reader.h"
#include "../Trie/Trie.h"

#include <istream>

class Extractor {
public:
    const size_t FILENAME_END = 256;
    const size_t ONE_MORE_FILE = 257;
    const size_t ARCHIVE_END = 258;
    const size_t MAX_SYMBOLS_COUNT = 259;

    explicit Extractor(std::istream& input_stream);

    size_t ExtractArchive();  // return number of extracted files

private:
    bool ExtractFile();  // return false if the extracted file is the last one

    size_t GetSymbol(Trie& trie);

    Reader archive_reader_;
};