#include "PriorityQueue.h"
#include "../Trie/Trie.h"

template <typename KeyType, typename ValueType>
size_t PriorityQueue<KeyType, ValueType>::Size() {
    return elements_.size();
}

template <typename KeyType, typename ValueType>
bool PriorityQueue<KeyType, ValueType>::Empty() {
    return elements_.empty();
}

template <typename KeyType, typename ValueType>
KeyType PriorityQueue<KeyType, ValueType>::GetKey() {
    return elements_[0].key_;
}

template <typename KeyType, typename ValueType>
ValueType PriorityQueue<KeyType, ValueType>::GetValue() {
    return elements_[0].value_;
}

template <typename KeyType, typename ValueType>
void PriorityQueue<KeyType, ValueType>::Add(KeyType key, ValueType value) {
    elements_.emplace_back(KeyValuePair{.key_ = key, .value_ = value});

    size_t current_pos = Size() - 1;
    size_t parent_pos = (current_pos - 1) / 2;

    while (current_pos > 0 && elements_[parent_pos].key_ > key) {
        std::swap(elements_[current_pos], elements_[parent_pos]);

        current_pos = parent_pos;
        parent_pos = (current_pos - 1) / 2;
    }
}

template <typename KeyType, typename ValueType>
void PriorityQueue<KeyType, ValueType>::Delete() {
    std::swap(elements_[0], elements_[elements_.size() - 1]);
    elements_.pop_back();

    size_t current_pos = 0;
    size_t left_son_pos = current_pos * 2 + 1;
    size_t right_son_pos = current_pos * 2 + 2;

    while (left_son_pos < Size() && std::min(elements_[left_son_pos].key_,
                                             elements_[right_son_pos < Size() ? right_son_pos : left_son_pos].key_) <
                                    elements_[current_pos].key_) {
        size_t min_pos = left_son_pos;
        if (right_son_pos < Size() && elements_[left_son_pos].key_ > elements_[right_son_pos].key_) {
            min_pos = right_son_pos;
        }

        std::swap(elements_[current_pos], elements_[min_pos]);

        current_pos = min_pos;
        left_son_pos = current_pos * 2 + 1;
        right_son_pos = current_pos * 2 + 2;
    }
}

template class PriorityQueue<size_t, Trie::Node*>;