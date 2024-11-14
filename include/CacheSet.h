#ifndef CACHESET_H
#define CACHESET_H

#include <vector>
#include <list>
#include <queue>
#include "CacheBlock.h"

class CacheSet {
public:
    int associativity;            // Number of blocks in the set
    std::vector<CacheBlock> blocks; // Blocks in the set
    std::list<int> lru;           // LRU list of the blocks

    CacheSet(int n);
};

#endif