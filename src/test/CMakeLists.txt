add_executable(llvm-pass-dump-parser-test basic_tests.cpp)
target_link_libraries(llvm-pass-dump-parser-test llvm-pass-dump-parser-lib)
add_test(NAME llvm-pass-dump-parser-test COMMAND $<TARGET_FILE:llvm-pass-dump-parser-test>)
