cmake_minimum_required(VERSION 3.10)
project(asm-parser)

set(CMAKE_CXX_STANDARD 20)
add_compile_options(-Werror -Wall -Wextra -Wconversion)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=leak -fsanitize=address -fsanitize=undefined -static-libasan")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

set(CMAKE_VERBOSE_MAKEFILE on)

include(CheckIPOSupported)
check_ipo_supported()
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION_DEBUG FALSE)

if (NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/v0.16.1/conan.cmake"
            "${CMAKE_BINARY_DIR}/conan.cmake"
            TLS_VERIFY ON)
endif ()

include(${CMAKE_BINARY_DIR}/conan.cmake)

conan_check(VERSION 1.43.1 REQUIRED)

conan_cmake_run(
        REQUIRES
        catch2/3.2.0
        fmt/9.1.0
        ctre/3.7.1
        BASIC_SETUP
        BUILD missing)

include(${CMAKE_BINARY_DIR}/conan.cmake)

enable_testing()

add_subdirectory(src)
