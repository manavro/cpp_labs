cmake_minimum_required(VERSION 3.14)

project(Fibonacci LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_library(fibonacci STATIC src/fibonacci.cpp)

add_executable(main src/main.cpp)
target_link_libraries(main fibonacci)

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Изменено имя исполняемого файла
add_executable(fibonacci_tests tests/test_fibonacci.cpp)
target_link_libraries(fibonacci_tests fibonacci ${GTEST_LIBRARIES} pthread)

# Обновлено имя теста
add_test(NAME FibonacciTests COMMAND fibonacci_tests)

add_custom_target(run_tests ALL
    COMMAND ${CMAKE_COMMAND} -E echo "Запуск тестов..."
    COMMAND ctest
    DEPENDS fibonacci_tests
)
