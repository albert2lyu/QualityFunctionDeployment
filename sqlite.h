#ifndef SQLITE_H
#define SQLITE_H

#include <QString>
using namespace std;

class Sqlite
{
public:
    Sqlite();
    bool connect();
    bool createStep1Table();
    bool saveStep1Table(QString valueExpectation, QString valueOperator, QString expectations, QString stakeholders);
    bool queryStep1Data();

};

#endif // SQLITE_H
