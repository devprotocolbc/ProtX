//
// Created by BasLocal on 11/06/2025.
//

#include "protx/protx/ProtX.h"

void protx::ProtX::run() {
    MSG msg;
    while (m_isRunning && !m_display->isClosed()) {
        if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        Sleep(1);
    }
}
