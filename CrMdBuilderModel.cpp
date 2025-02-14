#include "CrMdBuilderModel.h"
#include <QDir>

CrMdBuilderModel::CrMdBuilderModel(const char* modelName, QObject *parent)
    : QObject{parent}
{
    setObjectName(QString::fromUtf8(modelName));

    QString startDir = QDir::homePath();
}

/*
 * Slots
 */
