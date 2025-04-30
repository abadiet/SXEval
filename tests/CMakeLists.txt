set(TARGET_NAME sxeval_tests)

find_package(Catch2 3 REQUIRED)

file(GLOB TEST_SOURCES "*.cpp")
add_executable(${TARGET_NAME} ${TEST_SOURCES})

target_link_libraries(${TARGET_NAME} PRIVATE sxeval Catch2::Catch2WithMain)

include(CTest)
include(Catch)
catch_discover_tests(${TARGET_NAME})
