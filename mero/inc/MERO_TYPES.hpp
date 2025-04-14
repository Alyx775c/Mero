#ifndef _MERO_TYPES
#define _MERO_TYPES

using mWINDOW = void(*);

struct Vector2 
{
    int x, y;
    Vector2(): x(0), y(0) {}
    Vector2(int x, int y): x(x), y(y) {}
};

#endif