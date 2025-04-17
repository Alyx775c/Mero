#ifndef _MERO_ECS
#define _MERO_ECS

#include <vector>

class C_BaseComponent;

class C_mECS
{
public:
    void PushComponent(C_BaseComponent* comp); 

    int Size()
    {
        return components.size();
    }

private:
    std::vector<C_BaseComponent*> components;
};

#endif