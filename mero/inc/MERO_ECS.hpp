#ifndef _MERO_ECS
#define _MERO_ECS

#include <vector>

// Forward declaration of C_BaseComponent
class C_BaseComponent;

class C_mECS
{
public:
    void PushComponent(C_BaseComponent* comp)
    {
        components.push_back(comp);
    }

    int Size()
    {
        return components.size();
    }

private:
    std::vector<C_BaseComponent*> components;
};

#endif