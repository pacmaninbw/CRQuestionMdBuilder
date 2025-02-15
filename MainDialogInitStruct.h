#ifndef MAINDIALOGINITSTRUCT_H_
#define MAINDIALOGINITSTRUCT_H_

#include <string>

enum class FileGenerationType
{
    GenerateTextFile,
    GemerateMdFile
};

struct MainDialogInitStruct
{
    std::string sourceDirectory;
    std::string QuestionFileName;
    FileGenerationType fileType;
};

#endif // MAINDIALOGINITSTRUCT_H_