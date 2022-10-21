
cmake_minimum_required(VERSION 3.24.0)

project(sort
VERSION 1.0
LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)

add_executable(treeSO tests/test.cpp src/Item.cpp src/treeListNode.cpp src/treeList.cpp src/treeSO.cpp)
target_include_directories(treeSO PUBLIC ${PROJECT_SOURCE_DIR}/include)



# add the executable