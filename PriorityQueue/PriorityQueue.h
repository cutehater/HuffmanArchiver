#pragma once

#include <vector>

template <typename KeyType, typename ValueType>
class PriorityQueue {
public:
    struct KeyValuePair {
        KeyType key_;
        ValueType value_;
    };

    size_t Size();
    bool Empty();

    KeyType GetKey();
    ValueType GetValue();

    void Add(KeyType key, ValueType value);
    void Delete();

private:
    std::vector<KeyValuePair> elements_;
};