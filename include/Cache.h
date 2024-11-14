#ifndef CACHE_H
#define CACHE_H

#include <vector>
#include "CacheSet.h"

class Cache {
public:
    int size;          // Total number of blocks in the cache
    int sets;          // Number of sets in the cache
    int associativity; // Set associativity of the cache
    int hits;          // Number of cache hits
    int misses;        // Number of cache misses
    std::vector<CacheSet> cache; // The sets in the cache

    Cache(int s, int a);
    void access(int address);

    void printMissRate() const;
    void printHeader() const;
    void printCacheState() const;

};

#endif