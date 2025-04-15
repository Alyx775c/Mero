#ifndef _MERO_INH_COMPONENT
#define _MERO_INH_COMPONENT

#include <string>

#include "MERO_ECS.hpp"

class C_BaseComponent
{
protected:
    C_BaseComponent()
    {
        mECS->PushComponent(this);
    }

    virtual void Initialize() {};
    virtual void Tick() {};

public:
    virtual ~C_BaseComponent()
    {
    }

    static C_mECS *mECS;
};

class MERO_SPRITE
{
protected:
    std::string path;

public:
    MERO_SPRITE(const std::string &texturePath)
        : path(texturePath)
    {
        LoadTexture();
    }

    bool LoadTexture() {
        return true;
    };

    ~MERO_SPRITE() {

    };
};

#endif