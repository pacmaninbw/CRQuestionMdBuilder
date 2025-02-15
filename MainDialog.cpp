#include "createNamedQTWidget.h"
#include "DirectoryLineEdit.h"
#include "NumericLineEdit.h"
#include "MainDialog.h"
#include <QVariant>
#include <QAbstractButton>
#include <QDialog>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QMessageBox>

MainDialog::MainDialog(QWidget *parent) :
    QDialog(parent)
{
    setObjectName(QString::fromUtf8("mainDialog"));

    setUpDialogUI();

/*
 * QMetaObject::connectSlotsByName() does not connect Dialog Button Box buttons
 * or checkboxes. This makes it necessary to connect the buttons and checkboxes
 * explicitly.
 */
    connectDialogButtons();

    QMetaObject::connectSlotsByName(this);
}

void MainDialog::setUpDialogUI()
{
    QString dialogTitle = "TITLE";
    setWindowTitle(dialogTitle);
}


void  MainDialog::connectDialogButtons()
{
#if 0
    QObject::connect(optionsButtonBox, &QDialogButtonBox::accepted,
        this, &MainDialog::onAccept);
        
    QObject::connect(optionsButtonBox, &QDialogButtonBox::rejected,
        this, qOverload<>(&QDialog::reject));
#endif
}

#if 0
/*
 * Please pardon the repetition of code in the following 2 functions. I am still
 * researching how to pass a signal that needs to be emitted into a function.
 */
void MainDialog::connectPhotoGroupCheckBoxes()
{
    connect(maintainRatioCheckBox, &QCheckBox::toggled, [this]()
        {
            emit optionsMaintainRatioCBChanged(maintainRatioCheckBox->isChecked());
        }
    );
    connect(displayResizedCheckBox, &QCheckBox::toggled, [this]()
        {
            emit optionsDisplayResizedCBChanged(displayResizedCheckBox->isChecked());
        }
    );
}


QFormLayout* MainDialog::createNamedFormLayoutWithPolicy(const char *formName)
{
    QFormLayout* newFormLayout = createNamedQTWidget<QFormLayout>(formName);
    newFormLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);

    return newFormLayout;
}
#endif

void MainDialog::handelModelError(const MainDialogErrorSignalContents &eMessage)
{
    MainDialogErrorCode eCode = eMessage.errorCode;
    modelHasErrors |= eCode;
    widgetHighlightError(eCode, true);
    showErrorDisableOKButton(eMessage.errorMessage);
}

void MainDialog::clearModelError(const MainDialogErrorCode clearedError)
{
    modelHasErrors &= ~clearedError;
    widgetHighlightError(clearedError, false);    
    if (!modelHasErrors)
    {
#if 0
        optionsButtonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
#endif
    }
}

void MainDialog::showErrorDisableOKButton(QString error)
{
    QMessageBox errorMessageBox;
    errorMessageBox.critical(0,"Error:", error);
    errorMessageBox.setFixedSize(500,200);

#if 0
    optionsButtonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
#endif 
}

void MainDialog::widgetHighlightError(const MainDialogErrorCode error, bool highlight)
{
    NumericLineEdit* widgetToChange = nullptr;

    switch (error)
    {
        default: 
            showErrorDisableOKButton("Unknown error code!");
            return;
        case overwriteWarning:
            widgetToChange = MyLineEdit;
            break;
    }

    if (widgetToChange)
    {
        widgetToChange->highlightError(highlight);
    }
}


/*
 * Slots for the widgets.
 */
void MainDialog::onAccept()
{
    if (modelHasErrors)
    {
        QMessageBox::warning(this, "Errors", "Please correct the errors highlighted in yellow before closing.");
    }
    else
    {
        emit validateMainDialog();
    }
}


