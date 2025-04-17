#include <catch2/catch_test_macros.hpp>
#include "MERO.hpp"

class mTestComponent : public C_BaseComponent
{
public:
    mTestComponent()
        : C_BaseComponent("Test Component")
    {
        // at the end of the comp we register
        Register();
    }

    void Initialize() override
    {
        MERO_LOG::getInstance().LOG("hi from init test component");
    }
};

TEST_CASE("Test app", "[app]")
{
    MERO *mero = new MERO(glm::ivec2(400, 400), "test app", true);
    REQUIRE(C_BaseComponent::mECS->Size() == 0);

    mTestComponent *component = new mTestComponent();

    while (mero && !mero->ShouldCloseWindow())
    {
        mero->MainLoop();
    }

    REQUIRE(C_BaseComponent::mECS->Size() == 1);

    mero->Shutdown();
}