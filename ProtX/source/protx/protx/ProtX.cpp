//
// Created by BasLocal on 09/06/2025.
//

#include "protx/protx/ProtX.h"

protx::ProtX::ProtX() {
    m_display = std::unique_ptr<PWindow>(new PWindow());
}

protx::ProtX::~ProtX() {
}

void protx::ProtX::quit() {
    m_isRunning = false;
}
