#include "Reader.h"

Reader::Reader(std::istream& input_stream) : input_stream_(input_stream){};

bool Reader::ReadBit() {
    if (read_bits_ == CHAR_SIZE) {
        char c;
        if (!input_stream_.get(c)) {
            throw std::invalid_argument("unexpected end of file");
        }

        current_byte_ = static_cast<unsigned char>(c);
        read_bits_ = 0;
    }

    return static_cast<bool>(current_byte_ & (1 << (read_bits_++)));
}

size_t Reader::ReadNineBits() {
    size_t answer = 0;

    for (size_t i = 0; i < NINE_BITS; ++i) {
        answer |= static_cast<size_t>(ReadBit()) * (1 << i);
    }

    return answer;
}

bool Reader::GetChar(char& c) {
    ;
    return static_cast<bool>(input_stream_.get(c));
}

void Reader::FlushInput() {
    input_stream_.clear();
    input_stream_.seekg(0, input_stream_.beg);
}