//
// Created by BasLocal on 11/06/2025.
//

#ifndef PGRAPHICSENGINE_H
#define PGRAPHICSENGINE_H
#include "glad/glad.h"
#include <assert.h>
#include "protx/math/PVec4.h"

namespace protx {
    class PGraphicsEngine {
    public:
        PGraphicsEngine();

        ~PGraphicsEngine();

    public:
        void clear(const PVec4 &_color);
    };
}


#endif //PGRAPHICSENGINE_H
