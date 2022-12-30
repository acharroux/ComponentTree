
project(ComponentTreeTests)

# The test program
set(CMAKE_CXX_STANDARD 17)
add_executable(version_tests version_tests.cpp)
target_link_libraries(version_tests PRIVATE ComponentTreeLib gtest_main)
add_test(NAME version_tests COMMAND version_tests)
