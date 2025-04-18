#include "MERO_ECS.hpp"

#include "MERO.hpp"

void C_mECS::PushComponent(MeroComponent* comp)
{
    MeroLogger::getInstance().LOG(std::format("Adding component with name: {}", comp->GetName()));
    if (comp) {
        components.push_back(comp);
        comp->Initialize(); // Calls MeroComponent::Initialize, not mTestComponent::Initialize
    }
}