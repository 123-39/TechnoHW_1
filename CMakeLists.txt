cmake_minimum_required(VERSION 3.1)
project(HW_1 C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-g -O0 -Wextra -Wall -Wextra -Wpedantic -lgcov --coverage)
add_link_options( -O0 -lgcov --coverage)

set(MAIN_FILE project/src/main.c)
set(LIB_HEADERS_PATH project/head)

set(SOURCE_LIB project/src/data.c project/src/print.c project/src/recomend.c)
add_library(hw_1_lib STATIC ${SOURCE_LIB})
target_include_directories(hw_1_lib PUBLIC ${LIB_HEADERS_PATH})

add_executable(hw_1 ${MAIN_FILE})
target_link_libraries(hw_1 hw_1_lib m pthread)

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(hw_1_test project/tests/test.cpp)
target_link_libraries(hw_1_test ${GTEST_LIBRARIES} hw_1_lib m pthread)

