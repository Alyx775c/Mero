#include <catch2/catch_test_macros.hpp>
#include "MERO.hpp"

// for some reason this doesnt work on windows?? dog ass system
TEST_CASE("Testing if created window is valid", "[init]") {
    MERO* m = new MERO(glm::ivec2(400, 400), "Test Window", true);

    REQUIRE(m->isWindowValid() == true);
}