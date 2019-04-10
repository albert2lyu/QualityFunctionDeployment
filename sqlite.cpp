#include "sqlite.h"
#include <QtSql>
#include <QString>
#include "entity_step1.h"
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
bool Sqlite::saveStep1Table(QString valueExpectation, QString valueOperator, QString expectations, QString stakeholders)
{
    qDebug()<<"saveStep1Table";
    if(valueExpectation != nullptr && valueOperator != nullptr && expectations != nullptr && stakeholders != nullptr)
    {
        /*
            QSqlQuery deleteQuery ;
            if(!deleteQuery.exec("delete from  'Step1'' "))
            {
                qDebug() << "Create createStep1Table Failed!";
            }
        */
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
    qDebug()<<"Sqlite::saveStep2Table";
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

vector<Entity_Step1> Sqlite::queryStep1Data()
{
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

