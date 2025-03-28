#ifndef CONTEXT_HPP
#define CONTEXT_HPP
#include "QtWidgets/qpushbutton.h"
#include "signal.hpp"

namespace Reaction::Common {
    class Context {
        public:
            void setOpenFileContext(QPushButton *button, Signal *signal);
    };
}


#endif // CONTEXT_HPP