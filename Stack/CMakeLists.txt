cmake_minimum_required (VERSION 3.1)

project(Stack VERSION 1.0)

enable_language(CXX)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(test)

file(GLOB_RECURSE stack *.cpp *.h)

add_library(stack_lib SHARED ${stack})
target_include_directories(stack_lib ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(CLANG_TIDY_FLAGS
    clang-tidy;
    -checks=*;
    -header-filter=.;
    -warnings-as-errors=*;
    )

set_target_properties(${TEST} PROPERTIES CXX_CLANG_TIDY "${CLANG_TIDY_FLAGS}")

add_custom_target(
        clang-format
        COMMAND clang-format
        -i
        ${stack})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -Wpedantic -Wcast-qual -Wcast-align -Wconversion \
    -Wsign-promo -Wfloat-equal -Wenum-compare -Wold-style-cast -Wredundant-decls -Wsign-conversion -Wnon-virtual-dtor \
    -Wctor-dtor-privacy -Woverloaded-virtual -Wno-float-equal"
)