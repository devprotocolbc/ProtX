//
// Created by BasLocal on 09/06/2025.
//

#ifndef PWINDOW_H
#define PWINDOW_H

#include <Windows.h>
#include <assert.h>

namespace protx {
    class PWindow {
    public:
        PWindow();
        ~PWindow();

        void onDestroy();
        bool isClosed();

    private:
        void* m_handle = nullptr;
    };
} // protx

#endif //PWINDOW_H
