cmake_minimum_required(VERSION 3.16)
project(CommandPattern LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Pattern code, shared by the demo and the tests.
add_library(command_lib STATIC
    src/Character.cpp
    src/MoveCommand.cpp
)
target_include_directories(command_lib PUBLIC include)

add_executable(command_demo src/main.cpp)
target_link_libraries(command_demo PRIVATE command_lib)

enable_testing()
add_executable(command_tests tests/command_tests.cpp)
target_link_libraries(command_tests PRIVATE command_lib)
add_test(NAME command_tests COMMAND command_tests)
