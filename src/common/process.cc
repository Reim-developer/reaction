#include "include/process.hpp"
#include "QtCore/qdebug.h"
#include "QtCore/qlogging.h"
#include <QtCore/QProcess>

using namespace Reaction::Common;

void Process::setProcess(const QString &programPath, const QStringList &params) {
    QProcess process;
    process.start(programPath, params);

    QString output = QString::fromUtf8(process.readAllStandardOutput());
    qDebug() << "Output: " << output;
}