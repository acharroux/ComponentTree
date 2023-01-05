
project(ComponentTreeTests)
include(GoogleTest)


# The test program
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(version_tests version_tests.cpp)
target_link_libraries(version_tests PRIVATE ComponentTreeLib gtest_main)

gtest_discover_tests(version_tests)