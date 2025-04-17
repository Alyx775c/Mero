#include "MERO_ECS.hpp"

#include "MERO.hpp"

void C_mECS::PushComponent(C_BaseComponent* comp)
{
    MERO_LOG::getInstance().LOG(std::format("Adding component with name: {}", comp->GetName()));
    if (comp) {
        components.push_back(comp);
        comp->Initialize(); // Calls C_BaseComponent::Initialize, not mTestComponent::Initialize
    }
}