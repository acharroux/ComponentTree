

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# This lib is only headers so there is no PRIVATE info

add_library(ComponentTreeLib INTERFACE)
target_include_directories(ComponentTreeLib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})


target_compile_features(ComponentTreeLib INTERFACE cxx_std_17 )


