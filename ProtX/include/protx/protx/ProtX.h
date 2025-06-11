//
// Created by BasLocal on 09/06/2025.
//

#ifndef PGAME_H
#define PGAME_H
#include <memory>
#include "protx/window/PWindow.h"


namespace protx {
    class PGraphicsEngine;
    class PWindow;
    class ProtX {
    public:
        ProtX();
        ~ProtX();

        virtual void onCreate();

        virtual void onUpdate();

        virtual void onQuit();

        void run();
        void quit();

    private:
        bool m_isRunning = true;
        std::unique_ptr<PGraphicsEngine> m_graphicsEngine;
        std::unique_ptr<PWindow> m_display;
    };
}


#endif //PGAME_H
