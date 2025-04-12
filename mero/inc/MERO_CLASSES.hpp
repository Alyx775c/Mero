#ifndef _MERO_CLASS_DEF
#define _MERO_CLASS_DEF

#include <GLFW/glfw3.h>

#include "MERO_TYPES.hpp"

class C_MeroWindow
{
private:
    mWINDOW* window;
public:
    C_MeroWindow();
    ~C_MeroWindow();
};

#endif