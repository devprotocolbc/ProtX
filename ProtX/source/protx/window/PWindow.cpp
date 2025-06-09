//
// Created by BasLocal on 09/06/2025.
//

#include "protx/window/PWindow.h"
#include <Windows.h>
#include <assert.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_DESTROY: {
            protx::PWindow* window = (protx::PWindow*)GetWindowLongPtr(hwnd, GWLP_USERDATA);
            window->onDestroy();
            break;
        }

        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return NULL;
}

protx::PWindow::PWindow() {
    WNDCLASSEX wc = {};
    wc.cbSize = sizeof(wc);
    wc.lpszClassName = "ProtXWindow";
    wc.lpfnWndProc = &WndProc;

    assert(RegisterClassEx(&wc));

    RECT rc = {0, 0, 1280, 720};
    AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW | WS_CAPTION | WS_SYSMENU, false);

    m_handle = CreateWindowEx(NULL, wc.lpszClassName, "DEV://BC | ProtX", WS_OVERLAPPEDWINDOW | WS_CAPTION | WS_SYSMENU,
                   CW_USEDEFAULT, CW_USEDEFAULT, rc.right - rc.left, rc.bottom - rc.top,NULL,NULL,NULL,NULL);

    assert(m_handle);

    SetWindowLongPtr((HWND)m_handle, GWLP_USERDATA, (LONG_PTR)this);

    ShowWindow((HWND)m_handle, SW_SHOW);
    UpdateWindow((HWND)m_handle);
}

protx::PWindow::~PWindow() {
    DestroyWindow((HWND)m_handle);
}

void protx::PWindow::onDestroy() {
    m_handle = nullptr;
}

bool protx::PWindow::isClosed() {
    return !m_handle;
}

// protx
