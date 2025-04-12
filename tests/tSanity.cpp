#include <catch2/catch_test_macros.hpp>
#include "MERO.hpp"

TEST_CASE("Basic math works", "[math]") {
    REQUIRE(1 + 1 == 2);
    REQUIRE(2 - 3 == -1);
}