cmake_minimum_required(VERSION 3.3)
project(OrderBookDemo)

# Update this to the directory boost is installed on your machine.
set(BOOST_ROOT /Users/gohchangmingclement/boost_1_81_0/)

set(GOOGLETEST_VERSION 1.13.0)

# REQUIRED -> Fail with error if Boost is not found
find_package(Boost REQUIRED)

# add_definitions(-std==c++11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(OrderBookDemo ${SOURCE_FILES})

# This makes OrderBook as a library visible
include_directories(OrderBook)

include_directories(${Boost_INCLUDE_DIRS})

# Add a subdirectory to the build
# CMakeList.txt in the source directory(OrderBook), will be processed before continuing
add_subdirectory(OrderBook)
add_subdirectory(OrderBookTests)

# specify libraries or flags to use when linking a given target or dependents
target_link_libraries(OrderBookDemo OrderBook)
target_link_libraries(OrderBookDemo ${Boost_LIBRARIES})