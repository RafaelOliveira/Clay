#ifndef OBJECT_H
#define OBJECT_H

#include "raylib.h"

class Object
{
    public:
    
        virtual void Update();
        virtual void Draw();
};

#endif