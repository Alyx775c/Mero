#ifndef _MERO_ECS
#define _MERO_ECS

#include <vector>

class MeroComponent;

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
    void PushComponent(MeroComponent* comp); 

    int Size()
    {
        return components.size();
    }

private:
    std::vector<MeroComponent*> components;
};

#endif