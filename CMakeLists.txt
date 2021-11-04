cmake_minimum_required(VERSION 2.8)
project(HuffmanArchiver)

set(CMAKE_CXX_STANDARD 20)

add_executable(archiver main.cpp PriorityQueue/PriorityQueue.cpp)

add_library(ARCHIVER Archiver/Archiver.cpp)
add_library(ARGUMENT_PARSER ArgumentParser/ArgumentParser.cpp)
add_library(EXTRACTOR Extractor/Extractor.cpp)
add_library(MESSENGER Messenger/Messenger.cpp)
add_library(PRIORITY_QUEUE PriorityQueue/PriorityQueue.cpp)
add_library(READER Reader/Reader.cpp)
add_library(TRIE Trie/Trie.cpp)
add_library(WRITER Writer/Writer.cpp)

target_link_libraries(archiver ARCHIVER ARGUMENT_PARSER EXTRACTOR MESSENGER PRIORITY_QUEUE READER TRIE WRITER)
