#include "Trie.h"
#include "../PriorityQueue/PriorityQueue.h"

using NodePriority = size_t;

Trie::Trie(const std::vector<size_t>& symbols_priority) {
    PriorityQueue<size_t, Node*> node_queue;

    for (size_t i = 0; i < symbols_priority.size(); ++i) {
        if (symbols_priority[i] > 0) {
            node_queue.Add(symbols_priority[i], new Node{.is_terminal_ = true, .terminal_symbol_ = i});
        }
    }

    while (node_queue.Size() > 1) {
        size_t left_son_priority = node_queue.GetKey();
        Node* left_son = node_queue.GetValue();
        node_queue.Delete();

        size_t right_son_priority = node_queue.GetKey();
        Node* right_son = node_queue.GetValue();
        node_queue.Delete();

        auto new_node = new Node{.left_son_ = left_son, .right_son_ = right_son};
        node_queue.Add(left_son_priority + right_son_priority, new_node);

        left_son->parent_ = new_node;
        right_son->parent_ = new_node;
    }

    root_ = node_queue.GetValue();
    current_state_ = root_;
}

Trie::Trie(const std::vector<EncodedSymbol>& canonical_encoded_symbols) {
    root_ = new Node;
    current_state_ = root_;

    for (const auto& encoded_symbol : canonical_encoded_symbols) {
        for (int64_t bit = encoded_symbol.code_length_ - 1; bit >= 0; --bit) {
            bool is_son_right = ((1 << bit) & encoded_symbol.code_value_);

            if (!is_son_right) {
                if (current_state_->left_son_ == nullptr) {
                    current_state_->left_son_ = new Node;
                    current_state_->left_son_->parent_ = current_state_;
                }

                current_state_ = current_state_->left_son_;
            } else {
                if (current_state_->right_son_ == nullptr) {
                    current_state_->right_son_ = new Node;
                    current_state_->right_son_->parent_ = current_state_;
                }

                current_state_ = current_state_->right_son_;
            }
        }

        current_state_->is_terminal_ = true;
        current_state_->terminal_symbol_ = encoded_symbol.symbol_;
        current_state_ = root_;
    }
}

Trie::~Trie() {
    current_state_ = root_;

    while (current_state_ != nullptr) {
        if (current_state_->left_son_ != nullptr) {
            Node* tmp_node = current_state_->left_son_;
            current_state_->left_son_ = nullptr;
            current_state_ = tmp_node;

        } else if (current_state_->right_son_ != nullptr) {
            Node* tmp_node = current_state_->right_son_;
            current_state_->right_son_ = nullptr;
            current_state_ = tmp_node;

        } else {
            Node* tmp_node = current_state_->parent_;
            delete current_state_;
            current_state_ = tmp_node;
        }
    }
}

std::vector<Trie::EncodedSymbol> Trie::GetCanonicalSymbolsCodes() {
    std::vector<Trie::EncodedSymbol> encoded_symbols;

    size_t current_code_length = 0;

    while (current_state_ != nullptr) {
        current_state_->was_visited_by_canonical_bypass_ = true;
        if (!current_state_->is_terminal_ && !current_state_->left_son_->was_visited_by_canonical_bypass_) {
            current_state_ = current_state_->left_son_;
            ++current_code_length;
        } else if (!current_state_->is_terminal_ && !current_state_->right_son_->was_visited_by_canonical_bypass_) {
            current_state_ = current_state_->right_son_;
            ++current_code_length;
        } else {
            if (current_state_->is_terminal_) {
                encoded_symbols.push_back(
                        EncodedSymbol{.symbol_ = current_state_->terminal_symbol_, .code_length_ = current_code_length});
            }

            current_state_ = current_state_->parent_;
            --current_code_length;
        }
    }
    current_state_ = root_;

    std::sort(encoded_symbols.begin(), encoded_symbols.end(), [](const auto& lhs, const auto& rhs) {
        return (lhs.code_length_ < rhs.code_length_) ||
               (lhs.code_length_ == rhs.code_length_ && lhs.symbol_ < rhs.symbol_);
    });

    size_t current_code_value = 0;
    current_code_length = 1;

    for (auto& encoded_symbol : encoded_symbols) {
        while (current_code_length < encoded_symbol.code_length_) {
            ++current_code_length;
            current_code_value <<= 1;
        }

        encoded_symbol.code_value_ = current_code_value++;
    }

    return encoded_symbols;
}

bool Trie::IsCurrentNodeTerminal() {
    return current_state_->is_terminal_;
}

bool Trie::GoDown(bool bit) {  // return false if the archive is damaged and we haven't where we need to go
    if (!bit) {
        if (!current_state_->left_son_) {
            return false;
        } else {
            current_state_ = current_state_->left_son_;
            return true;
        }
    } else {
        if (!current_state_->right_son_) {
            return false;
        } else {
            current_state_ = current_state_->right_son_;
            return true;
        }
    }
}

size_t Trie::GetDecodedSymbol() {
    size_t answer = current_state_->terminal_symbol_;
    current_state_ = root_;

    return answer;
}