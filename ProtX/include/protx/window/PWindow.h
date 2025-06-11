//
// Created by BasLocal on 09/06/2025.
//

#ifndef PWINDOW_H
#define PWINDOW_H

#include <assert.h>

namespace protx {
    class PWindow {
    public:
        PWindow();
        ~PWindow();

        void makeCurrentContext();

        void present(bool vsync);

    private:
        void* m_handle = nullptr;
        void *m_context = nullptr;
    };
} // protx

#endif //PWINDOW_H
