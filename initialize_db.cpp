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
        qDebug() << "Create Step1 Failed!";
    }
    QSqlQuery query1;
    if(!query1.exec("CREATE TABLE 'Step10' ( `QualityParameterName` TEXT, `upLow` TEXT, `outputValue` REAL )"))
    {
        qDebug() << "Create Step10 Failed!";
    }
    QSqlQuery query2;
    if(!query2.exec("CREATE TABLE `Step2` ( `价值指标名称` varchar(255), `相对重要评级` double )"))
    {
        qDebug() << "Create Step2 Failed!";
    }
    QSqlQuery query3;
    if(!query3.exec("CREATE TABLE `Step2_2` ( `价值期望名称row` varchar(255), `价值期望名称rank` varchar(255), `各个价值指标的相对重要程度` varchar(255) )"))
    {
        qDebug() << "Create Step2_2 Failed!";
    }
    QSqlQuery query4;
    if(!query4.exec("CREATE TABLE `Step3_2` ( `row` varchar(255), `rank` varchar(255), `competitiveEvaluation` double )"))
    {
        qDebug() << "Create Step3_2 Failed!";
    }
    QSqlQuery query5;
    if(!query5.exec("CREATE TABLE `Step3_3` ( `row` varchar(255), `rank` varchar(255), `expectedRank` double )"))
    {
        qDebug() << "Create Step3_3 Failed!";
    }
    QSqlQuery query6;
    if(!query6.exec("CREATE TABLE `Step3_4` ( `Row` varchar(255), `rank` varchar(255), `criticality` double )"))
    {
        qDebug() << "Create Step3_4 Failed!";
    }
    QSqlQuery query7;
    if(!query7.exec("CREATE TABLE `Step4_1` ( `valueIndexName` varchar(255) )"))
    {
        qDebug() << "Create Step4_1 Failed!";
    }
    QSqlQuery query8;
    if(!query8.exec("CREATE TABLE `Step4_2` ( `chooseValueIndexName` varchar(255) )"))
    {
        qDebug() << "Create Step4_2 Failed!";
    }
    QSqlQuery query9;
    if(!query9.exec("CREATE TABLE 'Step5_1' ( `qualityParameterName` varchar ( 255 ), `dataType` varchar ( 255 ), `upperBoundValue` double, `lowerBoundValue` double )"))
    {
        qDebug() << "Create Step5_1 Failed!";
    }
    QSqlQuery query10;
    if(!query10.exec("CREATE TABLE `Step6_1` ( `row` varchar(255), `qualityParameterName` varchar(255), `value` double )"))
    {
        qDebug() << "Create Step6_1 Failed!";
    }
    QSqlQuery query11;
    if(!query11.exec("CREATE TABLE `Step6_2` ( `qualityParameterNameRow` varchar(255), `qualityParameterNameRank` varchar(255), `valueQualityType` varchar(255), `BValue` double )"))
    {
        qDebug() << "Create Step6_2 Failed!";
    }
    QSqlQuery query12;
    if(!query12.exec("CREATE TABLE `Step6_3` ( `row` varchar(255), `rank` varchar(255), `autocorrelationResult` double )"))
    {
        qDebug() << "Create Step6_3 Failed!";
    }
    QSqlQuery query13;
    if(!query13.exec("CREATE TABLE `Step7_1` ( `valueExpectation` TEXT, `QualityParameterName` TEXT, `valuequalityResult` REAL, `Evalue` REAL )"))
    {
        qDebug() << "Create Step7_1 Failed!";
    }
    QSqlQuery query14;
    if(!query14.exec("CREATE TABLE 'Step7_2' ( `qualityParameterNameRow` TEXT, `qualityParameterNameRank` TEXT, `valueQualityType` TEXT, `BValue` REAL )"))
    {
        qDebug() << "Create Step7_2 Failed!";
    }
    QSqlQuery query15;
    if(!query15.exec("CREATE TABLE `Step7_3` ( `valueExpectation` TEXT, `QualityParameterName` TEXT, `valuequalityResult` REAL )"))
    {
        qDebug() << "Create Step7_3 Failed!";
    }
    QSqlQuery query16;
    if(!query16.exec("CREATE TABLE `Step7out` ( `valueExpectation` TEXT, `QualityParameterName` TEXT, `valuequalityResult` REAL )"))
    {
        qDebug() << "Create Step7out Failed!";
    }
    QSqlQuery query17;
    if(!query17.exec("CREATE TABLE 'Step8' ( `QualityParameters` TEXT, `relativeImportanceRating` REAL )"))
    {
        qDebug() << "Create Step8 Failed!";
    }
    QSqlQuery query18;
    if(!query18.exec("CREATE TABLE `Step9_2` ( `valueExpectationRow` TEXT, `valueExpectationRank` TEXT, `competitiveEvaluation` TEXT )"))
    {
        qDebug() << "Create Step9_2 Failed!";
    }
    QSqlQuery query19;
    if(!query19.exec("CREATE TABLE `Step9_3` ( `valueExpectationRow` TEXT, `valueExpectationRank` TEXT, `expectedRank` TEXT )"))
    {
        qDebug() << "Create Step9_3 Failed!";
    }
    QSqlQuery query20;
    if(!query20.exec("CREATE TABLE `Step9_4` ( `valueExpectationRow` TEXT, `valueExpectationRank` TEXT, `criticality` TEXT )"))
    {
        qDebug() << "Create Step9_4 Failed!";
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
    pSheets = pWorkBook->querySubObject("Sheets");//获取工作表集合
    QAxObject* newSheet4 = pSheets->querySubObject("Add()");
    QAxObject* newSheet5 = pSheets->querySubObject("Add()");
    QAxObject* newSheet6 = pSheets->querySubObject("Add()");
    QAxObject* newSheet7 = pSheets->querySubObject("Add()");
    QAxObject* newSheet8 = pSheets->querySubObject("Add()");
    QAxObject* newSheet9 = pSheets->querySubObject("Add()");
    QAxObject* newSheet10 = pSheets->querySubObject("Add()");
    QAxObject* newSheet11 = pSheets->querySubObject("Add()");
    QAxObject* newSheet12 = pSheets->querySubObject("Add()");
    QAxObject* newSheet13 = pSheets->querySubObject("Add()");
    QAxObject* newSheet14 = pSheets->querySubObject("Add()");
    QAxObject* newSheet15 = pSheets->querySubObject("Add()");
    QAxObject* newSheet16 = pSheets->querySubObject("Add()");
    QAxObject* newSheet17 = pSheets->querySubObject("Add()");
    QAxObject* newSheet18 = pSheets->querySubObject("Add()");
     QAxObject* newSheet19 = pSheets->querySubObject("Add()");
 //    QAxObject* newSheet20 = pSheets->querySubObject("Add()");
        ////////////////////
        /// \brief pSheet
        /// ///
        pSheet = pSheets->querySubObject("Item(int)",1);//获取工作表集合的工作表1，即sheet1
        pSheet->setProperty("Name", "step1");
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
        sheet2->setProperty("Name", "step2");
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
        sheet3->setProperty("Name", "step3_2");
        vector<Entity_Step3_2> returnlist32 = sqlite.queryStep3_2Data();
        for(int i=0;i<returnlist32.size();i++)
        {
              QAxObject *cell = sheet3->querySubObject("Cells(int,int)",  i+1,1 );
              cell->setProperty("Value", returnlist32[i].valueExpectationRow);
              QAxObject *cell2 = sheet3->querySubObject("Cells(int,int)",  i+1,2 );
              cell2->setProperty("Value", returnlist32[i].valueExpectationRank);
              QAxObject *cell3 = sheet3->querySubObject("Cells(int,int)",  i+1,3 );
              cell3->setProperty("Value", returnlist32[i].competitiveEvaluation);
        }
         qDebug()<<"queryStep3_2Data over";
         //////////////////////
         /// \brief sheet4
         ///
        QAxObject *sheet4 = pSheets->querySubObject("Item(int)", 4);
                    sheet4->setProperty("Name", "step3_3");
        vector<Entity_Step3_3> returnlist33 = sqlite.queryStep3_3Data();
        for(int i=0;i<returnlist33.size();i++)
        {
              QAxObject *cell = sheet4->querySubObject("Cells(int,int)",  i+1,1 );
              cell->setProperty("Value", returnlist33[i].valueExpectationRow);
              QAxObject *cell2 = sheet4->querySubObject("Cells(int,int)",  i+1,2 );
              cell2->setProperty("Value", returnlist33[i].valueExpectationRank);
              QAxObject *cell3 = sheet4->querySubObject("Cells(int,int)",  i+1,3 );
              cell3->setProperty("Value", returnlist33[i].expectedRank);
        }
        qDebug()<<"queryStep3_3Data over";
        ///////////////////////
        /// \brief sheet5
        ///
        QAxObject *sheet5 = pSheets->querySubObject("Item(int)", 5);
                    sheet5->setProperty("Name", "step3_4");
        vector<Entity_Step3_4> returnlist34 = sqlite.queryStep3_4Data();
        for(int i=0;i<returnlist34.size();i++)
        {
              QAxObject *cell = sheet5->querySubObject("Cells(int,int)",  i+1,1 );
              cell->setProperty("Value", returnlist34[i].valueExpectationRow);
              QAxObject *cell2 = sheet5->querySubObject("Cells(int,int)",  i+1,2 );
              cell2->setProperty("Value", returnlist34[i].valueExpectationRank);
              QAxObject *cell3 = sheet5->querySubObject("Cells(int,int)",  i+1,3 );
              cell3->setProperty("Value", returnlist34[i].criticality);
        }
         qDebug()<<"queryStep3_4Data over";
         ////////////////////////
         /// \brief sheet6
         ///
        QAxObject *sheet6 = pSheets->querySubObject("Item(int)", 6);
                 sheet6->setProperty("Name", "step4_1");
        vector<Entity_Step4_1> returnlist41 = sqlite.queryStep4_1Data();
        for(int i=0;i<(int)returnlist41.size();i++)
        {
              QAxObject *cell = sheet6->querySubObject("Cells(int,int)",  i+1,1 );
              cell->setProperty("Value", returnlist41[i].QualityParameterName);
        }
        qDebug()<<"queryStep4_1Data over";
        //////////////////////////
        /// \brief sheet7
        ///
        QAxObject *sheet7 = pSheets->querySubObject("Item(int)", 7);
        sheet7->setProperty("Name", "step4_2");
        vector<Entity_Step4_2> returnlist42= sqlite.queryStep4_2Data();
        for(int i=0;i<(int)returnlist42.size();i++)
        {
              QAxObject *cell = sheet7->querySubObject("Cells(int,int)",  i+1,1 );
              cell->setProperty("Value", returnlist42[i].chooseQualityParameterName);
        }
        qDebug()<<"queryStep4_2Data over";
        //////////////
        /// \brief sheet8
        ///
         QAxObject *sheet8 = pSheets->querySubObject("Item(int)", 8);
                sheet8->setProperty("Name", "step5");
         vector<Entity_Step5> returnlist5= sqlite.queryStep5Data();
         for(int i=0;i<(int)returnlist5.size();i++)
         {
               QAxObject *cell = sheet8->querySubObject("Cells(int,int)",  i+1,1 );
               cell->setProperty("Value", returnlist5[i].qualityParameterName);
               QAxObject *cell2 = sheet8->querySubObject("Cells(int,int)", i+1, 2);
               cell2->setProperty("Value", returnlist5[i].dataType);
               QAxObject *cell3 = sheet8->querySubObject("Cells(int,int)", i+1, 3);
               cell3->setProperty("Value", returnlist5[i].upperBoundValue);
               QAxObject *cell4 = sheet8->querySubObject("Cells(int,int)", i+1, 4);
               cell4->setProperty("Value", returnlist5[i].lowerBoundValue);
         }
         ////////////////
         /// \brief sheet9
         ///
         QAxObject *sheet9 = pSheets->querySubObject("Item(int)", 9);
         sheet9->setProperty("Name", "step6_1");
         vector<Entity_Step6_1> returnlist61= sqlite.queryStep6_1Data();
         for(int i=0;i<(int)returnlist61.size();i++)
         {
               QAxObject *cell = sheet9->querySubObject("Cells(int,int)",  i+1,1 );
               cell->setProperty("Value", returnlist61[i].row);
               QAxObject *cell2 = sheet9->querySubObject("Cells(int,int)", i+1, 2);
               cell2->setProperty("Value", returnlist61[i].qualityParameterName);
               QAxObject *cell3 = sheet9->querySubObject("Cells(int,int)", i+1, 3);
               cell3->setProperty("Value", returnlist61[i].value);
         }
         //////////////////
         /// \brief sheet10
         ///
         QAxObject *sheet10 = pSheets->querySubObject("Item(int)", 10);
         sheet10->setProperty("Name", "step6_2");
         vector<Entity_Step6_2> returnlist62= sqlite.queryStep6_2Data();
         for(int i=0;i<(int)returnlist62.size();i++)
         {
               QAxObject *cell = sheet10->querySubObject("Cells(int,int)",  i+1,1 );
               cell->setProperty("Value", returnlist62[i].qualityParameterNameRow);
               QAxObject *cell2 = sheet10->querySubObject("Cells(int,int)", i+1, 2);
               cell2->setProperty("Value", returnlist62[i].qualityParameterNameRank);
               QAxObject *cell3 = sheet10->querySubObject("Cells(int,int)", i+1, 3);
               cell3->setProperty("Value", returnlist62[i].valueQualityType);
               QAxObject *cell4 = sheet10->querySubObject("Cells(int,int)", i+1, 4);
               cell4->setProperty("Value", returnlist62[i].BValue);
         }
         //////////////////////
         /// \brief sheet11
         ///
         QAxObject *sheet11 = pSheets->querySubObject("Item(int)", 11);
          sheet11->setProperty("Name", "step6_3");
         vector<Entity_Step6_3> returnlist63= sqlite.queryStep6_3Data();
         for(int i=0;i<(int)returnlist63.size();i++)
         {
               QAxObject *cell = sheet11->querySubObject("Cells(int,int)",  i+1,1 );
               cell->setProperty("Value", returnlist63[i].row);
               QAxObject *cell2 = sheet11->querySubObject("Cells(int,int)", i+1, 2);
               cell2->setProperty("Value", returnlist63[i].rank);
               QAxObject *cell3 = sheet11->querySubObject("Cells(int,int)", i+1, 3);
               cell3->setProperty("Value", returnlist63[i].autocorrelationResult);
         }
         /////////////
         /// \brief sheet12
         ///
         QAxObject *sheet12 = pSheets->querySubObject("Item(int)", 12);
         sheet12->setProperty("Name", "step7_1");
         vector<Entity_Step7_1> returnlist71= sqlite.queryStep7_1Data();
         for(int i=0;i<(int)returnlist71.size();i++)
         {
               QAxObject *cell = sheet12->querySubObject("Cells(int,int)",  i+1,1 );
               cell->setProperty("Value", returnlist71[i].valueExpectation);
               QAxObject *cell2 = sheet12->querySubObject("Cells(int,int)", i+1, 2);
               cell2->setProperty("Value", returnlist71[i].QualityParameterName);
               QAxObject *cell3 = sheet12->querySubObject("Cells(int,int)", i+1, 3);
               cell3->setProperty("Value", returnlist71[i].valuequalityResult);
               QAxObject *cell4 = sheet12->querySubObject("Cells(int,int)", i+1, 4);
               cell4->setProperty("Value", returnlist71[i].Evalue);
         }
         //////////////
         /// \brief sheet13
         ///
         QAxObject *sheet13 = pSheets->querySubObject("Item(int)", 13);
         sheet13->setProperty("Name", "step7_2");
         vector<Entity_Step7_2> returnlist72= sqlite.queryStep7_2Data();
         for(int i=0;i<(int)returnlist72.size();i++)
         {
               QAxObject *cell = sheet13->querySubObject("Cells(int,int)",  i+1,1 );
               cell->setProperty("Value", returnlist72[i].qualityParameterNameRow);
               QAxObject *cell2 = sheet13->querySubObject("Cells(int,int)", i+1, 2);
               cell2->setProperty("Value", returnlist72[i].qualityParameterNameRank);
               QAxObject *cell3 = sheet13->querySubObject("Cells(int,int)", i+1, 3);
               cell3->setProperty("Value", returnlist72[i].valueQualityType);
               QAxObject *cell4 = sheet13->querySubObject("Cells(int,int)", i+1, 4);
               cell4->setProperty("Value", returnlist72[i].BValue);
         }
         ///////////
         /// \brief sheet14
         ///
         QAxObject *sheet14 = pSheets->querySubObject("Item(int)", 14);
         sheet14->setProperty("Name", "step7_3");
         vector<Entity_Step7_3> returnlist73= sqlite.queryStep7_3Data();
         for(int i=0;i<(int)returnlist73.size();i++)
         {
               QAxObject *cell = sheet14->querySubObject("Cells(int,int)",  i+1,1 );
               cell->setProperty("Value", returnlist73[i].valueExpectation);
               QAxObject *cell2 = sheet14->querySubObject("Cells(int,int)", i+1, 2);
               cell2->setProperty("Value", returnlist73[i].QualityParameterName);
               QAxObject *cell3 = sheet14->querySubObject("Cells(int,int)", i+1, 3);
               cell3->setProperty("Value", returnlist73[i].valuequalityResult);
         }
         //////////
         /// \brief sheet15
         ///
         QAxObject *sheet15 = pSheets->querySubObject("Item(int)", 15);
         sheet15->setProperty("Name", "step8");
         vector<Entity_Step8> returnlist8= sqlite.queryStep8Data();
         for(int i=0;i<(int)returnlist8.size();i++)
         {
               QAxObject *cell = sheet15->querySubObject("Cells(int,int)",  i+1,1 );
               cell->setProperty("Value", returnlist8[i].QualityParameters);
               QAxObject *cell2 = sheet15->querySubObject("Cells(int,int)", i+1, 2);
               cell2->setProperty("Value", returnlist8[i].relativeImportanceRating);
         }
         //////////
         /// \brief sheet16
         ///
         QAxObject *sheet16 = pSheets->querySubObject("Item(int)", 16);
         sheet16->setProperty("Name", "step9_2");
         vector<Entity_Step9_2> returnlist92= sqlite.queryStep9_2Data();
         for(int i=0;i<(int)returnlist92.size();i++)
         {
               QAxObject *cell = sheet16->querySubObject("Cells(int,int)",  i+1,1 );
               cell->setProperty("Value", returnlist92[i].valueExpectationRow);
               QAxObject *cell2 = sheet16->querySubObject("Cells(int,int)", i+1, 2);
               cell2->setProperty("Value", returnlist92[i].valueExpectationRank);
               QAxObject *cell3 = sheet16->querySubObject("Cells(int,int)", i+1, 3);
               cell3->setProperty("Value", returnlist92[i].competitiveEvaluation);
         }
         ///////////
         /// \brief sheet17
         ///
         QAxObject *sheet17 = pSheets->querySubObject("Item(int)", 17);
         sheet17->setProperty("Name", "step9_3");
         vector<Entity_Step9_3> returnlist93= sqlite.queryStep9_3Data();
         for(int i=0;i<(int)returnlist93.size();i++)
         {
               QAxObject *cell = sheet17->querySubObject("Cells(int,int)",  i+1,1 );
               cell->setProperty("Value", returnlist93[i].valueExpectationRow);
               QAxObject *cell2 = sheet17->querySubObject("Cells(int,int)", i+1, 2);
               cell2->setProperty("Value", returnlist93[i].valueExpectationRank);
               QAxObject *cell3 = sheet17->querySubObject("Cells(int,int)", i+1, 3);
               cell3->setProperty("Value", returnlist93[i].expectedRank);
         }
          qDebug()<<"queryStep9_3Data over";
//         ///////////
//         /// \brief sheet18
//         ///
//         QAxObject *sheet18 = pSheets->querySubObject("Item(int)", 18);
//         sheet18->setProperty("Name", "step9_4");
//         vector<Entity_Step9_4> returnlist94= sqlite.queryStep9_4Data();
//         for(int i=0;i<(int)returnlist94.size();i++)
//         {
//               QAxObject *cell = sheet18->querySubObject("Cells(int,int)",  i+1,1 );
//               cell->setProperty("Value", returnlist94[i].valueExpectationRow);
//               QAxObject *cell2 = sheet18->querySubObject("Cells(int,int)", i+1, 2);
//               cell2->setProperty("Value", returnlist94[i].valueExpectationRank);
//               QAxObject *cell3 = sheet18->querySubObject("Cells(int,int)", i+1, 3);
//               cell3->setProperty("Value", returnlist94[i].criticality);
//         }
//         qDebug()<<"queryStep9_4Data over";
//         ////////////////
//         /// \brief sheet19
//         ///
//         QAxObject *sheet19 = pSheets->querySubObject("Item(int)", 19);
//         sheet19->setProperty("Name", "step10");
//         vector<Entity_Step10> returnlist10= sqlite.queryStep10Data();
//         for(int i=0;i<(int)returnlist10.size();i++)
//         {
//               QAxObject *cell = sheet19->querySubObject("Cells(int,int)",  i+1,1 );
//               cell->setProperty("Value", returnlist10[i].QualityParameterName);
//               QAxObject *cell2 = sheet19->querySubObject("Cells(int,int)", i+1, 2);
//               cell2->setProperty("Value", returnlist10[i].upLow);
//               QAxObject *cell3 = sheet19->querySubObject("Cells(int,int)", i+1, 3);
//               cell3->setProperty("Value", returnlist10[i].outputValue);
//         }
//         qDebug()<<"queryStep10Data over";

    pWorkBook->dynamicCall("SaveAs(const QString&)",QDir::toNativeSeparators(fileName));//保存至filepath，注意一定要用QDir::toNativeSeparators将路径中的"/"转换为"\"，不然一定保存不了。
    pWorkBook->dynamicCall("Close()");//关闭工作簿
    pApplication->dynamicCall("Quit()");//关闭excel

    return true;
}


