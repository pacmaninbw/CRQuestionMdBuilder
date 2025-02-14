#include "SignalRouterController.h"
#include <QString>

SignalRouterController::SignalRouterController(const char* objectName, QObject *parent)
    : QObject{parent}
{
    setObjectName(QString::fromUtf8(objectName));

}

void SignalRouterController::createModel()
{
}

void SignalRouterController::connectControllerAndModelSignalsToSlots()
{
}



/*
 * Slots
 */


