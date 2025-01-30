cmake_minimum_required(VERSION 3.10)
project(PrimeCalculator)

set(CMAKE_CXX_STANDARD 11)


include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/external/plog/include)


add_executable(prime_calculator src/main.cpp src/number.cpp)



