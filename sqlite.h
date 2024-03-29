#ifndef SQLITE_H
#define SQLITE_H


#include <vector>
#include <QString>
#include "entity_step1.h"
#include "entity_step2.h"
#include "entity_step3_2.h"
#include "entity_step3_3.h"
#include "entity_step3_4.h"
#include "entity_step4_1.h"
#include "entity_step4_2.h"
#include "entity_step5.h"
#include "entity_step6_1.h"
#include "entity_step6_2.h"
#include "entity_step7_1.h"
#include "entity_step7_2.h"
#include "entity_step7_3.h"
#include "entity_step6_3.h"
#include "entity_step8.h"
#include "entity_step9_2.h"
#include "entity_step9_3.h"
#include "entity_step9_4.h"
#include "entity_step10.h"
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
    bool saveStep4_1Table(QString qualityParameterName);//所有质量参数
    bool saveStep4_2Table(QString chooseQualityParameterName);//选中的质量参数
    bool saveStep5Table(QString chooseQualityParameterName,QString dataType,double  upperBoundValue,double  lowerBoundValue,QString Unit);
    bool saveStep6_1Table(QString row,QString qualityParameterName,double value);
    bool saveStep6_2Table(QString qualityParameterNameRow,QString qualityParameterNameRank,QString valueQualityType,double BValue);
    bool saveStep6_3Table(QString row,QString rank,double  autocorrelationResult);
    bool saveStep7_1Table(QString valueExpectation,QString QualityParameterName,double  valuequalityResult,double Evalue);
    bool saveStep7_2Table(QString qualityParameterNameRow,QString qualityParameterNameRank,QString valueQualityType,double BValue);
    bool saveStep7_3Table(QString valueExpectation,QString QualityParameterName,double  valuequalityResult);
    bool saveStep8Table(QString QualityParameters,double relativeImportanceRating);
    bool saveStep9_2Table(QString valueExpectationRow,QString valueExpectationRank,QString competitiveEvaluation);
    bool saveStep9_3Table(QString valueExpectationRow,QString valueExpectationRank,QString expectedRank);
    bool saveStep9_4Table(QString valueExpectationRow,QString valueExpectationRank,QString criticality);
    bool saveStep10Table(QString QualityParameterName,QString upLow,double outputValue,QString Unit);

    vector<Entity_Step1>  queryStep1Data();
    vector<Entity_Step2>  queryStep2Data();
    vector<Entity_Step3_2>queryStep3_2Data();
    vector<Entity_Step3_3>queryStep3_3Data();
    vector<Entity_Step3_4>queryStep3_4Data();
    vector<Entity_Step4_1>queryStep4_1Data();
    vector<Entity_Step4_2>queryStep4_2Data();
    vector<Entity_Step5>  queryStep5Data();
    vector<Entity_Step6_1>queryStep6_1Data();
    vector<Entity_Step6_2>queryStep6_2Data();
    vector<Entity_Step6_3>queryStep6_3Data();
    vector<Entity_Step7_1>queryStep7_1Data();
    vector<Entity_Step7_2>queryStep7_2Data();
    vector<Entity_Step7_3>queryStep7_3Data();
    vector<Entity_Step8>  queryStep8Data();
    vector<Entity_Step9_2>queryStep9_2Data();
    vector<Entity_Step9_3>queryStep9_3Data();
    vector<Entity_Step9_4>queryStep9_4Data();
    vector<Entity_Step10> queryStep10Data();
    bool deleteStep1Table();
    bool deleteStep1Data();
    bool deleteStep2Table();
    bool deleteStep3_2Data();
    bool deleteStep3_3Data();
    bool deleteStep3_4Data();
    bool deleteStep4_1Data();
    bool deleteStep4_2Data();
    bool deleteStep5Data();
    bool deleteStep6_1Data();
    bool deleteStep6_2Data();
    bool deleteStep6_3Data();
    bool deleteStep7_1Data();
    bool deleteStep7_2Data();
    bool deleteStep7_3Data();
    bool deleteStep8Data();
    bool deleteStep9_2Data();
    bool deleteStep9_3Data();
    bool deleteStep9_4Data();
    bool deleteStep10Data();
};

#endif // SQLITE_H
