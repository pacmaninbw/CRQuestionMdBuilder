#include "SignalRouterController.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication theApp(argc, argv);

    SignalRouterController routerController("TheController");
    routerController.createModel();
    routerController.connectControllerAndModelSignalsToSlots();
    routerController.createMainDialog();
    routerController.connectMainDialogSignalsAndSlots();
        
    return theApp.exec();
}
