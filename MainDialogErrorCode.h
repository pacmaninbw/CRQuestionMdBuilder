#ifndef MAINDIALOGERORCODE_H_
#define MAINDIALOGERORCODE_H_

#include <QString>

using MainDialogErrorCode = unsigned int;

const MainDialogErrorCode overwriteWarning = 0x0011;

struct MainDialogErrorSignalContents
{
    MainDialogErrorCode errorCode;
    QString errorMessage;
};

#endif // MAINDIALOGERORCODE_H_
