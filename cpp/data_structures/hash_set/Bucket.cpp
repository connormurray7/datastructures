#include "Bucket.h"
#include <vector>
#include <iostream>

template<typename T>
Bucket<T>::Bucket() {
    node = nullptr;
}

template<typename T>
Bucket<T>::Bucket(HashSetNode<T>& n) {
    node = &n;
}

template<typename T>
bool Bucket<T>::contains(const T& key) {
    return find(key) != nullptr;
}

template<typename T>
void Bucket<T>::add(const T& key) {
    auto new_node = std::make_shared<HashSetNode<T>>(key);
    if(isEmpty()) {
        node = new_node;
        return;
    }
    auto cur = node;
    while(cur->next != nullptr) {
        cur = cur->next;
    }
    cur->next = new_node;
}

template<typename T>
bool Bucket<T>::remove(const T& key) {
    if(isEmpty()) {
        return false;
    }
    auto cur = node;
    std::shared_ptr<HashSetNode<T>> prev = nullptr;
    while(cur != nullptr && cur->key != key) {
        prev = cur;
        cur = cur->next;
    }
    if(cur == nullptr) {
        return false; //key not found.
    }
    if(prev == nullptr) {
        node = node->next;
    } else {
        prev->next = cur->next;
    }
    return true;
}

template<typename T>
bool Bucket<T>::isEmpty() {
    return node == nullptr;
}

template<typename T>
std::vector<T> Bucket<T>::get_keys() {
    std::vector<T> v;
    auto cur = node;
    while(cur != nullptr) {
        v.push_back(cur->key);
        cur = cur->next;
    }
    return v;
}

template<typename T>
std::shared_ptr<HashSetNode<T>> Bucket<T>::find(const T& key) {
    auto cur = node;
    while(cur != nullptr && cur->key != key) {
        cur = cur->next;
    }
    return cur;
}
