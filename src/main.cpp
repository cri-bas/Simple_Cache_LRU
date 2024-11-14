#include <iostream>
#include <vector>
#include "../include/Cache.h"
#include "../include/CacheBlock.h"
#include "../include/CacheSet.h"

void readInput(int &size, int &associativity, std::vector<int> &references) {
    std::cout << "Enter the number of cache blocks: ";
    std::cin >> size;

    std::cout << "Enter the set associativity option (1 for direct-mapped, 2 or 4 for set associative, 0 for fully associative): ";
    std::cin >> associativity;

    if (associativity == 0) {
        // Fully associative: set associativity to the total number of blocks
        associativity = size;
    } else if (size % associativity != 0) {
        // Validate that size is divisible by associativity
        std::cerr << "Error: Number of blocks must be divisible by associativity.\n";
        exit(1);
    }

    std::cout << "Enter the sequence of block address references (end with -1): ";
    int address;
    while (std::cin >> address && address != -1) {
        references.push_back(address);
    }
}

int main() {
    int size, associativity;
    std::vector<int> references;

    // Read input from the user
    readInput(size, associativity, references);

    // Initialize the cache
    Cache cache(size, associativity);

    // Print the header once at the beginning
    cache.printHeader();

    // Access each block in the sequence and print result
    for (int address : references) {
        cache.access(address);
    }

    // Print the final miss rate
    cache.printMissRate();

    return 0;
}