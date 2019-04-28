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
    bool mlfStep3(QTableWidget *tableWidget);
    bool matStep6(QTableWidget *tableWidget);
    bool matStep7(QTableWidget *tableWidget);
    bool matStep8(QTableWidget *tableWidget);
    bool mlfStep9(QTableWidget *tableWidget);
    bool matStep10(QTableWidget *tableWidget);
};

#endif // MATLABFUNCTION_H
