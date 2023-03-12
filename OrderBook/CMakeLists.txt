project (OrderBook)

add_definitions(-std=c++11)

set(HEADER_FILES OrderBook.h)
set(SOURCE_FILES OrderBook.cpp)

# make this folder a library
add_library(OrderBook STATIC ${SOURCE_FILES} ${HEADER_FILES})
