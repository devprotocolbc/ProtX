//
// Created by BasLocal on 09/06/2025.
//

#ifndef PGAME_H
#define PGAME_H
#include <memory>


namespace protx {
    class PWindow;
    class ProtX {
    public:
        ProtX();

        ~ProtX();

        void run();

        void quit();

    private:
        bool m_isRunning = true;
        std::unique_ptr<PWindow> m_display;
    };
}


#endif //PGAME_H
