cmake_minimum_required(VERSION 3.10)

# Options
option(BUILD_EXAMPLES "Build examples" ON)
option(BUILD_TESTS "Performs tests" OFF)
option(SXEVAL_DEBUG "Debug mode" OFF)

# Project
project(sxeval)
set(SXEVAL_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/include)
add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE ${SXEVAL_INCLUDE})

# Examples
if(BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

# Tests
if(BUILD_TESTS)
    message(STATUS "Adding tests")
    include(FetchContent)

    FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG 2b60af89e23d28eefc081bc930831ee9d45ea58b # v3.8.1
    )
    FetchContent_MakeAvailable(Catch2)

    enable_testing()
    add_subdirectory(tests)
endif()
