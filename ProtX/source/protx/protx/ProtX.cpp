//
// Created by BasLocal on 09/06/2025.
//

#include "protx/protx/ProtX.h"

#include "protx/core/PLogger.h"
#include "protx/graphics/PGraphicsEngine.h"

protx::ProtX::ProtX() {
    PLogger::Initialize(PLogger::LogLevel::Info);
    m_graphicsEngine = std::make_unique<PGraphicsEngine>();
    m_display = std::make_unique<PWindow>();

    m_display->makeCurrentContext();
}

protx::ProtX::~ProtX() {
}

void protx::ProtX::onCreate() {
    m_graphicsEngine->clear(PVec4(1, 0, 0, 0));
    m_display->present(false);
    ProtXLogInfo("ProtX created")
}

void protx::ProtX::onUpdate() {
    m_graphicsEngine->clear(PVec4(1, 0, 1, 0));

    m_display->present(false);
}

void protx::ProtX::onQuit() {
}

void protx::ProtX::quit() {
    m_isRunning = false;
}
