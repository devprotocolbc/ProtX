//
// Created by BasLocal on 16/06/2025.
//

#include "protx/core/PLogger.h"


void protx::PLogger::Log(LogLevel level, const char *msg) {
    auto logLeveltoString = [](LogLevel level) {
        switch (level) {
            case LogLevel::Info: return "Info";
            case LogLevel::Warning: return "Warning";
            case LogLevel::Error: return "Error";
            default: return "unknown";
        }
    };

    if (!m_levelSet)
        std::clog << "[ProtX " << logLeveltoString(LogLevel::Error) << "]" <<
                " LogLevel not set!  ---- Set to Error By default ----" << std::endl << std::endl;

    if (level > m_logLevel) return;
    std::clog << "[ProtX " << logLeveltoString(level) << "]: " << msg << std::endl;
}

bool protx::PLogger::Initialize(LogLevel level) {
    m_logLevel = level;
    m_levelSet = true;

    // srand(time(0));
    // if (int rando = rand() % 2) {
    // std::clog << "██████╗                      █╗   ██╗  ██╗" << std::endl;
    // std::clog << "██╔══██╗ █████╗  ██████╗    ██║   ╚██╗██╔╝" << std::endl;
    // std::clog << "██████╔╝██╔═══╝ ██╔═══██╗  █████╗  ╚███╔╝" << std::endl;
    // std::clog << "██╔═══╝ ██║     ██║   ██║  ╚██╔═╝  ██╔██╗" << std::endl;
    // std::clog << "██║     ██║     ╚██████╔╝   ██║   ██╔╝ ██╗" << std::endl;
    // std::clog << "╚═╝     ╚═╝      ╚═════╝    ╚═╝   ╚═╝  ╚═╝\n" << std::endl;
    // } else {
    std::clog << "888~-_                     d8   Y88b    / " << std::endl;
    std::clog << "888   \\  888-~\\  e88~-_  _d88__  Y88b  /" << std::endl;
    std::clog << "888    | 888    d888   i  888     Y88b/" << std::endl;
    std::clog << "888   /  888    8888   |  888     /Y88b" << std::endl;
    std::clog << "888_-~   888    Y888   '  888    /  Y88b" << std::endl;
    std::clog << "888      888     \"88_-~   \"88_/ /    Y88b" << std::endl << std::endl;
    // }
    std::clog << "-----------------Dev://BC-----------------" << std::endl << std::endl << std::endl;
    return true;
}
