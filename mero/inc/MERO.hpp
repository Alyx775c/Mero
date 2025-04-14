#ifndef _MERO

#ifndef _RELEASE
#define _DEBUG
#endif

#include <iostream>

#include <source_location>

// i promise this isnt being used to scan files, check MERO_LOG.hpp
// for more information regarding why this was included
#include <filesystem>
#include <format>
#include <string>
#include <vector>

#ifdef _WIN32
#include <Windows.h>
#endif

#include "MERO_COMPONENT.hpp"
#include "MERO_ECS.hpp"
#include "MERO_LOG.hpp"
#include "MERO_TYPES.hpp"
#include "MERO_WINDOW.hpp"

/**
 * Main MERO class, holds all MERO related data besides types
 * and structs
 */
class MERO
{
public:
    /**
     * @param size Size of window
     * @param name Name of the new window
     * @param testing Configures more verbose output ( planned in the future )
     */
    MERO(Vector2 size, const char* name, bool testing = false);
    ~MERO();
    
    /**
     * Checks if the current C_MeroWindow is valid
     */
    bool isWindowValid() {
        return window->isValid();
    }
private:
    // has to be a pointer because of the fact that the ctor would shit itself otherwise
    C_MeroWindow* window;
    // no ent list?? go see MERO_ECS for the actualy ecs
    bool INIT;
};

#endif