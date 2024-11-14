#include "../include/CacheBlock.h"

// Constructor for CacheBlock class
// Initializes a cache block with default values
CacheBlock::CacheBlock() {
    tag = -1;        // Set the initial tag to -1, indicating an empty or uninitialized block
    valid = false;   // Set the valid bit to false, meaning the block is initially invalid
    freq = 0;        // Initialize the frequency (or usage count) to 0, useful for replacement policies like LFU
}