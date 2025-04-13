#include "MERO_WINDOW.hpp"

#include "MERO.hpp"

C_MeroWindow::C_MeroWindow(int x, int y, const char* name, GLFWmonitor* mon, GLFWwindow* share)
{
    window = glfwCreateWindow(x, y, name, NULL, NULL);
    if (window) {
        MERO_LOG::getInstance().LOG("Successfully initialized window");
    } else {
        MERO_LOG::getInstance().LOG("Failed to initialize window", true);
    }
}

C_MeroWindow::~C_MeroWindow()
{
}
