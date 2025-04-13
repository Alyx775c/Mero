#ifndef _MERO_INH_COMPONENT
#define _MERO_INH_COMPONENT

#include "MERO_ECS.hpp"

class C_BaseComponent 
{
protected:
    C_BaseComponent()
    {
        mECS->PushComponent(this);
    }

public:
    virtual ~C_BaseComponent()
    {
        
    }
    
    static C_mECS* mECS;
};

#endif