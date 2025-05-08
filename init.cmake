#Variables
set(IZIP_TEST_EXE "test")
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/source")
set(TEST_DIR "${CMAKE_SOURCE_DIR}/test")

set(SOURCES
    ${SOURCE_DIR}/main.cpp
    ${SOURCE_DIR}/App.cpp
    ${SOURCE_DIR}/Appctor.cpp
    ${SOURCE_DIR}/comp_file/File.cpp
    ${SOURCE_DIR}/comp_help/Help.cpp
    ${SOURCE_DIR}/comp_file/archive_computation.cpp
    ${SOURCE_DIR}/comp_file/recursive_processing.cpp
)

set(TEST_SOURCES
    ${TEST_DIR}/main.cpp
    ${SOURCE_DIR}/comp_help/Help.cpp
    ${TEST_DIR}/comp_help/descriptors/param_help_descriptors.cpp
    ${TEST_DIR}/comp_help/descriptors/param_descriptor.cpp
    ${TEST_DIR}/comp_help/descriptors/general_message.cpp

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
#add_subdirectory(${CMAKE_SOURCE_DIR}/indicators)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Local source folders
include_directories(${COMP_CMAKE_SOURCE})


# Direct compiler options.

add_compile_options("-std=c++20")
