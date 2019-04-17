#ifndef SQLITE_H
#define SQLITE_H


#include <vector>
#include <QString>
#include "entity_step1.h"
#include "entity_step2.h"
#include "entity_step3_2.h"
#include "entity_step3_3.h"
#include "entity_step3_4.h"
using namespace std;

class Sqlite
{
public:

    Sqlite();
    bool connect();
    bool createStep1Table();
    bool createStep2Table();
    bool createStep2_2Table();
    bool createStep3_2Table();

    bool saveStep1Table(QString valueExpectation, QString valueOperator, QString expectations, QString stakeholders);
    bool saveStep2Table(QString valueIndexName,QString relativeImportanceRating);
    bool saveStep2TableDouble(QString valueIndexName, double relativeImportanceRating);
    bool saveStep2_2Table(QString valueExpectationRow,QString valueExpectationRank,QString relativeImportanceRating);
    bool saveStep3_2Table(QString valueExpectationRow,QString valueExpectationRank,QString competitiveEvaluation);
    bool saveStep3_3Table(QString valueExpectationRow,QString valueExpectationRank,QString expectedRank);
    bool saveStep3_4Table(QString valueExpectationRow,QString valueExpectationRank,QString criticality);
    bool saveStep4_1Table(QString valueExpectationRow);

    vector<Entity_Step1>  queryStep1Data();
    vector<Entity_Step2>  queryStep2Data();
    vector<Entity_Step3_2>queryStep3_2Data();
    vector<Entity_Step3_3>queryStep3_3Data();
    vector<Entity_Step3_4>queryStep3_4Data();

    bool deleteStep2Table();
    bool deleteStep3_2Data();
    bool deleteStep3_3Data();
    bool deleteStep3_4Data();

};

#endif // SQLITE_H
