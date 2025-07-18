#Variables
set(IZIP_TEST_EXE "test")
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/source")
set(TEST_DIR "${CMAKE_SOURCE_DIR}/test")


set(SOURCES
        ${SOURCE_DIR}/main.cpp
        ${SOURCE_DIR}/App.cpp
        ${SOURCE_DIR}/Appctor.cpp
        ${SOURCE_DIR}/comp_file/FileComputation.cpp
        ${SOURCE_DIR}/comp_file/ArchiveComputation.cpp
        ${SOURCE_DIR}/comp_file/FileCompression.cpp
        ${SOURCE_DIR}/comp_file/File.cpp
)

set(TEST_SOURCES
        ${TEST_DIR}/main.cpp
        ${TEST_DIR}/FileTest.cpp
        ${TEST_DIR}/FileMockTest.cpp
        ${SOURCE_DIR}/comp_file/File.cpp
        #${SOURCE_DIR}/comp_file/ArchiveComputation.cpp
        #${SOURCE_DIR}/comp_file/FileCompression.cpp
        #${SOURCE_DIR}/comp_file/FileComputation.cpp
)

include_directories(
    ${CMAKE_SOURCE_DIR}/test
    ${SOURCE_DIR}/comp_help
    ${SOURCE_DIR}/comp_file
    ${SOURCE_DIR}
    ${TEST_DIR}/test/help_test
    ${TEST_DIR}/test
)

add_subdirectory(${CMAKE_SOURCE_DIR}/fmt)
add_subdirectory(${CMAKE_SOURCE_DIR}/spdlog)
add_subdirectory(${CMAKE_SOURCE_DIR}/googletest)
add_subdirectory(${CMAKE_SOURCE_DIR}/libarchive)
add_subdirectory(${CMAKE_SOURCE_DIR}/CLI11)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${SOURCE_DIR})
include_directories(${TEST_DIR})

# Local source folders
include_directories(${COMP_CMAKE_SOURCE})


# Direct compiler options.
add_compile_options("-std=c++23")
add_compile_options("-g")
add_compile_options("-pedantic")
add_compile_options("-Wextra")

# Preprocessor symbols
add_compile_definitions(
        TEST_TARGET_FILE="file_test.c"
        TEST_TARGET_FILE_WT_EXT="file_test"
)

