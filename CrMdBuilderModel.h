#ifndef CRMDBUILDERMODEL_H_
#define CRMDBUILDERMODEL_H_

#include <filesystem>
#include <QObject>
#include <QString>
#include <string>
#include <vector>

// std::filesystem can make lines very long.
namespace fs = std::filesystem;

class CrMdBuilderModel : public QObject
{
    Q_OBJECT

public:
    explicit CrMdBuilderModel(const char * modelName, QObject *parent = nullptr);
    ~CrMdBuilderModel() = default;

public slots:

signals:

private slots:


private:

};

#endif // CRMDBUILDERMODEL_H_


