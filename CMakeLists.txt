cmake_minimum_required(VERSION 3.30)
project(izip CXX)

include("init.cmake")
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(${PROJECT_NAME} "${SOURCES}")


target_link_libraries(${PROJECT_NAME} PUBLIC CLI11::CLI11 spdlog::spdlog fmt::fmt archive)


add_executable(${IZIP_TEST_EXE} "${TEST_SOURCES}")

target_link_libraries(${IZIP_TEST_EXE} PRIVATE gtest ${TEST_DESCRIPTORS})

# Defs
add_compile_definitions(PARAM_LENGTH=3)
add_compile_definitions(GENERAL_SIZE=1)