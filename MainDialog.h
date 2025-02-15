#ifndef MainDialog_H_
#define MainDialog_H_

#include "createNamedQTWidget.h"
#include "DirectoryLineEdit.h"
#include "MainDialogErrorCode.h"
#include "NumericLineEdit.h"
#include <QVariant>
#include <QDialog>
#include <QDialogButtonBox>

class MainDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MainDialog(QWidget* parent = nullptr);
    ~MainDialog() = default;

public slots:

signals:
    void validateMainDialog();
    void MyLineEditChandeByUser(QString my);

private slots:
    void onAccept();
    void on_MyLineEdit_userEditComplete(QString newValue){ emit MyLineEditChandeByUser(newValue); };

private:
    void setUpDialogUI();
    void connectDialogButtons();
    void showErrorDisableOKButton(QString error);
    void widgetHighlightError(const MainDialogErrorCode error, bool highlight);
    void clearModelError(const MainDialogErrorCode clearedError);
    void handelModelError(const MainDialogErrorSignalContents &eMessage);

/*
 * Widget Declarations
 */
    DirectoryLineEdit* sourceDirectoryLineEdit;
    NumericLineEdit* MyLineEdit;

/*
 * Private Variables
 */
    MainDialogErrorCode modelHasErrors = 0;

};

#endif  // MainDialog_H_
