#ifndef SIGNALROUTERCONTROLLER_H_
#define SIGNALROUTERCONTROLLER_H_

#include "CrMdBuilderModel.h"
#include "MainDialog.h"
#include <QObject>
#include <QString>

/*
 * The purpose of this class is to control the the Photo Reducer Tool. It
 * creates the model and the different views of the model. Most of the signals
 * and slots of the objects will be connected in this class.
 * 
 * Signals to create new views are handled by this class.
 */
class SignalRouterController: public QObject
{
    Q_OBJECT

public:
    explicit SignalRouterController(const char * controllerName, QObject *parent = nullptr);
    ~SignalRouterController() = default;
    void createModel();
    void createMainDialog();
    void connectControllerAndModelSignalsToSlots();

public slots:

signals:


private slots:


private:

/*
 * Private Variables
 */
    CrMdBuilderModel* model;
    MainDialog* mainDialog;
};

#endif // SIGNALROUTERCONTROLLER_H_


