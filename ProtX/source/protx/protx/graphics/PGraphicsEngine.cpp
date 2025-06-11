//
// Created by BasLocal on 11/06/2025.
//

#include "protx/graphics/PGraphicsEngine.h"


void protx::PGraphicsEngine::clear(const PVec4 &_color) {
    glClearColor(_color.x, _color.y, _color.z, _color.w);
    glClear(GL_COLOR_BUFFER_BIT);
}
