#ifndef _MERO_ECS
#define _MERO_ECS

#include <vector>

class C_BaseComponent;

/**
 * @brief Mero's ECS system, dont interface directly
 * 
 */
class C_mECS
{
public:
    /**
     * @brief Pushes a new component to the vector
     * 
     * @param comp The component to push
     */
    void PushComponent(C_BaseComponent* comp); 

    int Size()
    {
        return components.size();
    }

private:
    std::vector<C_BaseComponent*> components;
};

#endif