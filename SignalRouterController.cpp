#include "SignalRouterController.h"
#include <QString>

SignalRouterController::SignalRouterController(const char* objectName, QObject *parent)
    : QObject{parent}
{
    setObjectName(QString::fromUtf8(objectName));

}

void SignalRouterController::createModel()
{
    model = new CrMdBuilderModel("model", this);
}

void SignalRouterController::createMainDialog()
{
    mainDialog = new MainDialog();
    mainDialog->setObjectName("mainDialog");
}

void SignalRouterController::connectControllerAndModelSignalsToSlots()
{
}



/*
 * Slots
 */


