#include <catch2/catch_test_macros.hpp>
#include "Mero.h"

class mTestComponent: 
    public MeroComponent
{
public:
    mTestComponent()
        : MeroComponent("Test Component")
    {
        // at the end of the comp we register
        Register();
    }

    void Initialize() override
    {
        MeroLogger::getInstance().LOG("hi from init test component");
    }
};

TEST_CASE("Test app", "[app]")
{
    Mero *mero = new Mero(glm::ivec2(400, 400), "test app", true);
    REQUIRE(MeroComponent::mECS->Size() == 0);

    mTestComponent *component = new mTestComponent();

    while (mero && !mero->ShouldCloseWindow())
    {
        mero->MainLoop();
    }

    REQUIRE(MeroComponent::mECS->Size() == 1);

    mero->Shutdown();
}