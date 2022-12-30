project(framework)

# This lib is only headers so there is no PRIVATE info

add_library(ComponentTreeLib INTERFACE)
target_include_directories(ComponentTreeLib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

set(CMAKE_CXX_STANDARD 17)
target_compile_features(ComponentTreeLib INTERFACE cxx_std_17 )


