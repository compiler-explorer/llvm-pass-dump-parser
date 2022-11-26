#include <catch2/catch_test_macros.hpp>

TEST_CASE("Hello world test", "[asm]")
{
    int fourtytwo = 7 * 6;
    REQUIRE(fourtytwo == 42);
}
