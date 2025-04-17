#ifndef _MERO_INH_COMPONENT
#define _MERO_INH_COMPONENT

#include <string>

#include "MERO_ECS.hpp"

class C_BaseComponent
{
protected:
    C_BaseComponent(const std::string& componentName)
        : name(componentName)
    { }

    std::string name;

public:
    std::string GetName() {
        return name;
    }

    virtual void Initialize() {};
    virtual void Tick() {};

    void Register() {
        mECS->PushComponent(this);
    }

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