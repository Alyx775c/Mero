#ifndef _MERO_INH_COMPONENT
#define _MERO_INH_COMPONENT

#include "MERO_ECS.hpp"

class C_BaseComponent 
{
public:
    C_BaseComponent()
    {
        mECS->PushComponent(this);
    }

    ~C_BaseComponent()
    {
        
    }
private:
    static C_mECS* mECS;
};

#endif