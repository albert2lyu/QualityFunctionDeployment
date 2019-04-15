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
    /// \brief Entity_Step3_2 returnList
    ///
    vector<Entity_Step3_2>returnList = sqlite.queryStep3_2Data();
    if(returnList.size() != 0 )
    {
        int end_size = (int) returnList.size();
        qDebug()<<"MatlabFunction::mlfStep3::returnList::end_size"<<end_size;
        Entity_Step3_2  entity_Step3_2 = (Entity_Step3_2) returnList[(end_size-1)];
        int row = (int) entity_Step3_2.valueExpectationRow.toInt()+1;
        qDebug()<<"MatlabFunction::mlfStep3::returnList::row"<<row;
        int col = (int) entity_Step3_2.valueExpectationRank.toInt()+1;
        qDebug()<<"MatlabFunction::mlfStep3::returnList::col"<<col;
        int step3_2Matrix[row][col];
        for(int i =0;i<returnList.size();i++)
        {
            int step3_2MatrixRow = (int) returnList[i].valueExpectationRow.toInt();
            qDebug()<<"MatlabFunction::mlfStep3::returnList::step3_2MatrixRow"<<step3_2MatrixRow;
            int step3_2MatrixCol = (int) returnList[i].valueExpectationRank.toInt();
            qDebug()<<"MatlabFunction::mlfStep3::returnList::step3_2MatrixCol"<<step3_2MatrixCol;
            step3_2Matrix[step3_2MatrixRow][step3_2MatrixCol] = (int)returnList[i].competitiveEvaluation.toInt();
            qDebug()<<"MatlabFunction::mlfStep3::returnList::step3_2Matrix[step3_2MatrixRow][step3_2MatrixCol]"<<entity_Step3_2.competitiveEvaluation.toInt();
        }

        //////
        /// \brief Entity_Step3_3 returnList
        ///
        vector<Entity_Step3_3>returnList3_3 = sqlite.queryStep3_3Data();
        if(returnList3_3.size() != 0)
        {
            int returnList3_3_end_size = (int) returnList3_3.size();
            qDebug()<<"MatlabFunction::mlfStep3::returnList::returnList3_3_end_size"<<returnList3_3_end_size;
            Entity_Step3_3  entity_Step3_3 = (Entity_Step3_3) returnList3_3[(returnList3_3_end_size-1)];
            int entity_Step3_3_row = (int) entity_Step3_3.valueExpectationRow.toInt()+1;
            qDebug()<<"MatlabFunction::mlfStep3::returnList::row"<<row;
            int entity_Step3_3_col = (int) entity_Step3_3.valueExpectationRank.toInt()+1;
            qDebug()<<"MatlabFunction::mlfStep3::returnList::col"<<col;
            int step3_3Matrix[entity_Step3_3_row][entity_Step3_3_col];
            for(int i =0;i<returnList3_3.size();i++)
            {
                int step3_3MatrixRow = (int) returnList3_3[i].valueExpectationRow.toInt();
                qDebug()<<"MatlabFunction::mlfStep3::returnList::step3_3MatrixRow"<<step3_3MatrixRow;
                int step3_3MatrixCol = (int) returnList3_3[i].valueExpectationRank.toInt();
                qDebug()<<"MatlabFunction::mlfStep3::returnList::step3_3MatrixCol"<<step3_3MatrixCol;
                step3_3Matrix[step3_3MatrixRow][step3_3MatrixCol] = (int)returnList3_3[i].expectedRank.toInt();
                qDebug()<<"MatlabFunction::mlfStep3::returnList:: step3_3Matrix[step3_3MatrixRow][step3_3MatrixCol]"<<entity_Step3_2.competitiveEvaluation.toInt();
            }

        }


    }


}

















