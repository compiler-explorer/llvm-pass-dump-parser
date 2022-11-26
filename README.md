# llvm-pass-dump-parser


### Example usage

`/opt/compiler-explorer/clang-15.0.0/bin/clang++ -gdwarf-4 -g -o ./output.s -mllvm --x86-asm-syntax=intel -S --gcc-toolchain=/opt/compiler-explorer/gcc-12.2.0 -fno-crash-diagnostics --std=c++20 ./example.cpp -mllvm --print-before-all -mllvm --print-after-all -fno-discard-value-names | llvm-pass-dump-parser`
