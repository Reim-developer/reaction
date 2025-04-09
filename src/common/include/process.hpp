#ifndef PROCESS_HPP
#define PROCESS_HPP
#include <QtCore/QString>
#include <QtCore/QStringList>

namespace Reaction::Common {
    class Process {
        public:
            void setProcess(const QString &programPath, const QStringList &params);
    };
}

#endif // PROCESS_HPP
