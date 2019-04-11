#ifndef SQLITE_H
#define SQLITE_H


#include <vector>
#include <QString>
#include "entity_step1.h"
#include "entity_step2.h"
using namespace std;

class Sqlite
{
public:

    Sqlite();
    bool connect();
    bool createStep1Table();
    bool createStep2Table();
    bool createStep2_2Table();

    bool saveStep1Table(QString valueExpectation, QString valueOperator, QString expectations, QString stakeholders);
    bool saveStep2Table(QString valueIndexName,QString relativeImportanceRating);
    bool saveStep2_2Table(QString valueExpectationRow,QString valueExpectationRank,QString relativeImportanceRating);

    vector<Entity_Step1> queryStep1Data();
    vector<Entity_Step2> queryStep2Data();

    bool deleteStep2Table();


};

#endif // SQLITE_H
