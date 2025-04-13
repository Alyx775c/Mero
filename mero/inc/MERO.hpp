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
#include <GLFW/glfw3.h>

#ifdef _WIN32
#include <Windows.h>
#endif

#include "MERO_CLASSES.hpp"
#include "MERO_LOG.hpp"
#include "MERO_TYPES.hpp"

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
    C_MeroWindow* window;
    bool INIT;
};

#endif