#ifndef CACHEBLOCK_H
#define CACHEBLOCK_H

class CacheBlock {
public:
    int tag;   // The tag of the block
    bool valid; // The valid bit of the block
    int freq;   // The frequency of the block (for LFU policy)

    CacheBlock();
};

#endif