#include <catch2/catch_test_macros.hpp>
#include "MERO.hpp"

class mTestComponent : public C_BaseComponent
{
public:
    mTestComponent()
    {
    }

    void Initialize() override
    {
    }
};

TEST_CASE("Test app", "[app]")
{
    MERO *mero = new MERO(Vector2(400, 400), "test app", true);
    mTestComponent *component = new mTestComponent();

    REQUIRE(C_BaseComponent::mECS->Size() == 1);
}