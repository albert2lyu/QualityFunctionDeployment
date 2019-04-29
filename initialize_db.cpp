#include "initialize_db.h"
#include <QDebug>
#include <QtSql>
#include <QFileDialog>
#include <QAxObject>
#include "sqlite.h"
#include <QDateTime>
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
Initialize_DB::Initialize_DB()
{

}
bool Initialize_DB::Initialize_QFD(QString dbName)
{
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString current_date =current_date_time.toString("yyyy.MM.dd hh:mm:ss.zzz ddd").
                                trimmed().replace(".","").replace(" ","").replace(":","")+".db";
    qDebug()<<"Initialize_QFD::currentDate"<<current_date;

    qDebug()<<"Initialize_DB::Initialize_QFD";
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(current_date);
    db.open();
    if(!db.open())
    {
        qDebug() << "QSqlDatabase not open";
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

    QAxObject *pApplication = nullptr;
    QAxObject *pWorkBooks = nullptr;
    QAxObject *pSheets = nullptr;
    QAxObject *pSheet = nullptr;
    QAxObject *pWorkBook = nullptr;
    QString fileName = QFileDialog::getSaveFileName(NULL,"Save File",".","Excel File(*.xls)");
    pApplication = new QAxObject();
    pApplication->setControl("Excel.Application");//连接exl控件
    pApplication->dynamicCall("SetVisible(bool)",false);//不显示窗体
    pApplication->setProperty("DisplayAlerts",false);//不显示警告信息
    pWorkBooks = pApplication->querySubObject("Workbooks");//获取工作薄合集
    pWorkBooks->dynamicCall("Add");//新建
    pWorkBook = pApplication->querySubObject("ActiveWorkBook");//获取当前工作薄合集
    //pWorkBook->dynamicCall("SaveAs(const QString&)",fileName);
    pSheets = pWorkBook->querySubObject("Sheets");//获取工作表集合
    QAxObject* newSheet = pSheets->querySubObject("Add()");
    pSheet = pSheets->querySubObject("Item(int)",1);//获取工作表集合的工作表1，即sheet1
        Sqlite sqlite ;
        vector<Entity_Step1> returnlist = sqlite.queryStep1Data();
        for(int i =0;i<returnlist.size();i++)
        {
            QAxObject *cell = pSheet->querySubObject("Cells(int,int)",  i+1,1 );
            cell->setProperty("Value", returnlist[i].valueIndexName);
            QAxObject *cell2 = pSheet->querySubObject("Cells(int,int)", i+1, 2);
            cell2->setProperty("Value", returnlist[i].valueOperator);
            QAxObject *cell3 = pSheet->querySubObject("Cells(int,int)", i+1, 3);
            cell3->setProperty("Value", returnlist[i].expectations);
            QAxObject *cell4 = pSheet->querySubObject("Cells(int,int)", i+1, 4);
            cell4->setProperty("Value", returnlist[i].stakeholders);
        }
        qDebug()<<"queryStep1Data over";
        //////////////////////////
        /// \brief sheet2
        ///
        QAxObject *sheet2 = pSheets->querySubObject("Item(int)", 2);
        vector<Entity_Step2> returnlist2 = sqlite.queryStep2Data();
        for(int i=0;i<returnlist2.size();i++)
        {
              QAxObject *cell = sheet2->querySubObject("Cells(int,int)",  i+1,1 );
              cell->setProperty("Value", returnlist2[i].valueExpectation);
              QAxObject *cell2 = sheet2->querySubObject("Cells(int,int)",  i+1,2 );
              cell2->setProperty("Value", returnlist2[i].relativeImportanceRating);
        }
        qDebug()<<"queryStep2Data over";
        ///////////////////////
        /// \brief sheet3
        ///
        QAxObject *sheet3 = pSheets->querySubObject("Item(int)", 3);
        vector<Entity_Step3_2> returnlist32 = sqlite.queryStep3_2Data();
        for(int i=0;i<returnlist32.size();i++)
        {
              QAxObject *cell = sheet3->querySubObject("Cells(int,int)",  i+1,1 );
              cell->setProperty("Value", returnlist32[i].valueExpectationRow);
              QAxObject *cell2 = sheet3->querySubObject("Cells(int,int)",  i+1,2 );
              cell2->setProperty("Value", returnlist32[i].valueExpectationRank);
              QAxObject *cell3 = sheet3->querySubObject("Cells(int,int)",  i+1,3 );
              cell2->setProperty("Value", returnlist32[i].competitiveEvaluation);
        }
         qDebug()<<"queryStep3_2Data over";
         /*
         //////////////////////
         /// \brief sheet4
         ///
        QAxObject *sheet4 = pSheets->querySubObject("Item(int)", 4);
        vector<Entity_Step3_3> returnlist33 = sqlite.queryStep3_3Data();
        for(int i=0;i<returnlist33.size();i++)
        {
              QAxObject *cell = sheet4->querySubObject("Cells(int,int)",  i+1,1 );
              cell->setProperty("Value", returnlist33[i].valueExpectationRow);
              QAxObject *cell2 = sheet4->querySubObject("Cells(int,int)",  i+1,2 );
              cell2->setProperty("Value", returnlist33[i].valueExpectationRank);
              QAxObject *cell3 = sheet4->querySubObject("Cells(int,int)",  i+1,3 );
              cell2->setProperty("Value", returnlist33[i].expectedRank);
        }
        qDebug()<<"queryStep3_3Data over";
        ///////////////////////
        /// \brief sheet5
        ///
        QAxObject *sheet5 = pSheets->querySubObject("Item(int)", 5);
        vector<Entity_Step3_4> returnlist34 = sqlite.queryStep3_4Data();
        for(int i=0;i<returnlist34.size();i++)
        {
              QAxObject *cell = sheet5->querySubObject("Cells(int,int)",  i+1,1 );
              cell->setProperty("Value", returnlist34[i].valueExpectationRow);
              QAxObject *cell2 = sheet5->querySubObject("Cells(int,int)",  i+1,2 );
              cell2->setProperty("Value", returnlist34[i].valueExpectationRank);
              QAxObject *cell3 = sheet5->querySubObject("Cells(int,int)",  i+1,3 );
              cell2->setProperty("Value", returnlist34[i].criticality);
        }
         qDebug()<<"queryStep3_4Data over";
         ////////////////////////
         /// \brief sheet6
         ///
        QAxObject *sheet6 = pSheets->querySubObject("Item(int)", 6);
        vector<Entity_Step4_1> returnlist41 = sqlite.queryStep4_1Data();
        for(int i=0;i<returnlist41.size();i++)
        {
              QAxObject *cell = sheet6->querySubObject("Cells(int,int)",  i+1,1 );
              cell->setProperty("Value", returnlist41[i].QualityParameterName);
        }
        qDebug()<<"queryStep4_1Data over";
        //////////////////////////
        /// \brief sheet7
        ///
        QAxObject *sheet7 = pSheets->querySubObject("Item(int)", 7);
        vector<Entity_Step4_2> returnlist42= sqlite.queryStep4_2Data();
        for(int i=0;i<returnlist41.size();i++)
        {
              QAxObject *cell = sheet7->querySubObject("Cells(int,int)",  i+1,1 );
              cell->setProperty("Value", returnlist42[i].chooseQualityParameterName);
        }
        qDebug()<<"queryStep4_2Data over";


*/
    pWorkBook->dynamicCall("SaveAs(const QString&)",QDir::toNativeSeparators(fileName));//保存至filepath，注意一定要用QDir::toNativeSeparators将路径中的"/"转换为"\"，不然一定保存不了。
    pWorkBook->dynamicCall("Close()");//关闭工作簿
    pApplication->dynamicCall("Quit()");//关闭excel

    return true;
}


