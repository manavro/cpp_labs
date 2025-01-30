cmake_minimum_required(VERSION 3.14)
project(worker)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenSSL REQUIRED)
find_package(Threads REQUIRED)

include_directories(include)

add_executable(worker src/main.cpp src/password_cracker.cpp)

target_link_libraries(worker OpenSSL::Crypto Threads::Threads)


