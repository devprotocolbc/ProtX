//
// Created by BasLocal on 11/06/2025.
//

#include <Windows.h>
#include "protx/protx/ProtX.h"

void protx::ProtX::run() {
    MSG msg;
    onCreate();
    while (m_isRunning) {
        if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE)) {
            if (msg.message == WM_QUIT) {
                m_isRunning = false;
                continue;
            } else {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        onUpdate();
    }
    onQuit();
}
