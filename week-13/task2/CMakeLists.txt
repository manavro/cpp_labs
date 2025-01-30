cmake_minimum_required(VERSION 3.14)

project(StackExample LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include_directories(include)


find_package(OpenSSL REQUIRED)


add_library(stack STATIC src/password.cpp)


add_executable(main src/main.cpp)


target_link_libraries(main stack OpenSSL::SSL OpenSSL::Crypto)


set(TARGET_HASH "8c8e9f2a4a2e3b0b7e9f0f6b1a3c5b7d" CACHE STRING "Hash to search for")


add_custom_target(run
    COMMAND main ${TARGET_HASH} 5
    DEPENDS main
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)


add_custom_target(clean-all
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_CURRENT_BINARY_DIR}
    DEPENDS main
)






