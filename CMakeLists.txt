cmake_minimum_required(VERSION 3.15)
project(hexedit LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(hexedit
  src/main.cpp
  src/FileIO.cpp
  src/View.cpp
  src/Convert.cpp
  src/EditController.cpp
)
target_include_directories(hexedit PRIVATE include)
