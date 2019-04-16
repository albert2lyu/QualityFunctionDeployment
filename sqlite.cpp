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

