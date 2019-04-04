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
    qDebug()<<"createStep1Table";
    QSqlQuery query;
    if(!query.exec("CREATE TABLE 'Step1' ( `价值期望名称` varchar ( 255 ), `操作符` varchar ( 1 ), `期望值` double, `利益相关者` varchar(255) )"))
    {
        qDebug() << "Create createStep1Table Failed!";
        return false;
    }
    return true;
}
bool Sqlite::saveStep1Table(QString valueExpectation, QString valueOperator, QString expectations, QString stakeholders)
{
    qDebug()<<"saveStep1Table";
    if(valueExpectation != NULL && valueOperator != NULL && expectations != NULL && stakeholders != NULL)
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
//QString valueExpectation, QString valueOperator, QString expectations, QString stakeholders
vector<Entity_Step1> Sqlite::queryStep1Data()
{
      QSqlQuery query;
      query.exec("SELECT * FROM Step1");
      vector<Entity_Step1>returnList;
      while(query.next())
      {
          Entity_Step1 entity_Step1;
          entity_Step1.valueExpectation = query.value(0).toString();
          entity_Step1.valueOperator = query.value(1).toString();
          entity_Step1.expectations = query.value(2).toString();
          entity_Step1.stakeholders = query.value(3).toString();
          returnList.push_back(entity_Step1);
      }
      return returnList;
}
