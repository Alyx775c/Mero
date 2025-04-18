#ifndef _MERO_INH_COMPONENT
#define _MERO_INH_COMPONENT

#include <string>

#include "MeroECS.h"

/**
 * @brief The base component class, dont use, inherit
 * 
 */
class MeroComponent
{
protected:
    /**
     * @brief Construct a new Component object
     * 
     * @param componentName 
     */
    MeroComponent(const std::string& componentName)
        : name(componentName)
    { }

    std::string name;

public:
    std::string GetName() {
        return name;
    }

    /**
     * @brief Initializiation method
     * 
     */
    virtual void Initialize() {};

    /**
     * @brief Method to call on tick
     * 
     */
    virtual void Tick() {};

    /**
     * @brief Call! Check out tApp.cpp for example
     * 
     */
    void Register() {
        mECS->PushComponent(this);
    }

    virtual ~MeroComponent()
    {
    }

    // Don't assign this is assigned in MERO_COMPONENT.cpp
    static C_mECS *mECS;
};

/**
 * @brief MERO class helper for sprties
 * 
 * typically used inside of a class with a MERO_SPRITE*
 */
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