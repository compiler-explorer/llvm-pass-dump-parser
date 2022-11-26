add_library(llvm-pass-dump-parser-lib STATIC
    utils/debug.cpp
)
target_link_libraries(llvm-pass-dump-parser-lib PUBLIC ${CONAN_LIBS})

add_executable(llvm-pass-dump-parser main.cpp)

target_link_libraries(llvm-pass-dump-parser llvm-pass-dump-parser-lib)

add_subdirectory(test)