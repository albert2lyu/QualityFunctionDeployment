#include "matlabfunction.h"
#include "matBasic.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDebug>
#include <QComboBox>
#include <QFileDialog>
#include <QLibrary>
#include "matBasic.h"
#include <QHeaderView>
#include "sqlite.h"
#include "entity_step3_3.h"
#include "engine.h"
MatlabFunction::MatlabFunction()
{

}
typedef void  (*Pcom_matFahp)(int , mxArray**,  mxArray*);
typedef bool  (*Pcom_matBasicsssInitialize)(void);
bool MatlabFunction::matBasi(QTableWidget *tableWidget)
{
     QLibrary mylib("matBasic.DLL");
     if(mylib.load())
     {
         qDebug()<<"MatlabFunction::matBasi";
     }
     Pcom_matBasicsssInitialize pcom_matBasicsssInitialize =
            (Pcom_matBasicsssInitialize)mylib.resolve("matBasicInitialize");
     if(pcom_matBasicsssInitialize)
     {
         pcom_matBasicsssInitialize();
         qDebug()<<"MatlabFunction::pcom_matBasicsssInitialize";
     }
     int rowCntA = tableWidget->rowCount();
     qDebug()<<"MatlabFunction::rowCntA"<<rowCntA;
     int colCntA = tableWidget->columnCount();
     qDebug()<<"MatlabFunction::colCntA"<<colCntA;
     if(rowCntA != colCntA)
     {
         qDebug()<<"MatlabFunction::矩阵A行列不一致，不能计算";
     }
     double arrayA [rowCntA][colCntA];
       for(int i=0;i<rowCntA;i++)
       {
           for (int j=0; j<colCntA;j++)
          {
             arrayA[i][j]=tableWidget->item(j,i)->text().toDouble();
          }
       }
     //初始化matrixA
     mxArray *matrixA = mxCreateDoubleMatrix(rowCntA,colCntA,mxREAL);//定义数组，行，列，double类型
     memcpy((void *)mxGetPr(matrixA),(void *)arrayA,sizeof(arrayA));
     //初始化matrixC
     int   rowCntC=rowCntA;
     int   colCntC=1;
     mxArray *matrixC = mxCreateDoubleMatrix(rowCntC,colCntC,mxREAL);
     int nargout=1;//输出变量个数
     Pcom_matFahp pcom_matFahp = (Pcom_matFahp) mylib.resolve("mlfMatFahp");
     if(pcom_matFahp)
     {
         qDebug()<<"MatlabFunction::mlfMatFahp";
         pcom_matFahp(nargout,&matrixC,matrixA);
         double * pr = mxGetPr(matrixC);
         qDebug()<<"MatlabFunction::mxGetM"<<mxGetM(matrixC);
         Sqlite sqlite ;
         sqlite.connect();
         sqlite.deleteStep2Table();
         for(int i = 0;i<tableWidget->horizontalHeader()->count();i++)
         {
            QString valueExpectationRow = tableWidget->horizontalHeaderItem(i)->data(Qt::DisplayRole).toString();
            qDebug()<<"MatlabFunction::valueExpectationRow"<<valueExpectationRow;
            double  matrixCoutput = pr[i];
            qDebug()<<"MatlabFunction::"<<QString::number(matrixCoutput);
            sqlite.saveStep2TableDouble(valueExpectationRow,matrixCoutput);
         }
     }
}
typedef void  (*Pcom_mlfStep3)(int , mxArray**,  mxArray*, mxArray*, mxArray*, mxArray*);
typedef bool  (*Pcom_step3Initialize)(void);
bool MatlabFunction::mlfStep3(QTableWidget *tableWidget)
{
    qDebug()<<"MatlabFunction::mlfStep3";
    QLibrary mylib("step3.DLL");
    if(mylib.load())
    {
        qDebug()<<"MatlabFunction::mlfStep3";
    }
    Pcom_step3Initialize pcom_step3Initialize =
           (Pcom_step3Initialize)mylib.resolve("step3Initialize");
    if(pcom_step3Initialize)
    {
        pcom_step3Initialize();
        qDebug()<<"MatlabFunction::pcom_matBasicsssInitialize";
    }

    Sqlite sqlite ;
    sqlite.connect();
    ////////////
    /// \brief Entity_Step3_2 returnList 竞争性分析矩::输入,n列,行数不确定C3:
    ///
    vector<Entity_Step3_2>returnList = sqlite.queryStep3_2Data();
    if(returnList.size() != 0 )
    {
        int end_size = (int) returnList.size();
        Entity_Step3_2  entity_Step3_2 = (Entity_Step3_2) returnList[(end_size-1)];
        int row = (int) entity_Step3_2.valueExpectationRow.toInt()+1;
        int col = (int) entity_Step3_2.valueExpectationRank.toInt()+1;
        double step3_2Matrix[row][col];
        for(int i =0;i<returnList.size();i++)
        {
            int step3_2MatrixRow = (int) returnList[i].valueExpectationRow.toInt();
            int step3_2MatrixCol = (int) returnList[i].valueExpectationRank.toInt();
            step3_2Matrix[step3_2MatrixRow][step3_2MatrixCol] = (double)returnList[i].competitiveEvaluation.toDouble();
        }

        //////
        /// \brief Entity_Step3_3 returnList::目标等级,1*n矩阵
        ///
        vector<Entity_Step3_3>returnList3_3 = sqlite.queryStep3_3Data();
        if(returnList3_3.size() != 0)
        {
            int returnList3_3_end_size = (int) returnList3_3.size();
            Entity_Step3_3  entity_Step3_3 = (Entity_Step3_3) returnList3_3[(returnList3_3_end_size-1)];
            int entity_Step3_3_row = 1;
            int entity_Step3_3_col = (int) entity_Step3_3.valueExpectationRank.toInt()+1;
            double step3_3Matrix[entity_Step3_3_row][entity_Step3_3_col];
            for(int i =0;i<returnList3_3.size();i++)
            {
                int step3_3MatrixRow = (int) returnList3_3[i].valueExpectationRow.toInt();
                int step3_3MatrixCol = (int) returnList3_3[i].valueExpectationRank.toInt();
                step3_3Matrix[step3_3MatrixRow][step3_3MatrixCol] = (double)returnList3_3[i].expectedRank.toDouble();
            }
            /////////
            /// \brief returnList3_4 销售点矩阵:1*n,D3数据填写时做成下拉框,三个选型对应1,1.5,1.25
            ///
            vector<Entity_Step3_4> returnList3_4 = sqlite.queryStep3_4Data();
            if(returnList3_4.size()!=0)
            {
                int returnList3_4_end_size = (int) returnList3_4.size();
                Entity_Step3_4  entity_Step3_4 = (Entity_Step3_4) returnList3_4[(returnList3_4_end_size-1)];
                int entity_Step3_4_row = 1;
                int entity_Step3_4_col = (int) entity_Step3_4.valueExpectationRank.toInt()+1;
                double step3_4Matrix[entity_Step3_4_row][entity_Step3_4_col];
                for(int i =0;i<returnList3_4.size();i++)
                {
                    int step3_4MatrixRow = (int) returnList3_4[i].valueExpectationRow.toInt();
                    int step3_4MatrixCol = (int) returnList3_4[i].valueExpectationRank.toInt();
                    step3_4Matrix[step3_4MatrixRow][step3_4MatrixCol] = (double)returnList3_4[i].criticality.toDouble();
                }
                ////////////
                /// \brief returnList3_1  Step2得到的结果,n*1矩阵
                ///
                vector<Entity_Step2>returnList3_1 = sqlite.queryStep2Data();
                int   rowCntResult=returnList3_1.size();
                int   colCntResult=1;
                double   step3_1Matrix[rowCntResult][colCntResult];
                for(int i =0;i<returnList3_1.size();i++)
                {
                    qDebug()<<"returnList3_1[i].relativeImportanceRating::"<<returnList3_1[i].relativeImportanceRating.toDouble();
                    step3_1Matrix[i][0]=returnList3_1[i].relativeImportanceRating.toDouble();
                    qDebug()<<"step3_1Matrix[i][0]"<<step3_1Matrix[i][0];
                }
                mxArray *matrixA = mxCreateDoubleMatrix(rowCntResult,1,mxREAL);//定义数组，行，列，double类型
                memcpy((void *)mxGetPr(matrixA),(void *)step3_1Matrix,sizeof(step3_1Matrix));

                mxArray *matrixB = mxCreateDoubleMatrix(row,col,mxREAL);
                memcpy((void *)mxGetPr(matrixB),(void *)step3_2Matrix,sizeof(step3_2Matrix));

                mxArray *matrixC = mxCreateDoubleMatrix(entity_Step3_3_row,entity_Step3_3_col,mxREAL);
                memcpy((void *)mxGetPr(matrixC),(void *)step3_3Matrix,sizeof(step3_3Matrix));

                mxArray *matrixD = mxCreateDoubleMatrix(entity_Step3_4_row,entity_Step3_4_col,mxREAL);
                memcpy((void *)mxGetPr(matrixD),(void *)step3_4Matrix,sizeof(step3_4Matrix));

                mxArray *matrixResult = mxCreateDoubleMatrix(1,rowCntResult,mxREAL);

                Pcom_mlfStep3 pcom_mlfStep3 = (Pcom_mlfStep3)mylib.resolve("mlfStep3");
                if(pcom_mlfStep3)
                {
                     qDebug()<<"MatlabFunction::mlfStep3";
                     pcom_mlfStep3(1,&matrixResult,matrixA,matrixB,matrixC,matrixD);
                     double * pr = mxGetPr(matrixResult);
                     sqlite.deleteStep2Table();
                     for(int i =0;i<rowCntResult;i++)
                     {
                            double  matrixResultOutput = pr[i];
                            QString resultExpectation = returnList3_1[i].valueExpectation;
                            sqlite.saveStep2Table(resultExpectation,QString::number(matrixResultOutput));
                            qDebug()<<"MatlabFunction::mlfStep3::matrixResultOutput"<<QString::number(matrixResultOutput);
                     }

                }

            }

        }


    }
}

















