//
// Created by BasLocal on 09/06/2025.
//

#include "protx/protx/ProtX.h"

#include <Windows.h>
#include "protx/window/PWindow.h"

protx::ProtX::ProtX() {
    m_display = std::unique_ptr<PWindow>(new PWindow());
}

protx::ProtX::~ProtX() {
}

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

void protx::ProtX::quit() {
    m_isRunning = false;
}
