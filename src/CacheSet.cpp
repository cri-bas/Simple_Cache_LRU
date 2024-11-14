#include "../include/CacheSet.h"

CacheSet::CacheSet(int n) {
    associativity = n;
    blocks.resize(n);
    for (int i = 0; i < n; i++) {
        lru.push_back(i); // Initialize the LRU list
    }
}