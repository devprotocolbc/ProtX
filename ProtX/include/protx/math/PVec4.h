//
// Created by BasLocal on 12/06/2025.
//

#ifndef PVEC4_H
#define PVEC4_H

#include "protx/Prerequesites.h"

namespace protx {
    class PVec4 {
    public:
        PVec4() {
        }

        PVec4(f32 _x, f32 _y, f32 _z, f32 _w) : x(_x), y(_y), z(_z), w(_w) {
        }

        ~PVec4() {
        }

    public:
        f32 x, y, z, w;
    };
}

#endif //PVEC4_H
