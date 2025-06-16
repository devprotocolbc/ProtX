//
// Created by BasLocal on 16/06/2025.
//

#ifndef LOGGER_H
#define LOGGER_H
#include <iostream>
#include <stdexcept>


namespace protx {
    class PLogger final {
    public:
        enum class LogLevel {
            Error = 0,
            Warning,
            Info,
        };

        static void Log(LogLevel level, const char *msg);

        static bool Initialize(LogLevel level);

    private: // prevent instantiation so we have a Singleton
        PLogger(const PLogger &) = delete; //copy constructor method
        PLogger(PLogger &&) = delete; //move constructor method
        PLogger &operator =(const PLogger &) = delete; //copy assignment operator
        PLogger &operator =(PLogger &&) = delete; //move assigment operator

    private:
        static inline bool m_levelSet = false;
        static inline LogLevel m_logLevel = LogLevel::Error;
    };

#define ProtXLogInfo(message) {\
    protx::PLogger::Log((PLogger::LogLevel::Info), message);\
}
#define ProtXLogWarning(message) {\
    protx::PLogger::Log((PLogger::LogLevel::Info), message);\
}
#define ProtXLogError(message) {\
    protx::PLogger::Log((PLogger::LogLevel::Info), message);\
}
#define ProtXLogErrorAndThrow(message){\
    ProtXLogError(message)\
    throw std::runtime_error(message);\
}
}
#endif //LOGGER_H
