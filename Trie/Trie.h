#pragma once

#include <vector>

class Trie {
public:
    struct EncodedSymbol {
        size_t symbol_;
        size_t code_value_;
        size_t code_length_;
    };

    explicit Trie(const std::vector<size_t>& symbols_priority);
    explicit Trie(const std::vector<EncodedSymbol>& canonical_encoded_symbols);
    ~Trie();

    std::vector<EncodedSymbol> GetCanonicalSymbolsCodes();

    bool IsCurrentNodeTerminal();
    bool GoDown(bool bit);

    size_t GetDecodedSymbol();

private:
    class Node {
    public:
        bool is_terminal_ = false;
        size_t terminal_symbol_ = 0;

        bool was_visited_by_canonical_bypass_ = false;

        Node* parent_ = nullptr;
        Node* left_son_ = nullptr;
        Node* right_son_ = nullptr;
    };

    Node* root_;
    Node* current_state_;
};