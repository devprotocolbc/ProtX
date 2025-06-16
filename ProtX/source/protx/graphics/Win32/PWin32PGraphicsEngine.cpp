//
// Created by BasLocal on 12/06/2025.
//

#include "protx/graphics/PGraphicsEngine.h"

#include <stdexcept>
#include "glad/glad_wgl.h"
#include "protx/core/PLogger.h"

protx::PGraphicsEngine::PGraphicsEngine() {
    WNDCLASSEX wc = {};
    wc.cbSize = sizeof(wc);
    wc.lpszClassName = "ProtXWindow - Dummy";
    wc.lpfnWndProc = DefWindowProc;
    wc.style = CS_OWNDC;

    auto classId = RegisterClassEx(&wc);
    assert(classId); // TODO: make all asserts an exception


    auto dummyWindow = CreateWindowEx(NULL, MAKEINTATOM(classId), "DEV://BC | ProtX",
                                      WS_OVERLAPPEDWINDOW | WS_CAPTION | WS_SYSMENU,
                                      CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,NULL,NULL,NULL,NULL);
    assert(dummyWindow);

    auto dummyDC = GetDC(dummyWindow); //DC = Device Context

    PIXELFORMATDESCRIPTOR pixelformatdescriptor = {};
    pixelformatdescriptor.nSize = sizeof(pixelformatdescriptor);
    pixelformatdescriptor.nVersion = 1;
    pixelformatdescriptor.iPixelType = PFD_TYPE_RGBA;
    pixelformatdescriptor.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pixelformatdescriptor.cColorBits = 32;
    pixelformatdescriptor.cAlphaBits = 8;
    pixelformatdescriptor.cDepthBits = 24;
    pixelformatdescriptor.cStencilBits = 8;
    pixelformatdescriptor.iLayerType = PFD_MAIN_PLANE;

    auto pixelFormat = ChoosePixelFormat(dummyDC, &pixelformatdescriptor);
    SetPixelFormat(dummyDC, pixelFormat, &pixelformatdescriptor);

    auto dummyContext = wglCreateContext(dummyDC); // OPENGL entrypoint
    assert(dummyContext);

    wglMakeCurrent(dummyDC, dummyContext);

    if (!gladLoadWGL(dummyDC)) {
        ProtXLogErrorAndThrow("Failed to initialize OpenGL context (WGL)");
        //throw std::runtime_error("ProtX - Error - Failed to initialize OpenGL context (WGL)");
    }
    if (gladLoadGL()) {
        ProtXLogErrorAndThrow("Failed to initialize OpenGL context (GL)");
        //throw std::runtime_error("ProtX - Error - Failed to initialize OpenGL context (GL)");
    }

    wglMakeCurrent(dummyDC, nullptr);
    wglDeleteContext(dummyContext);
    ReleaseDC(dummyWindow, dummyDC);
    DestroyWindow(dummyWindow);
}

protx::PGraphicsEngine::~PGraphicsEngine() {
}
