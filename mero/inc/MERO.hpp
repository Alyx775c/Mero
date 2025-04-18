#ifndef _MERO_HPP
#define _MERO_HPP

#ifndef _RELEASE
#define _DEBUG
#endif

#include <iostream>
#include <source_location>
#include <filesystem>
#include <format>
#include <string>
#include <vector>
#include <chrono>
#include <thread>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#ifdef _WIN32
#include <Windows.h>
#endif

#include "MERO_COMPONENT.hpp"
#include "MERO_ECS.hpp"
#include "MERO_LOG.hpp"
#include "MERO_WINDOW.hpp"

/**
 * @brief Main Mero class, holds all important info
 * 
 */
class Mero
{
public:
    /**
     * @brief Makes a new Mero instance
     * 
     * @param size Size of window
     * @param name Name of the new window
     * @param testing Configures more verbose output ( planned in the future )
     */
    Mero(glm::ivec2 size, const char* name, bool testing = false);
    ~Mero();

    /**
     * @brief Shuts GLFW and the window down
     * 
     */
    void Shutdown() {
        if (window)
        {
            delete window;
            window = nullptr;
        }
        glfwTerminate(); 
    }

    /**
     * @brief Runs all of the main code
     */
    void MainLoop();
    
    /**
     * @brief Checks if the current MeroWindow is valid
     */
    bool isWindowValid() {
        return window->isValid();
    }

    /**
     * @brief Should I close the window?
     */
    bool ShouldCloseWindow() {
        return window->ShouldClose();
    }
private:
    void Update() {}

    void Render() {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    // has to be a pointer because of the fact that the ctor would shit itself otherwise
    MeroWindow* window;
    // no ent list?? go see MERO_ECS for the actual ecs
    bool INIT;
};

#endif