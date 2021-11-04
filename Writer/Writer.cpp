#include "Writer.h"

Writer::Writer(std::ostream& output_stream) : output_stream_(output_stream){};

void Writer::WriteSymbol(size_t new_symbol, size_t new_symbol_size) {
    for (int64_t bit = new_symbol_size - 1; bit >= 0; --bit) {
        OutputByteIfNeeded();

        current_byte_ |= (1 << used_bits_) * (static_cast<bool>(new_symbol & (1 << bit)));
        ++used_bits_;
    }
}

void Writer::WriteNineBitsValue(size_t new_symbol_code) {
    for (size_t bit = 0; bit < NINE_BITS; ++bit) {
        OutputByteIfNeeded();

        current_byte_ |= (1 << used_bits_) * (static_cast<bool>(new_symbol_code & (1 << bit)));
        ++used_bits_;
    }
}

void Writer::ForceOutputByte() {
    if (used_bits_ > 0) {
        used_bits_ = CHAR_SIZE;
        OutputByteIfNeeded();
    }
}

void Writer::OutputByteIfNeeded() {
    if (used_bits_ == CHAR_SIZE) {
        output_stream_ << current_byte_;

        current_byte_ = 0;
        used_bits_ = 0;
    }
}