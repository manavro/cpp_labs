cmake_minimum_required(VERSION 3.14)

project(stack LANGUAGES CXX)

# Установка стандарта C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Указание директории с заголовочными файлами
include_directories(include)

# Создание статической библиотеки из Stack.cpp
add_library(stack STATIC src/Stack.cpp)

# Создание исполняемого файла main
add_executable(main src/main.cpp)
target_link_libraries(main stack)

# Включение тестирования
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Создание исполняемого файла для тестов
add_executable(stack_tests tests/StackTests.cpp)
target_link_libraries(stack_tests stack ${GTEST_LIBRARIES} pthread)

# Регистрация тестов
add_test(NAME stackTests COMMAND stack_tests)

# Создание пользовательской цели для запуска тестов
add_custom_target(run_tests ALL
    COMMAND ${CMAKE_COMMAND} -E echo "Запуск тестов..."
    COMMAND ctest
    DEPENDS stack_tests
)
