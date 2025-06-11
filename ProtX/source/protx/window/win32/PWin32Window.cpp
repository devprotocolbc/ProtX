//
// Created by BasLocal on 09/06/2025.
//

#include <Windows.h>
#include "protx/window/PWindow.h"
#include "glad/glad_wgl.h"
#include "glad/glad.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_DESTROY: {
            protx::PWindow *window = (protx::PWindow *) GetWindowLongPtr(hwnd, GWLP_USERDATA);
            break;
        }
        case WM_CLOSE: {
            PostQuitMessage(0);
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
    wc.style = CS_OWNDC;


    auto classId = RegisterClassEx(&wc);
    assert(classId); // TODO: make all asserts an exception

    RECT rc = {0, 0, 1280, 720};
    AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW | WS_CAPTION | WS_SYSMENU, false);

    m_handle = CreateWindowEx(NULL, MAKEINTATOM(classId), "DEV://BC | ProtX",
                              WS_OVERLAPPEDWINDOW | WS_CAPTION | WS_SYSMENU,
                              CW_USEDEFAULT, CW_USEDEFAULT, rc.right - rc.left, rc.bottom - rc.top,NULL,NULL,NULL,NULL);

    assert(m_handle);

    SetWindowLongPtr((HWND) m_handle, GWLP_USERDATA, (LONG_PTR) this);

    ShowWindow((HWND) m_handle, SW_SHOW);
    UpdateWindow((HWND) m_handle);

    //Creating OpenGL Render Context

    auto hDC = GetDC((HWND) m_handle);

    int pixelformatAttributes[] = {
        WGL_DRAW_TO_WINDOW_ARB, GL_TRUE,
        WGL_SUPPORT_OPENGL_ARB, GL_TRUE,
        WGL_DOUBLE_BUFFER_ARB, GL_TRUE,
        WGL_ACCELERATION_ARB, WGL_FULL_ACCELERATION_ARB,
        WGL_PIXEL_TYPE_ARB, WGL_TYPE_RGBA_ARB,
        WGL_COLOR_BITS_ARB, 32,
        WGL_DEPTH_BITS_ARB, 24,
        WGL_STENCIL_BITS_ARB, 8,
        0
    };

    int pixelformat = 0;
    UINT numFormats = 0;
    wglChoosePixelFormatARB(hDC, pixelformatAttributes, nullptr, 1, &pixelformat, &numFormats);
    assert(numFormats);

    PIXELFORMATDESCRIPTOR pixelformatdescriptor = {};
    DescribePixelFormat(hDC, pixelformat, sizeof(PIXELFORMATDESCRIPTOR), &pixelformatdescriptor);
    SetPixelFormat(hDC, pixelformat, &pixelformatdescriptor);

    int openGLAttributes[]{
        WGL_CONTEXT_MAJOR_VERSION_ARB, 4,
        WGL_CONTEXT_MINOR_VERSION_ARB, 6,
        WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
        0
    };

    m_context = wglCreateContextAttribsARB(hDC, 0, openGLAttributes);
    assert(m_context);
}

protx::PWindow::~PWindow() {
    wglDeleteContext(HGLRC(m_context));
    DestroyWindow((HWND) m_handle);
}

void protx::PWindow::makeCurrentContext() {
    wglMakeCurrent(GetDC(HWND(m_handle)), HGLRC(m_context));
}

void protx::PWindow::present(bool vsync) {
    wglSwapIntervalEXT(vsync);
    wglSwapLayerBuffers(GetDC(HWND(m_handle)), WGL_SWAP_MAIN_PLANE);
}

// protx
