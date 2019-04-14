#ifndef MATLABFUNCTION_H
#define MATLABFUNCTION_H
#include <QFile>
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include <QTableWidget>
#include <QAxObject>
#include "matBasic.h"
class MatlabFunction
{
public:
    MatlabFunction();
    bool matBasi(QTableWidget *tableWidget);
};

#endif // MATLABFUNCTION_H
