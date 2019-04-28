#include "sqlite.h"
#include <QtSql>
#include <QString>
#include "entity_step1.h"
#include "entity_step3_3.h"
Sqlite::Sqlite()
{

}

bool  Sqlite::connect()
{
    qDebug()<<"Sqlite::connect";
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("QFD.db");
    if(!db.open())
    {
        return false;
    }
    return true;
}
bool Sqlite::createStep1Table()
{
    qDebug()<<"Sqlite::createStep1Table";
    QSqlQuery query;
    if(!query.exec("CREATE TABLE 'Step1' ( `价值期望名称` varchar ( 255 ), `操作符` varchar ( 1 ), `期望值` double, `利益相关者` varchar(255) )"))
    {
        qDebug() << "Create createStep1Table Failed!";
        return false;
    }
    return true;
}
bool Sqlite::createStep2Table()
{
    qDebug()<<"Sqlite::createStep2Table";
    QSqlQuery query;
    if(!query.exec("CREATE TABLE `Step2` ( `价值指标名称` varchar(255), `相对重要评级` double )"))
    {
        qDebug() << "Create createStep1Table Failed!";
        return false;
    }
    return true;
}
bool Sqlite::createStep2_2Table()
{
    qDebug()<<"Sqlite::createStep2_2Table";
    QSqlQuery query;
    if(!query.exec("CREATE TABLE `Step2_2` ( `价值期望名称row` varchar(255), `价值期望名称rank` varchar(255), `各个价值指标的相对重要程度` varchar(255) )"))
    {
        qDebug() << "Create createStep1Table Failed!";
        return false;
    }
    return true;
}
bool Sqlite::createStep3_2Table()
{
    qDebug()<<"Sqlite::createStep3_2Table";
    QSqlQuery query;
    if(!query.exec("CREATE TABLE `Step3_2` ( `row` varchar(255), `rank` varchar(255), `competitiveEvaluation` double )"))
    {
        qDebug() << "Create createStep3_2 Failed!";
        return false;
    }
    return true;
}

bool Sqlite::saveStep1Table(QString valueExpectation, QString valueOperator, QString expectations, QString stakeholders)
{
    qDebug()<<"saveStep1Table";
    if(valueExpectation != nullptr && valueOperator != nullptr && expectations != nullptr && stakeholders != nullptr)
    {
            QSqlQuery query;
            query.prepare("INSERT INTO Step1 (价值期望名称, 操作符 ,期望值 ,利益相关者) VALUES (:valueExpectation, :valueOperator, :expectations, :stakeholders)");
            query.bindValue(":valueExpectation", valueExpectation.trimmed());
            query.bindValue(":valueOperator", valueOperator.trimmed());
            query.bindValue(":expectations", expectations.trimmed());
            query.bindValue(":stakeholders", stakeholders.trimmed());
            if(!query.exec())
            {
                return false;
            }
            query.finish();
            return true;
    }
    else
    {
        return false;
    }
}
bool Sqlite::saveStep2Table(QString valueIndexName, QString relativeImportanceRating)
{
    qDebug()<<"Sqlite::saveStep2TableQString";
    if(valueIndexName != nullptr && relativeImportanceRating != nullptr )
    {
            QSqlQuery query;
            query.prepare("INSERT INTO Step2 (价值指标名称, 相对重要评级) VALUES (:valueIndexName, :relativeImportanceRating)");
            query.bindValue(":valueIndexName", valueIndexName.trimmed());
            query.bindValue(":relativeImportanceRating", relativeImportanceRating.trimmed());
            if(!query.exec())
            {
                return false;
            }
            query.finish();
            return true;
    }
    else
    {
        return false;
    }
}
bool Sqlite::saveStep2TableDouble(QString valueIndexName, double relativeImportanceRating)
{
    qDebug()<<"Sqlite::saveStep2Tabledouble";
    if(valueIndexName != nullptr )
    {
            QSqlQuery query;
            query.prepare("INSERT INTO Step2 (价值指标名称, 相对重要评级) VALUES (:valueIndexName, :relativeImportanceRating)");
            query.bindValue(":valueIndexName", valueIndexName.trimmed());
            query.bindValue(":relativeImportanceRating", relativeImportanceRating);
            if(!query.exec())
            {
                return false;
            }
            query.finish();
            return true;
    }
    else
    {
        return false;
    }
}

bool Sqlite::saveStep2_2Table(QString valueExpectationRow, QString valueExpectationRank, QString relativeImportanceRating)
{
    qDebug()<<"Sqlite::saveStep2_2Table";
    if(valueExpectationRow != nullptr && valueExpectationRank != nullptr && relativeImportanceRating != nullptr)
    {
            QSqlQuery query;
            query.prepare("INSERT INTO Step2_2 (价值期望名称row, 价值期望名称rank,各个价值指标的相对重要程度) VALUES (:valueExpectationRow, :valueExpectationRank,:relativeImportanceRating)");
            query.bindValue(":valueExpectationRow", valueExpectationRow.trimmed());
            query.bindValue(":valueExpectationRank", valueExpectationRank.trimmed());
            query.bindValue(":relativeImportanceRating", relativeImportanceRating.trimmed());
            if(!query.exec())
            {
                return false;
            }
            query.finish();
            return true;
    }
    else
    {
        return false;
    }
}
bool Sqlite::saveStep3_2Table(QString valueExpectationRow, QString valueExpectationRank, QString competitiveEvaluation)
{
    qDebug()<<"Sqlite::saveStep2_2Table";
    if(valueExpectationRow != nullptr && valueExpectationRank != nullptr && competitiveEvaluation != nullptr)
    {
            QSqlQuery query;
            query.prepare("INSERT INTO Step3_2 (row, rank,competitiveEvaluation) VALUES (:valueExpectationRow, :valueExpectationRank,:competitiveEvaluation)");
            query.bindValue(":valueExpectationRow", valueExpectationRow.trimmed());
            query.bindValue(":valueExpectationRank", valueExpectationRank.trimmed());
            query.bindValue(":competitiveEvaluation", competitiveEvaluation.trimmed());
            if(!query.exec())
            {
                return false;
            }
            query.finish();
            return true;
    }
    else
    {
        return false;
    }
}
bool Sqlite::saveStep3_3Table(QString valueExpectationRow, QString valueExpectationRank, QString expectedRank)
{
    qDebug()<<"Sqlite::saveStep3_3Table";
    if(valueExpectationRow != nullptr && valueExpectationRank != nullptr && expectedRank != nullptr)
    {
            QSqlQuery query;
            query.prepare("INSERT INTO Step3_3 (row, rank,expectedRank) VALUES (:valueExpectationRow, :valueExpectationRank,:expectedRank)");
            query.bindValue(":valueExpectationRow", valueExpectationRow.trimmed());
            query.bindValue(":valueExpectationRank", valueExpectationRank.trimmed());
            query.bindValue(":expectedRank", expectedRank.trimmed());
            if(!query.exec())
            {
                return false;
            }
            query.finish();
            return true;
    }
    else
    {
        return false;
    }
}
//CREATE TABLE `Step3_4` ( `Row` varchar(255), `rank` varchar(255), `criticality` double )
bool Sqlite::saveStep3_4Table(QString valueExpectationRow, QString valueExpectationRank, QString criticality)
{
    qDebug()<<"Sqlite::saveStep3_4Table";
    if(valueExpectationRow != nullptr && valueExpectationRank != nullptr && criticality != nullptr)
    {
            QSqlQuery query;
            query.prepare("INSERT INTO Step3_4 (Row, rank,criticality) VALUES (:Row, :rank,:criticality)");
            query.bindValue(":Row", valueExpectationRow.trimmed());
            query.bindValue(":rank", valueExpectationRank.trimmed());
            query.bindValue(":criticality", criticality.trimmed());
            if(!query.exec())
            {
                return false;
            }
            query.finish();
            return true;
    }
    else
    {
        return false;
    }
}
bool Sqlite::saveStep4_1Table(QString qualityParameterName)
{
    //CREATE TABLE `Step4_1` ( `valueIndexName` varchar(255) )
    qDebug()<<"Sqlite::saveStep4_1Table";
    if(qualityParameterName != nullptr)
    {
            QSqlQuery query;
            query.prepare("INSERT INTO Step4_1 (valueIndexName) VALUES (:valueIndexName)");
            query.bindValue(":valueIndexName", qualityParameterName.trimmed());
            if(!query.exec())
            {
                return false;
            }
            query.finish();
            return true;
    }
    else
    {
        return false;
    }
}
bool Sqlite::saveStep4_2Table(QString chooseQualityParameterName)
{
    qDebug()<<"Sqlite::saveStep4_2Table";
    if(chooseQualityParameterName != nullptr)
    {
            QSqlQuery query;
            query.prepare("INSERT INTO Step4_2 (chooseValueIndexName) VALUES (:chooseValueIndexName)");
            query.bindValue(":chooseValueIndexName", chooseQualityParameterName.trimmed());
            if(!query.exec())
            {
                return false;
            }
            query.finish();
            return true;
    }
    else
    {
        return false;
    }
}
bool Sqlite::saveStep5Table(QString qualityParameterName, QString dataType, double upperBoundValue, double lowerBoundValue)
{

    qDebug()<<"Sqlite::saveStep5Table";
    if(qualityParameterName != nullptr && dataType != nullptr && upperBoundValue != 0 && lowerBoundValue != 0 )
    {
            QSqlQuery query;
            query.prepare("INSERT INTO Step5_1 (qualityParameterName,dataType,upperBoundValue,lowerBoundValue) VALUES (:qualityParameterName,:dataType,:upperBoundValue,:lowerBoundValue)");
            query.bindValue(":qualityParameterName", qualityParameterName.trimmed());
            query.bindValue(":dataType", dataType.trimmed());
            query.bindValue(":upperBoundValue", upperBoundValue);
            query.bindValue(":lowerBoundValue", lowerBoundValue);
            if(!query.exec())
            {
                return false;
            }
            query.finish();
            return true;
    }
    else
    {
        return false;
    }
}
bool Sqlite::saveStep6_1Table(QString row, QString qualityParameterName, double value)
{
    qDebug()<<"Sqlite::saveStep6_1Table";
    if(row != nullptr && qualityParameterName != nullptr && value != 0)
    {
            QSqlQuery query;
            query.prepare("INSERT INTO Step6_1 (row,qualityParameterName,value) VALUES (:row,:qualityParameterName,:value)");
            query.bindValue(":row", row.trimmed());
            query.bindValue(":qualityParameterName", qualityParameterName.trimmed());
            query.bindValue(":value", value);
            if(!query.exec())
            {
                return false;
            }
            query.finish();
            return true;
    }
    else
    {
        return false;
    }
}
bool Sqlite::saveStep7_1Table(QString valueExpectation, QString QualityParameterName, double valuequalityResult,double Evalue)
{

    qDebug()<<"Sqlite::saveStep7_1Table";
    if(valueExpectation != nullptr && QualityParameterName != nullptr )
    {
            QSqlQuery query;
            query.prepare("INSERT INTO Step7_1 (valueExpectation,QualityParameterName,valuequalityResult,Evalue) VALUES (:valueExpectation,:QualityParameterName,:valuequalityResult,:Evalue)");
            query.bindValue(":valueExpectation", valueExpectation.trimmed());
            query.bindValue(":QualityParameterName", QualityParameterName.trimmed());
            query.bindValue(":valuequalityResult", valuequalityResult);
            query.bindValue(":Evalue", Evalue);
            if(!query.exec())
            {
                return false;
            }
            query.finish();
            return true;
    }
    else
    {
        return false;
    }
}
bool Sqlite::saveStep6_2Table(QString qualityParameterNameRow, QString qualityParameterNameRank, QString valueQualityType, double BValue)
{
    qDebug()<<"Sqlite::saveStep6_2Table";
    if(qualityParameterNameRow != nullptr && qualityParameterNameRank != nullptr
            && valueQualityType != nullptr)
    {
            QSqlQuery query;
            query.prepare("INSERT INTO Step6_2 (qualityParameterNameRow,qualityParameterNameRank,valueQualityType,BValue) VALUES (:qualityParameterNameRow,:qualityParameterNameRank,:valueQualityType,:BValue)");
            query.bindValue(":qualityParameterNameRow", qualityParameterNameRow.trimmed());
            query.bindValue(":qualityParameterNameRank", qualityParameterNameRank.trimmed());
            query.bindValue(":valueQualityType", valueQualityType.trimmed());
            query.bindValue(":BValue", BValue);
            if(!query.exec())
            {
                return false;
            }
            query.finish();
            return true;
    }
    else
    {
        return false;
    }
}



bool Sqlite::saveStep6_3Table(QString row, QString rank, double autocorrelationResult)
{
    qDebug()<<"Sqlite::saveStep6_3Table";
    //CREATE TABLE `Step6_3` ( `row` varchar(255), `rank` varchar(255), `autocorrelationResult` double )
    if(row != nullptr && rank != nullptr  )
    {
            QSqlQuery query;
            query.prepare("INSERT INTO Step6_3 (row,rank,autocorrelationResult) VALUES (:row,:rank,:autocorrelationResult)");
            query.bindValue(":row", row.trimmed());
            query.bindValue(":rank", rank.trimmed());
            query.bindValue(":autocorrelationResult", autocorrelationResult);
            if(!query.exec())
            {
                return false;
            }
            query.finish();
            return true;
    }
    else
    {
        return false;
    }
}
bool Sqlite::saveStep7_3Table(QString valueExpectation, QString QualityParameterName, double valuequalityResult)
{
    qDebug()<<"Sqlite::saveStep7_3Table";
    //CREATE TABLE `Step7_3` ( `valueExpectation` varchar(255), `QualityParameterName` varchar(255), `valuequalityResult` double )
    if(valueExpectation != nullptr && QualityParameterName != nullptr  )
    {
            QSqlQuery query;
            query.prepare("INSERT INTO Step7_3 (valueExpectation,QualityParameterName,valuequalityResult) VALUES (:valueExpectation,:QualityParameterName,:valuequalityResult)");
            query.bindValue(":valueExpectation", valueExpectation.trimmed());
            query.bindValue(":QualityParameterName", QualityParameterName.trimmed());
            query.bindValue(":valuequalityResult", valuequalityResult);
            if(!query.exec())
            {
                return false;
            }
            query.finish();
            return true;
    }
    else
    {
        return false;
    }
}
bool Sqlite::saveStep7_2Table(QString qualityParameterNameRow, QString qualityParameterNameRank, QString valueQualityType, double BValue)
{
    qDebug()<<"Sqlite::saveStep7_2Table";
    if(qualityParameterNameRow != nullptr && qualityParameterNameRank != nullptr && valueQualityType != nullptr )
    {
            QSqlQuery query;
            query.prepare("INSERT INTO Step7_2 (qualityParameterNameRow,qualityParameterNameRank,valueQualityType,BValue) VALUES (:qualityParameterNameRow,:qualityParameterNameRank,:valueQualityType,:BValue)");
            query.bindValue(":qualityParameterNameRow", qualityParameterNameRow.trimmed());
            query.bindValue(":qualityParameterNameRank", qualityParameterNameRank.trimmed());
            query.bindValue(":valueQualityType", valueQualityType.trimmed());
            query.bindValue(":BValue", BValue);
            if(!query.exec())
            {
                return false;
            }
            query.finish();
            return true;
    }
    else
    {
        return false;
    }
}
bool Sqlite::saveStep8Table(QString QualityParameters,double relativeImportanceRating)
{
    qDebug()<<"Sqlite::saveStep8Table";
    //CREATE TABLE `Step8` ( `QualityParameterName` varchar(255),`upLow` varchar(255) `outputValue` double )
    if(QualityParameters != nullptr  )
    {//&& outputValue != 0
            QSqlQuery query;
            query.prepare("INSERT INTO Step8 (QualityParameters,relativeImportanceRating) VALUES (:QualityParameters,:relativeImportanceRating)");
            query.bindValue(":QualityParameters", QualityParameters.trimmed());
            query.bindValue(":relativeImportanceRating", relativeImportanceRating);

            if(!query.exec())
            {
                return false;
            }
            query.finish();
            return true;
    }
    else
    {
        return false;
    }
}
bool Sqlite::saveStep9_2Table(QString valueExpectationRow, QString valueExpectationRank, QString competitiveEvaluation)
{
    qDebug()<<"Sqlite::saveStep9_2Table";
    if(valueExpectationRow != nullptr && valueExpectationRank != nullptr && competitiveEvaluation != nullptr)
    {
            QSqlQuery query;
            query.prepare("INSERT INTO Step9_2 (valueExpectationRow, valueExpectationRank,competitiveEvaluation) VALUES (:valueExpectationRow, :valueExpectationRank,:competitiveEvaluation)");
            query.bindValue(":valueExpectationRow", valueExpectationRow.trimmed());
            query.bindValue(":valueExpectationRank", valueExpectationRank.trimmed());
            query.bindValue(":competitiveEvaluation", competitiveEvaluation.trimmed());
            if(!query.exec())
            {
                return false;
            }
            query.finish();
            return true;
    }
    else
    {
        return false;
    }
}
bool Sqlite::saveStep9_3Table(QString valueExpectationRow, QString valueExpectationRank, QString expectedRank)
{
    qDebug()<<"Sqlite::saveStep9_3Table";
    if(valueExpectationRow != nullptr && valueExpectationRank != nullptr && expectedRank != nullptr)
    {
            QSqlQuery query;
            query.prepare("INSERT INTO Step9_3 (valueExpectationRow, valueExpectationRank,expectedRank) VALUES (:valueExpectationRow, :valueExpectationRank,:expectedRank)");
            query.bindValue(":valueExpectationRow", valueExpectationRow.trimmed());
            query.bindValue(":valueExpectationRank", valueExpectationRank.trimmed());
            query.bindValue(":expectedRank", expectedRank.trimmed());
            if(!query.exec())
            {
                return false;
            }
            query.finish();
            return true;
    }
    else
    {
        return false;
    }
}
//CREATE TABLE `Step9_4` ( `Row` varchar(255), `rank` varchar(255), `criticality` double )
bool Sqlite::saveStep9_4Table(QString valueExpectationRow, QString valueExpectationRank, QString criticality)
{
    qDebug()<<"Sqlite::saveStep9_4Table";
    if(valueExpectationRow != nullptr && valueExpectationRank != nullptr && criticality != nullptr)
    {
            QSqlQuery query;
            query.prepare("INSERT INTO Step9_4 (valueExpectationRow, valueExpectationRank,criticality) VALUES (:valueExpectationRow, :valueExpectationRank,:criticality)");
            query.bindValue(":valueExpectationRow", valueExpectationRow.trimmed());
            query.bindValue(":valueExpectationRank", valueExpectationRank.trimmed());
            query.bindValue(":criticality", criticality.trimmed());
            if(!query.exec())
            {
                return false;
            }
            query.finish();
            return true;
    }
    else
    {
        return false;
    }
}
bool Sqlite::saveStep10Table(QString QualityParameterName,QString upLow, double outputValue)
{
    qDebug()<<"Sqlite::saveStep10Table";
    //CREATE TABLE `Step10` ( `QualityParameterName` varchar(255),`upLow` varchar(255) `outputValue` double )
    if(QualityParameterName != nullptr && upLow != nullptr )
    {//&& outputValue != 0
            QSqlQuery query;
            query.prepare("INSERT INTO Step10 (QualityParameterName,upLow,outputValue) VALUES (:QualityParameterName,:upLow,:outputValue)");
            query.bindValue(":QualityParameterName", QualityParameterName.trimmed());
            query.bindValue(":upLow", upLow.trimmed());
            query.bindValue(":outputValue", outputValue);
            if(!query.exec())
            {
                return false;
            }
            query.finish();
            return true;
    }
    else
    {
        return false;
    }
}

vector<Entity_Step1> Sqlite::queryStep1Data()
{
      qDebug()<<"Sqlite::queryStep1Data";
      QSqlQuery query;
      query.exec("SELECT * FROM Step1");
      vector<Entity_Step1>returnList;
      while(query.next())
      {
          Entity_Step1 entity_Step1;
          entity_Step1.valueIndexName = query.value(0).toString();
          entity_Step1.valueOperator = query.value(1).toString();
          entity_Step1.expectations = query.value(2).toString();
          entity_Step1.stakeholders = query.value(3).toString();
          returnList.push_back(entity_Step1);
      }
      return returnList;
}

vector<Entity_Step2> Sqlite::queryStep2Data()
{
    qDebug()<<"Sqlite::queryStep2Data";
    QSqlQuery query;
    query.exec("SELECT * FROM Step2");
    vector<Entity_Step2>returnList;
    while(query.next())
    {
        Entity_Step2 entity_Step2;
        entity_Step2.valueExpectation = query.value(0).toString();
        entity_Step2.relativeImportanceRating = query.value(1).toString();
        returnList.push_back(entity_Step2);
    }
    return returnList;
}
vector<Entity_Step3_2> Sqlite::queryStep3_2Data()
{
    qDebug()<<"Sqlite::queryStep3_2Data";
    QSqlQuery query;
    query.exec("SELECT * FROM Step3_2");
    vector<Entity_Step3_2>returnList;
    while(query.next())
    {
        Entity_Step3_2 entity_Step3_2;
        entity_Step3_2.valueExpectationRow = query.value(0).toString();
        entity_Step3_2.valueExpectationRank = query.value(1).toString();
        entity_Step3_2.competitiveEvaluation = query.value(2).toString();
        returnList.push_back(entity_Step3_2);
    }
    return returnList;
}

vector<Entity_Step3_3> Sqlite::queryStep3_3Data()
{
    qDebug()<<"Sqlite::queryStep3_3Data";
    QSqlQuery query;
    query.exec("SELECT * FROM Step3_3");
    vector<Entity_Step3_3>returnList;
    while(query.next())
    {
        Entity_Step3_3 entity_Step3_3;
        entity_Step3_3.valueExpectationRow = query.value(0).toString();
        entity_Step3_3.valueExpectationRank = query.value(1).toString();
        entity_Step3_3.expectedRank = query.value(2).toString();
        returnList.push_back(entity_Step3_3);
    }
    return returnList;
}
vector<Entity_Step3_4> Sqlite::queryStep3_4Data()
{
    qDebug()<<"Sqlite::queryStep3_4Data";
    QSqlQuery query;
    query.exec("SELECT * FROM Step3_4");
    vector<Entity_Step3_4>returnList;
    while(query.next())
    {
        Entity_Step3_4 entity_Step3_4;
        entity_Step3_4.valueExpectationRow = query.value(0).toString();
        entity_Step3_4.valueExpectationRank = query.value(1).toString();
        entity_Step3_4.criticality = query.value(2).toString();
        returnList.push_back(entity_Step3_4);
    }
    return returnList;
}
vector<Entity_Step4_1> Sqlite::queryStep4_1Data()
{
    qDebug()<<"Sqlite::queryStep4_1Data";
    QSqlQuery query;
    query.exec("SELECT * FROM Step4_1");
    vector<Entity_Step4_1>returnList;
    while(query.next())
    {
        Entity_Step4_1 Entity_Step4_1;
        Entity_Step4_1.QualityParameterName = query.value(0).toString();
        returnList.push_back(Entity_Step4_1);
    }
    return returnList;
}
vector<Entity_Step4_2> Sqlite::queryStep4_2Data()
{
    qDebug()<<"Sqlite::queryStep4_2Data";
    QSqlQuery query;
    query.exec("SELECT * FROM Step4_2");
    vector<Entity_Step4_2>returnList;
    while(query.next())
    {
        Entity_Step4_2 entity_Step4_2;
        entity_Step4_2.chooseQualityParameterName = query.value(0).toString();
        returnList.push_back(entity_Step4_2);
    }
    return returnList;
}
vector<Entity_Step5> Sqlite::queryStep5Data()
{
    qDebug()<<"Sqlite::queryStep5Data";
    QSqlQuery query;
    query.exec("SELECT * FROM Step5_1");
    vector<Entity_Step5>returnList;
    while(query.next())
    {
        Entity_Step5 entity_Step5;
        entity_Step5.qualityParameterName = query.value(0).toString();
        entity_Step5.dataType = query.value(1).toString();
        entity_Step5.upperBoundValue = query.value(2).toString().toDouble();
        entity_Step5.lowerBoundValue = query.value(3).toString().toDouble();
        returnList.push_back(entity_Step5);
    }
    return returnList;
}
vector<Entity_Step6_1> Sqlite::queryStep6_1Data()
{
    //CREATE TABLE `Step6_1` ( `row` varchar(255), `qualityParameterName` varchar(255), `value` double )
    qDebug()<<"Sqlite::queryStep6_1Data";
    QSqlQuery query;
    query.exec("SELECT * FROM Step6_1");
    vector<Entity_Step6_1>returnList;
    while(query.next())
    {
        Entity_Step6_1 entity_Step6_1;
        entity_Step6_1.row = query.value(0).toString();
        entity_Step6_1.qualityParameterName = query.value(1).toString();
        entity_Step6_1.value = query.value(2).toString().toDouble();
        returnList.push_back(entity_Step6_1);
    }
    return returnList;
}
vector<Entity_Step6_2> Sqlite::queryStep6_2Data()
{
    qDebug()<<"Sqlite::queryStep6_1Data";
    QSqlQuery query;
    query.exec("SELECT * FROM Step6_2");
    vector<Entity_Step6_2>returnList;
    while(query.next())
    {
        Entity_Step6_2 entity_Step6_2;
        entity_Step6_2.qualityParameterNameRow = query.value(0).toString();
        entity_Step6_2.qualityParameterNameRank = query.value(1).toString();
        entity_Step6_2.valueQualityType = query.value(2).toString();
        entity_Step6_2.BValue = query.value(2).toString().toDouble();
        returnList.push_back(entity_Step6_2);
    }
    return returnList;
}
vector<Entity_Step6_3> Sqlite::queryStep6_3Data()
{
    //CREATE TABLE `Step6_3` ( `row` varchar(255), `qualityParameterName` varchar(255), `value` double )
    qDebug()<<"Sqlite::queryStep6_3Data";
    QSqlQuery query;
    query.exec("SELECT * FROM Step6_3");
    vector<Entity_Step6_3>returnList;
    while(query.next())
    {
        Entity_Step6_3 entity_Step6_3;
        entity_Step6_3.row = query.value(0).toString();
        entity_Step6_3.rank = query.value(1).toString();
        entity_Step6_3.autocorrelationResult = query.value(2).toString().toDouble();
        returnList.push_back(entity_Step6_3);
    }
    return returnList;
}
vector<Entity_Step7_1> Sqlite::queryStep7_1Data()
{
    //CREATE TABLE `Ste7_1` ( `row` varchar(255), `column` varchar(255), `value` double )
    qDebug()<<"Sqlite::queryStep7_1Data";
    QSqlQuery query;
    query.exec("SELECT * FROM Step7_1");
    vector<Entity_Step7_1>returnList;
    while(query.next())
    {
        Entity_Step7_1 entity_Step7_1;
        entity_Step7_1.QualityParameterName = query.value(0).toString();
        entity_Step7_1.valueExpectation  = query.value(1).toString();
        entity_Step7_1.valuequalityResult = query.value(2).toString().toDouble();
        entity_Step7_1.Evalue = query.value(3).toString().toDouble();
        returnList.push_back(entity_Step7_1);
    }
    return returnList;
}
vector<Entity_Step7_2> Sqlite::queryStep7_2Data()
{
    qDebug()<<"Sqlite::queryStep7_2Data";
    QSqlQuery query;
    query.exec("SELECT * FROM Step7_2");
    vector<Entity_Step7_2>returnList;
    while(query.next())
    {
        Entity_Step7_2 entity_Step7_2;
        entity_Step7_2.qualityParameterNameRow = query.value(0).toString();
        entity_Step7_2.qualityParameterNameRank = query.value(1).toString();
        entity_Step7_2.valueQualityType = query.value(2).toString();
        entity_Step7_2.BValue = query.value(3).toString().toDouble();
        returnList.push_back(entity_Step7_2);
    }
    return returnList;
}

vector<Entity_Step7_3> Sqlite::queryStep7_3Data()
{
    qDebug()<<"Sqlite::queryStep7_3Data";
    QSqlQuery query;
    query.exec("SELECT * FROM Step7_3");
    vector<Entity_Step7_3>returnList;
    while(query.next())
    {
        Entity_Step7_3 entity_Step7_3;
        entity_Step7_3.valueExpectation = query.value(0).toString();
        entity_Step7_3.QualityParameterName  = query.value(1).toString();
        entity_Step7_3.valuequalityResult = query.value(2).toDouble();
        returnList.push_back(entity_Step7_3);
    }
    return returnList;

}
vector<Entity_Step8> Sqlite::queryStep8Data()
{
    //CREATE TABLE `Ste8` ( `row` varchar(255), `column` varchar(255), `value` double )
    qDebug()<<"Sqlite::queryStep8Data";
    QSqlQuery query;
    query.exec("SELECT * FROM Step8");
    vector<Entity_Step8>returnList;
    while(query.next())
    {
        Entity_Step8 entity_Step8;
        entity_Step8.QualityParameters = query.value(0).toString();
        entity_Step8.relativeImportanceRating  = query.value(1).toDouble();
        //QString QualityParameters;//价值指标名称
       // QString relativeImportanceRating;//相对重要评级
        returnList.push_back(entity_Step8);
    }
    return returnList;
}
vector<Entity_Step9_2> Sqlite::queryStep9_2Data()
{
    qDebug()<<"Sqlite::queryStep9_2Data";
    QSqlQuery query;
    query.exec("SELECT * FROM Step9_2");
    vector<Entity_Step9_2>returnList;
    while(query.next())
    {
        Entity_Step9_2 entity_Step9_2;
        entity_Step9_2.valueExpectationRow = query.value(0).toString();
        entity_Step9_2.valueExpectationRank = query.value(1).toString();
        entity_Step9_2.competitiveEvaluation = query.value(2).toString();
        returnList.push_back(entity_Step9_2);
    }
    return returnList;
}

vector<Entity_Step9_3> Sqlite::queryStep9_3Data()
{
    qDebug()<<"Sqlite::queryStep9_3Data";
    QSqlQuery query;
    query.exec("SELECT * FROM Step9_3");
    vector<Entity_Step9_3>returnList;
    while(query.next())
    {
        Entity_Step9_3 entity_Step9_3;
        entity_Step9_3.valueExpectationRow = query.value(0).toString();
        entity_Step9_3.valueExpectationRank = query.value(1).toString();
        entity_Step9_3.expectedRank = query.value(2).toString();
        returnList.push_back(entity_Step9_3);
    }
    return returnList;
}
vector<Entity_Step9_4> Sqlite::queryStep9_4Data()
{
    qDebug()<<"Sqlite::queryStep9_4Data";
    QSqlQuery query;
    query.exec("SELECT * FROM Step9_4");
    vector<Entity_Step9_4>returnList;
    while(query.next())
    {
        Entity_Step9_4 entity_Step9_4;
        entity_Step9_4.valueExpectationRow = query.value(0).toString();
        entity_Step9_4.valueExpectationRank = query.value(1).toString();
        entity_Step9_4.criticality = query.value(2).toString();
        returnList.push_back(entity_Step9_4);
    }
    return returnList;
}
vector<Entity_Step10> Sqlite::queryStep10Data()
{
    //CREATE TABLE `Ste7_1` ( `row` varchar(255), `column` varchar(255), `value` double )
    qDebug()<<"Sqlite::queryStep10Data";
    QSqlQuery query;
    query.exec("SELECT * FROM Step10");
    vector<Entity_Step10>returnList;
    while(query.next())
    {
        Entity_Step10 entity_Step10;
        entity_Step10.QualityParameterName = query.value(0).toString();
        entity_Step10.upLow  = query.value(1).toString();
        entity_Step10.outputValue = query.value(2).toDouble();
        returnList.push_back(entity_Step10);
    }
    return returnList;
}
bool Sqlite::deleteStep1Table()
{
    qDebug()<<"Sqlite::deleteStep1Table";
    QSqlQuery query;
    query.exec("DELETE FROM Step1");
    if(!query.exec())
    {
        return false;
    }
    query.finish();
    return true;
}
bool Sqlite::deleteStep1Data()
{
    qDebug()<<"Sqlite::deleteStep1Data";
    QSqlQuery query;
    query.exec("DELETE FROM Step1");
    if(!query.exec())
    {
        return false;
    }
    query.finish();
    return true;
}
bool Sqlite::deleteStep2Table()
{
    qDebug()<<"Sqlite::deleteStep2Table";
    QSqlQuery query;
    query.exec("DELETE FROM Step2");
    if(!query.exec())
    {
        return false;
    }
    query.finish();
    return true;
}
bool Sqlite::deleteStep3_2Data()
{
    qDebug()<<"Sqlite::deleteStep3_2Data";
    QSqlQuery query;
    query.exec("DELETE FROM Step3_2");
    if(!query.exec())
    {
        return false;
    }
    query.finish();
    return true;
}
bool Sqlite::deleteStep3_3Data()
{
    qDebug()<<"Sqlite::deleteStep3_3Data";
    QSqlQuery query;
    query.exec("DELETE FROM Step3_3");
    if(!query.exec())
    {
        return false;
    }
    query.finish();
    return true;
}
bool Sqlite::deleteStep3_4Data()
{
    qDebug()<<"Sqlite::deleteStep3_4Data";
    QSqlQuery query;
    query.exec("DELETE FROM Step3_4");
    if(!query.exec())
    {
        return false;
    }
    query.finish();
    return true;
}
bool Sqlite::deleteStep4_1Data()
{
    qDebug()<<"Sqlite::deleteStep4_1Data";
    QSqlQuery query;
    query.exec("DELETE FROM Step4_1");
    if(!query.exec())
    {
        return false;
    }
    query.finish();
    return true;
}
bool Sqlite::deleteStep4_2Data()
{
    qDebug()<<"Sqlite::deleteStep4_2Data";
    QSqlQuery query;
    query.exec("DELETE FROM Step4_2");
    if(!query.exec())
    {
        return false;
    }
    query.finish();
    return true;
}
bool Sqlite::deleteStep5Data()
{
    qDebug()<<"Sqlite::deleteStep5Data";
    QSqlQuery query;
    query.exec("DELETE FROM Step5_1");
    if(!query.exec())
    {
        return false;
    }
    query.finish();
    return true;
}
bool Sqlite::deleteStep6_1Data()
{
    qDebug()<<"Sqlite::deleteStep6_1Data";
    QSqlQuery query;
    query.exec("DELETE FROM Step6_1");
    if(!query.exec())
    {
        return false;
    }
    query.finish();
    return true;
}
bool Sqlite::deleteStep6_2Data()
{
    qDebug()<<"Sqlite::deleteStep6_2Data";
    QSqlQuery query;
    query.exec("DELETE FROM Step6_2");
    if(!query.exec())
    {
        return false;
    }
    query.finish();
    return true;
}
bool Sqlite::deleteStep6_3Data()
{
    qDebug()<<"Sqlite::deleteStep6_3Data";
    QSqlQuery query;
    query.exec("DELETE FROM Step6_3");
    if(!query.exec())
    {
        return false;
    }
    query.finish();
    return true;
}
bool Sqlite::deleteStep7_1Data()
{
    qDebug()<<"Sqlite::deleteStep7_1Data";
    QSqlQuery query;
    query.exec("DELETE FROM Step7_1");
    if(!query.exec())
    {
        return false;
    }
    query.finish();
    return true;
}
bool Sqlite::deleteStep7_2Data()
{
    qDebug()<<"Sqlite::deleteStep7_2Data";
    QSqlQuery query;
    query.exec("DELETE FROM Step7_2");
    if(!query.exec())
    {
        return false;
    }
    query.finish();
    return true;
}
bool Sqlite::deleteStep7_3Data()
{
    qDebug()<<"Sqlite::deleteStep7_3Data";
    QSqlQuery query;
    query.exec("DELETE FROM Step7_3");
    if(!query.exec())
    {
        return false;
    }
    query.finish();
    return true;
}
bool Sqlite::deleteStep8Data()
{
    qDebug()<<"Sqlite::deleteStep8Table";
    QSqlQuery query;
    query.exec("DELETE FROM Step8");
    if(!query.exec())
    {
        return false;
    }
    query.finish();
    return true;
}
bool Sqlite::deleteStep9_2Data()
{
    qDebug()<<"Sqlite::deleteStep9_2Data";
    QSqlQuery query;
    query.exec("DELETE FROM Step9_2");
    if(!query.exec())
    {
        return false;
    }
    query.finish();
    return true;
}
bool Sqlite::deleteStep9_3Data()
{
    qDebug()<<"Sqlite::deleteStep9_3Data";
    QSqlQuery query;
    query.exec("DELETE FROM Step9_3");
    if(!query.exec())
    {
        return false;
    }
    query.finish();
    return true;
}
bool Sqlite::deleteStep9_4Data()
{
    qDebug()<<"Sqlite::deleteStep9_4Data";
    QSqlQuery query;
    query.exec("DELETE FROM Step9_4");
    if(!query.exec())
    {
        return false;
    }
    query.finish();
    return true;
}
bool Sqlite::deleteStep10Data()
{
    qDebug()<<"Sqlite::deleteStep10Data";
    QSqlQuery query;
    query.exec("DELETE FROM Step10");
    if(!query.exec())
    {
        return false;
    }
    query.finish();
    return true;
}
