# Orderbook Implementation

Hello! This is an implementation of a simple OrderBook as guided by Dmitri Nesteruk on Youtube.

Catch his full tutorial here!
- https://www.youtube.com/watch?v=fxN4xEZvrxI&t=1354s&ab_channel=DmitriNesteruk

## Project Lessons

1. How to include Google Test as a static library in our project, by git cloning it.
2. Practice using CMakeLists.txt to auto-generate our CMake file. 

specifically being comfortable with using 

- `add_subdirectory` to include sub directories as part of your CMake pipeline
- `include_subdirectory` to allow a module to import from another subdirectory
- `target_link_libraries` to link a library to another library