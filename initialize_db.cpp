#include "initialize_db.h"
#include <QDebug>
#include <QtSql>
#include <QFileDialog>
#include <QAxObject>
#include "sqlite.h"
#include "entity_step1.h"
Initialize_DB::Initialize_DB()
{

}
bool Initialize_DB::Initialize_QFD(QString dbName)
{
    qDebug()<<"Initialize_DB::Initialize_QFD";
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("xxxxx.db");
    db.open();
    if(!db.open())
    {
        return false;
    }
    QSqlQuery query;
    if(!query.exec("CREATE TABLE 'Step1' ( `价值期望名称` varchar ( 255 ), `操作符` varchar ( 1 ), `期望值` double, `利益相关者` varchar(255) )"))
    {
        qDebug() << "Create createStep1Table Failed!";
    }
    QSqlQuery query1;
    if(!query1.exec("CREATE TABLE 'Step10' ( `QualityParameterName` TEXT, `upLow` TEXT, `outputValue` REAL )"))
    {
        qDebug() << "Create createStep1Table Failed!";
    }
    QSqlQuery query2;
    if(!query2.exec("CREATE TABLE `Step2` ( `价值指标名称` varchar(255), `相对重要评级` double )"))
    {
        qDebug() << "Create createStep1Table Failed!";
    }
    QSqlQuery query3;
    if(!query3.exec("CREATE TABLE `Step2_2` ( `价值期望名称row` varchar(255), `价值期望名称rank` varchar(255), `各个价值指标的相对重要程度` varchar(255) )"))
    {
        qDebug() << "Create createStep1Table Failed!";
    }
    QSqlQuery query4;
    if(!query4.exec("CREATE TABLE `Step3_2` ( `row` varchar(255), `rank` varchar(255), `competitiveEvaluation` double )"))
    {
        qDebug() << "Create createStep1Table Failed!";
    }
    QSqlQuery query5;
    if(!query5.exec("CREATE TABLE `Step3_3` ( `row` varchar(255), `rank` varchar(255), `expectedRank` double )"))
    {
        qDebug() << "Create createStep1Table Failed!";
    }
    QSqlQuery query6;
    if(!query6.exec("CREATE TABLE `Step3_4` ( `Row` varchar(255), `rank` varchar(255), `criticality` double )"))
    {
        qDebug() << "Create createStep1Table Failed!";
    }
    QSqlQuery query7;
    if(!query7.exec("CREATE TABLE `Step4_1` ( `valueIndexName` varchar(255) )"))
    {
        qDebug() << "Create createStep1Table Failed!";
    }
    QSqlQuery query8;
    if(!query8.exec("CREATE TABLE `Step4_2` ( `chooseValueIndexName` varchar(255) )"))
    {
        qDebug() << "Create createStep1Table Failed!";
    }
    QSqlQuery query9;
    if(!query9.exec("CREATE TABLE 'Step5_1' ( `qualityParameterName` varchar ( 255 ), `dataType` varchar ( 255 ), `upperBoundValue` double, `lowerBoundValue` double )"))
    {
        qDebug() << "Create createStep1Table Failed!";
    }
    QSqlQuery query10;
    if(!query10.exec("CREATE TABLE `Step6_1` ( `row` varchar(255), `qualityParameterName` varchar(255), `value` double )"))
    {
        qDebug() << "Create createStep1Table Failed!";
    }
    QSqlQuery query11;
    if(!query11.exec("CREATE TABLE `Step6_2` ( `qualityParameterNameRow` varchar(255), `qualityParameterNameRank` varchar(255), `valueQualityType` varchar(255), `BValue` double )"))
    {
        qDebug() << "Create createStep1Table Failed!";
    }
    QSqlQuery query12;
    if(!query12.exec("CREATE TABLE `Step6_3` ( `row` varchar(255), `rank` varchar(255), `autocorrelationResult` double )"))
    {
        qDebug() << "Create createStep1Table Failed!";
    }
    QSqlQuery query13;
    if(!query13.exec("CREATE TABLE `Step7_1` ( `valueExpectation` TEXT, `QualityParameterName` TEXT, `valuequalityResult` REAL, `Evalue` REAL )"))
    {
        qDebug() << "Create createStep1Table Failed!";
    }
    QSqlQuery query14;
    if(!query14.exec("CREATE TABLE 'Step7_2' ( `qualityParameterNameRow` TEXT, `qualityParameterNameRank` TEXT, `valueQualityType` TEXT, `BValue` REAL )"))
    {
        qDebug() << "Create createStep1Table Failed!";
    }
    QSqlQuery query15;
    if(!query15.exec("CREATE TABLE `Step7_3` ( `valueExpectation` TEXT, `QualityParameterName` TEXT, `valuequalityResult` REAL )"))
    {
        qDebug() << "Create createStep1Table Failed!";
    }
    QSqlQuery query16;
    if(!query16.exec("CREATE TABLE `Step7out` ( `valueExpectation` TEXT, `QualityParameterName` TEXT, `valuequalityResult` REAL )"))
    {
        qDebug() << "Create createStep1Table Failed!";
    }
    QSqlQuery query17;
    if(!query17.exec("CREATE TABLE 'Step8' ( `QualityParameters` TEXT, `relativeImportanceRating` REAL )"))
    {
        qDebug() << "Create createStep1Table Failed!";
    }
    return true;
}
bool Initialize_DB::exportDatabase(QString xxx)
{
       qDebug()<<"Initialize_DB::exportDatabase";
       QString filePath ="C:/Users/Administrator/Desktop/xxxxxx.xlsx";
       QAxObject *work_book = NULL;
       QAxObject excel("Excel.Application");
       excel.setProperty("Visible", false);
       excel.setProperty("DisplayAlerts", false);//不显示任何警告信息
       QAxObject *work_books = excel.querySubObject("WorkBooks");
       QFile xlsFile(filePath);
       if (xlsFile.exists())
       {
           work_book = work_books->querySubObject("Open(const QString &)", filePath);
       }
       else
       {
             work_books->dynamicCall("Add");
             work_book = excel.querySubObject("ActiveWorkBook");
       }

       QAxObject *work_sheets = work_book->querySubObject("Sheets");
       QAxObject *first_sheet = work_sheets->querySubObject("Item(int)", 1);

       Sqlite sqlite ;
       vector<Entity_Step1> returnlist = sqlite.queryStep1Data();
       qDebug()<<"returnlist.size()"<<returnlist.size();
       for(int i =0;i<returnlist.size();i++)
       {
           QAxObject *cell = first_sheet->querySubObject("Cells(int,int)",  i+1,1 );
           cell->setProperty("Value", returnlist[i].valueIndexName);
           QAxObject *cell2 = first_sheet->querySubObject("Cells(int,int)", i+1, 2);
           cell2->setProperty("Value", returnlist[i].valueOperator);
           QAxObject *cell3 = first_sheet->querySubObject("Cells(int,int)", i+1, 3);
           cell3->setProperty("Value", returnlist[i].expectations);
           QAxObject *cell4 = first_sheet->querySubObject("Cells(int,int)", i+1, 4);
           cell4->setProperty("Value", returnlist[i].stakeholders);
       }
       QAxObject *sheet2 = work_sheets->querySubObject("Item(int)", 2);
       vector<Entity_Step2> returnlist2 = sqlite.queryStep2Data();
       qDebug()<<"returnlist2.size()"<<returnlist2.size();
       for(int i=0;i<returnlist2.size();i++)
       {
             QAxObject *cell = sheet2->querySubObject("Cells(int,int)",  i+1,1 );
             cell->setProperty("Value", returnlist2[i].valueExpectation);
             QAxObject *cell2 = sheet2->querySubObject("Cells(int,int)",  i+1,2 );
             cell2->setProperty("Value", returnlist2[i].relativeImportanceRating);
       }

       work_book->dynamicCall("SaveAs(const QString &)", QDir::toNativeSeparators(filePath)); //转换路径不可少，否则会崩溃
       work_book->dynamicCall("Close(Boolean)", false);  //关闭文件
       excel.dynamicCall("Quit(void)");  //退出
       return true;
}

