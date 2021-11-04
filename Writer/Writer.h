#pragma once

#include <ostream>

class Writer {
public:
    const size_t NINE_BITS = 9;
    const size_t CHAR_SIZE = 8;

    explicit Writer(std::ostream& output_stream);

    void WriteSymbol(size_t new_symbol, size_t new_symbol_size);

    void WriteNineBitsValue(size_t new_symbol_code);

    void ForceOutputByte();

private:
    std::ostream& output_stream_;

    unsigned char current_byte_ = 0;
    size_t used_bits_ = 0;

    void OutputByteIfNeeded();
};