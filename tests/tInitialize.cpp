#include <catch2/catch_test_macros.hpp>
#include "MERO.hpp"

TEST_CASE("Testing if created window is valid", "[init]") {
    MERO* m = new MERO(Vector2(400, 400), "Test Window", true);

    REQUIRE(m->isWindowValid() == true);
}