#include <string>
#include <vector>
#include <memory>


#ifndef TRIE_NODE_H
#define TRIE_NODE_H

#define ALPHABET_START 'a'
#define ALPHABET_SIZE 26;

template<typename T>
struct TrieNode {
    T val;
    std::vector<std::shared_ptr<TrieNode<T>>> children;

    TrieNode() {
        children = std::vector<std::shared_ptr<TrieNode<T>>>();
        children.reserve(26);
        for(int i = 0; i < 26; ++i) { children[i] = nullptr; }
    }
    
    std::shared_ptr<TrieNode<T>> get_or_emplace(char letter) {
        int idx = letter - ALPHABET_START;
        if(children[idx] == nullptr) {
            children[idx] = std::make_shared<TrieNode<T>>();
        }
        return children[idx];
    }
};

#endif
