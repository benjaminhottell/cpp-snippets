# sets up a test executable that discovers all unit tests and runs them

cmake_minimum_required(VERSION 3.0)
project(cpp-snippets)

set(LibraryName "cpp-snippets")
set(TestRunnerName "cpp-snippets-tests")

find_package(doctest REQUIRED)


# set up snippet files as a library

file(GLOB_RECURSE LibrarySources src/*.hpp)

add_library(${LibraryName} INTERFACE)

target_sources(${LibraryName} INTERFACE ${LibrarySources})

target_include_directories(${LibraryName} INTERFACE ./src)

# set up tests

file(GLOB_RECURSE TestRunnerSources test/*.cpp test/*.hpp)

add_executable(${TestRunnerName} ${TestRunnerSources})

target_include_directories(${TestRunnerName} PRIVATE ./src ./test)

target_compile_options(${TestRunnerName} PRIVATE -Werror -Wall -Wextra)

target_link_libraries(${TestRunnerName} PUBLIC ${LibraryName} PRIVATE doctest::doctest)

