#ifndef MERO

#include <GLFW/glfw3.h>

class MERO
{
public:
    bool Initialize()
    {
        if (INIT)
            return 0;
        
        INIT = true;
        return glfwInit();
    };

private:
    static bool INIT;
};

#endif