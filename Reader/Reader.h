#pragma once

#include <istream>

class Reader {
public:
    const size_t CHAR_SIZE = 8;
    const size_t NINE_BITS = 9;

    explicit Reader(std::istream &input_stream);

    bool ReadBit();
    size_t ReadNineBits();

    bool GetChar(char& c);

    void FlushInput();

private:
    std::istream &input_stream_;

    unsigned char current_byte_ = 0;
    size_t read_bits_ = CHAR_SIZE;
};