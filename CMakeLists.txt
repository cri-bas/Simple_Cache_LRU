cmake_minimum_required(VERSION 3.29)
project(Simple_Cache_LRU)

set(CMAKE_CXX_STANDARD 20)

add_executable(Simple_Cache_LRU src/main.cpp
        src/CacheBlock.cpp
        include/CacheBlock.h
        src/CacheSet.cpp
        include/CacheSet.h
        src/Cache.cpp
        include/Cache.h)
