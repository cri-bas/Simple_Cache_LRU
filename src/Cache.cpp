#include "../include/Cache.h"
#include <iostream>
#include <iomanip>
#include <string>

// Helper function to pad strings to a fixed width
std::string padString(const std::string &str, int width) {
    if (str.length() < width) {
        return str + std::string(width - str.length(), ' ');
    }
    return str;
}

// Constructor for the Cache class
// Initializes a cache based on the specified size and associativity

Cache::Cache(int s, int a) {
    size = s;                  // Set the total number of cache blocks
    associativity = a;         // Set the associativity level (e.g., 1 for direct-mapped, 2 for 2-way set-associative, 0 for fully associative)
    sets = s / a;              // Calculate the number of sets by dividing the total size by the associativity level
    cache.resize(sets, CacheSet(a)); // Resize the cache to hold the correct number of sets, each containing the specified number of blocks
    hits = 0;                  // Initialize the hit count to zero
    misses = 0;                // Initialize the miss count to zero
}

// Function to print the header once
void Cache::printHeader() const {
    std::cout << "\n"
              << padString("A", 8) << "  "
              << padString("Hit/Miss", 10);
    for (int i = 0; i < associativity; ++i) {
        std::cout << "| " << padString("Block " + std::to_string(i), 10) << " ";
    }
    std::cout << "\n---------------------------------------------------------------------------------\n";
}

// Function to access a cache block and print the result
void Cache::access(int address) {
    int setIndex = address % sets; // Calculate set index
    int tag = address / sets;      // Calculate tag

    CacheSet &set = cache[setIndex];
    bool hit = false;
    int blockIndex = -1;

    // Check for hit
    for (int i = 0; i < associativity; i++) {
        if (set.blocks[i].valid && set.blocks[i].tag == tag) {
            hit = true;
            blockIndex = i;
            break;
        }
    }

    // Print the access result with aligned output
    std::cout << padString(std::to_string(address), 8) << "  ";
    if (hit) {
        hits++;
        std::cout << padString("HIT", 10);
    } else {
        misses++;
        std::cout << padString("MISS", 10);

        // LRU policy: replace least recently used block
        blockIndex = set.lru.front();
        set.lru.pop_front();
        set.lru.push_back(blockIndex);
    }

    // Update block tag and validity
    set.blocks[blockIndex].tag = tag;
    set.blocks[blockIndex].valid = true;

    // Print the cache content after this access
    printCacheState();
}

// Function to print the current state of the cache
void Cache::printCacheState() const {
    for (int i = 0; i < sets; ++i) {
        std::cout << padString(" ", 8) << "  ";  // Empty space under 'A' and 'Hit/Miss'
        for (int j = 0; j < associativity; ++j) {
            if (cache[i].blocks[j].valid) {
                std::cout << "| " << padString("Mem[" + std::to_string(cache[i].blocks[j].tag) + "]", 10);
            } else {
                std::cout << "| " << padString("Empty", 10);
            }
        }
        std::cout << "\n";
    }
}

// Function to print the cache miss rate
void Cache::printMissRate() const {
    std::cout << "Cache miss rate: " << std::fixed << std::setprecision(2) << (double)misses / (hits + misses) << "\n";
}