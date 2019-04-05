#ifndef SQLITE_H
#define SQLITE_H


#include <vector>
#include <QString>
#include "entity_step1.h"
using namespace std;

class Sqlite
{
public:

    Sqlite();
    bool connect();
    bool createStep1Table();
    bool saveStep1Table(QString valueExpectation, QString valueOperator, QString expectations, QString stakeholders);
    vector <Entity_Step1> queryStep1Data();

};

#endif // SQLITE_H
