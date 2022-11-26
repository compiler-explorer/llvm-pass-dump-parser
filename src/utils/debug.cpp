#include "debug.hpp"

void assert(bool condition, std::string_view message)
{
    if (!condition) {
        throw message;
        // const stack = new Error('Assertion Error').stack;
        // throw (
        //     (message
        //         ? `Assertion error in llvm-print-after-all-parser: ${message}`
        //         : `Assertion error in llvm-print-after-all-parser`) +
        //     (args.length > 0 ? `\n${JSON.stringify(args)}\n` : '') +
        //     `\n${stack}`
        // );
    }
}
