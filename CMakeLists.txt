cmake_minimum_required(VERSION 3.18)

# The project name
project(ComponentTree)

if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()


add_subdirectory(third_party/google_test)
add_subdirectory(src)
add_subdirectory(Tests)