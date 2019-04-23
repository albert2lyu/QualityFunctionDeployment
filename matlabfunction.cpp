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
#include<entity_step7_2.h>
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
    QList<QComboBox *> rad = tableWidget->findChildren<QComboBox *>();

    for(int i=0;i<rowCntA;i++)
    {
        for (int j=0; j<colCntA;j++)
        {
            QString temp=rad.at(0)->currentText();
            double temps;
            if(temp=="关系一")
            {

                 temps =0.1;
            } else  if(temp=="关系二"){ temps =0.2;}
            else  if(temp=="关系三"){ temps =0.4;}
            else  if(temp=="关系四"){ temps =0.5;}
            else  if(temp=="关系五"){ temps =0.6;}
            else  if(temp=="关系六"){ temps =0.8;}
            else { temps =0.9;}
            arrayA[i][j]=temps;
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
typedef bool (*Pcom_matStep67810Initialize)(void);
typedef void (*Pcom_mlfStep6)(int, mxArray** , mxArray* , mxArray* , mxArray* , mxArray*);
bool MatlabFunction::matStep6(QTableWidget *tableWidget)
{
    qDebug()<<"MatlabFunction::matStep6";
    QLibrary mylib("matStep67810.DLL");
    if(mylib.load())
    {
        qDebug()<<"MatlabFunction::matStep6";
    }
    Pcom_matStep67810Initialize pcom_matStep67810Initialize =
            (Pcom_matStep67810Initialize)mylib.resolve("matStep67810Initialize");
    if(pcom_matStep67810Initialize)
    {
        pcom_matStep67810Initialize();
        qDebug()<<"MatlabFunction::pcom_matStep67810Initialize";
    }
    Sqlite sqlite ;
    sqlite.connect();
    /*
函数：Q=matStep6(step51,step61,step621,step622)
其中：
step51是step5中输入的质量输参数的取值范围，行数与质量参数的数目一致，两列·第一列是下限，第二列是上限。
step61是step6中第一个表格输入的关于质量参数的实际数据，行数等于数据量，不定。列数等于质量参数的数目。
step621代表step6中第二个表第一分行输入的关系类型，一共六个类型，分别对应1至6，行数等于质量参数数目，列·等于质量参数数目。
step622代表step6中第二个表第二分行输入的数值，从一到十，行数列数等于质量参数数目。
Q：step6的输出，行数等于质量参数数目，列数等于质量参数数目+1
*/
    vector<Entity_Step5>returnList5 = sqlite.queryStep5Data();
    if(returnList5.size() != 0)
    {
        int returnList5Row = (int)returnList5.size();
        double Matrix51 [returnList5Row][2];
        for(int i =0;i<returnList5Row;i++)
        {
            Matrix51[i][0] = returnList5[i].lowerBoundValue;
            Matrix51[i][1] = returnList5[i].upperBoundValue;
        }
        double Matrix51_OVER [returnList5Row*2];
        int Matrix51_row_flag=0;
        int Matrix51_col_flag=0;
        for(int i =0;i<returnList5Row*2;i++)
        {
            Matrix51_OVER[i]=Matrix51[Matrix51_row_flag][Matrix51_col_flag];
            Matrix51_row_flag++;
            if(Matrix51_row_flag == returnList5Row)
            {
                Matrix51_row_flag=0;
                Matrix51_col_flag++;
            }
        }
        // Matrix51_OVER ==>  step51
        vector<Entity_Step6_1> returnList61 = sqlite.queryStep6_1Data();
        if(returnList61.size()!=0)
        {
            int  returnList61Row = (int)returnList61[(returnList61.size()-1)].row.toInt()+1;
            int  returnList61col = (int)returnList61[(returnList61.size()-1)].qualityParameterName.toInt()+1;
            double Matrix61 [returnList61Row][returnList61col];
            for(int i =0;i<returnList61.size();i++)
            {
                Matrix61[returnList61[i].row.toInt()][returnList61[i].qualityParameterName.toInt()] = returnList61[i].value;
            }
            double Matrix61_OVER[returnList61Row*returnList61col];
            int Matrix61_row_flag=0;
            int Matrix61_col_flag=0;
            for(int i=0;i<returnList61Row*returnList61col;i++)
            {
                Matrix61_OVER[i]=Matrix61[Matrix61_row_flag][Matrix61_col_flag];
                Matrix61_row_flag++;
                if(Matrix61_row_flag == returnList61Row)
                {
                    Matrix61_row_flag=0;
                    Matrix61_col_flag++;
                }
            }
            // Matrix61_OVER ==>step61
            vector<Entity_Step6_2> returnList62 = sqlite.queryStep6_2Data();
            if(returnList62.size()!=0)
            {
                int  returnList62Row = (int)returnList62[(returnList62.size()-1)].qualityParameterNameRow.toInt()+1;
                int  returnList62col = (int)returnList62[(returnList62.size()-1)].qualityParameterNameRank.toInt()+1;
                double Matrix621[returnList62Row][returnList62col];
                double Matrix622[returnList62Row][returnList62col];
                for(int i =0;i<returnList62.size();i++)
                {
                    Matrix621[returnList62[i].qualityParameterNameRow.toInt()][returnList62[i].qualityParameterNameRank.toInt()]
                            = returnList62[i].valueQualityType.toDouble();
                    Matrix622[returnList62[i].qualityParameterNameRow.toInt()][returnList62[i].qualityParameterNameRank.toInt()]
                            = returnList62[i].BValue;
                }
                double Matrix621_OVER[returnList62Row*returnList62col];
                double Matrix622_OVER[returnList62Row*returnList62col];
                int Matrix62_row_flag=0;
                int Matrix62_col_flag=0;
                for(int i=0;i<returnList62Row*returnList62col;i++)
                {
                    Matrix621_OVER[i]=Matrix621[Matrix62_row_flag][Matrix62_col_flag];
                    Matrix622_OVER[i]=Matrix622[Matrix62_row_flag][Matrix62_col_flag];
                    Matrix62_row_flag++;
                    if(Matrix62_row_flag == returnList62Row)
                    {
                        Matrix62_row_flag=0;
                        Matrix62_col_flag++;
                    }
                }
                //Matrix621_OVER ==>step621
                //Matrix622_OVER ==>step622
                mxArray *matrixA = mxCreateDoubleMatrix(returnList5Row,2,mxREAL);//定义数组，行，列，double类型
                memcpy((void *)mxGetPr(matrixA),(void *)Matrix51_OVER,sizeof(Matrix51_OVER));

                mxArray *matrixB = mxCreateDoubleMatrix(returnList61Row,returnList61col,mxREAL);//定义数组，行，列，double类型
                memcpy((void *)mxGetPr(matrixB),(void *)Matrix61_OVER,sizeof(Matrix61_OVER));

                mxArray *matrixC = mxCreateDoubleMatrix(returnList62Row,returnList62col,mxREAL);//定义数组，行，列，double类型
                memcpy((void *)mxGetPr(matrixC),(void *)Matrix621_OVER,sizeof(Matrix621_OVER));

                mxArray *matrixD = mxCreateDoubleMatrix(returnList62Row,returnList62col,mxREAL);//定义数组，行，列，double类型
                memcpy((void *)mxGetPr(matrixD),(void *)Matrix622_OVER,sizeof(Matrix622_OVER));

                mxArray *matrixResult = mxCreateDoubleMatrix(returnList5Row,(returnList5Row+1),mxREAL);//定义数组，行，列，double类型

                Pcom_mlfStep6 pcom_mlfStep6 = (Pcom_mlfStep6)mylib.resolve("mlfMatStep6");
                if(pcom_mlfStep6)
                {
                    pcom_mlfStep6(1,&matrixResult,matrixA,matrixB,matrixC,matrixD);

                    double * pr = mxGetPr(matrixResult);
                    double result [returnList5Row][returnList5Row+1];
                    int rowFlag =0;
                    int colFlag =0;

                    for(int i=0;i<returnList5Row*(returnList5Row+1);i++)
                    {
                        result[rowFlag][colFlag] = pr[i];
                        rowFlag++;
                        if(rowFlag == returnList5Row)
                        {
                            colFlag++;
                            rowFlag=0;
                        }
                    }
                    sqlite.deleteStep6_3Data();
                    for(int i =0;i<returnList5Row;i++)
                    {
                        for(int j=0;j<returnList5Row+1;j++)
                        {                             sqlite.saveStep6_3Table(QString::number(i),QString::number(j),result[i][j]);                            qDebug()<<"result::"<<result[i][j];
                        }
                    }

                }






            }

        }

    }
    return true;

}
/*
                double test[2][3]={1,2,3,4,5,6};
                for(int i =0;i<2;i++)
                {
                    qDebug()<<test[i][0]<<test[i][1]<<test[i][2];
                }
                mxArray *matrixtest = mxCreateDoubleMatrix(2,3,mxREAL);
                memcpy((void *)mxGetPr(matrixtest),(void *)test,sizeof(test));
                double * prtest = mxGetPr(matrixtest);
                qDebug()<<prtest[0];
                qDebug()<<prtest[1];
                qDebug()<<prtest[2];
                qDebug()<<prtest[3];
                qDebug()<<prtest[4];
                qDebug()<<prtest[5];

                double test1[2][3]={1,4,2,5,3,6};
                for(int i =0;i<2;i++)
                {
                    qDebug()<<test1[i][0]<<test1[i][1]<<test1[i][2];
                }
                mxArray *matrixtest1 = mxCreateDoubleMatrix(2,3,mxREAL);
                memcpy((void *)mxGetPr(matrixtest1),(void *)test1,sizeof(test1));
                double * prtest1 = mxGetPr(matrixtest1);
                qDebug()<<prtest1[0];
                qDebug()<<prtest1[1];
                qDebug()<<prtest1[2];
                qDebug()<<prtest1[3];
                qDebug()<<prtest1[4];
                qDebug()<<prtest1[5];*/


typedef void (*Pcom_mlfStep7)(int, mxArray** , mxArray* , mxArray*, mxArray* , mxArray* , mxArray* , mxArray*);
bool MatlabFunction::matStep7(QTableWidget *tableWidget)
{
    qDebug()<<"MatlabFunction::matStep7";
    QLibrary mylib("matStep67810.DLL");
    if(mylib.load())
    {
        qDebug()<<"MatlabFunction::matStep7";
    }
    Pcom_matStep67810Initialize pcom_matStep67810Initialize =
            (Pcom_matStep67810Initialize)mylib.resolve("matStep67810Initialize");
    if(pcom_matStep67810Initialize)
    {
        pcom_matStep67810Initialize();
        qDebug()<<"MatlabFunction::pcom_matStep67810Initialize";
    }
    Sqlite sqlite ;
    sqlite.connect();

    vector<Entity_Step5>returnList5 = sqlite.queryStep5Data();
    if(returnList5.size() != 0)
    {
        int returnList5Row = (int)returnList5.size();
        double Matrix51 [returnList5Row][2];
        for(int i =0;i<returnList5Row;i++)
        {
            Matrix51[i][0] = returnList5[i].lowerBoundValue;
            Matrix51[i][1] = returnList5[i].upperBoundValue;
        }
        double Matrix51_OVER [returnList5Row*2];
        int Matrix51_row_flag=0;
        int Matrix51_col_flag=0;
        for(int i =0;i<returnList5Row*2;i++)
        {
            Matrix51_OVER[i]=Matrix51[Matrix51_row_flag][Matrix51_col_flag];
            Matrix51_row_flag++;
            if(Matrix51_row_flag == returnList5Row)
            {
                Matrix51_row_flag=0;
                Matrix51_col_flag++;
            }
        }
        vector<Entity_Step6_1> returnList61 = sqlite.queryStep6_1Data();
        if(returnList61.size()!=0)
        {
            int  returnList61Row = (int)returnList61[(returnList61.size()-1)].row.toInt()+1;
            int  returnList61col = (int)returnList61[(returnList61.size()-1)].qualityParameterName.toInt()+1;
            double Matrix61 [returnList61Row][returnList61col];
            for(int i =0;i<returnList61.size();i++)
            {
                Matrix61[returnList61[i].row.toInt()][returnList61[i].qualityParameterName.toInt()] = returnList61[i].value;
            }
            double Matrix61_OVER[returnList61Row*returnList61col];
            int Matrix61_row_flag=0;
            int Matrix61_col_flag=0;
            for(int i=0;i<returnList61Row*returnList61col;i++)
            {
                Matrix61_OVER[i]=Matrix61[Matrix61_row_flag][Matrix61_col_flag];
                Matrix61_row_flag++;
                if(Matrix61_row_flag == returnList61Row)
                {
                    Matrix61_row_flag=0;
                    Matrix61_col_flag++;
                }
            }
            vector<Entity_Step7_1> returnList71 = sqlite.queryStep7_1Data();
            if(returnList71.size()!=0)
            {
                int  returnList71Row = (int)returnList71[(returnList71.size()-1)].QualityParameterName.toInt()+1;
                qDebug()<<"row"<<returnList71Row;
                int  returnList71col = (int)returnList71[(returnList71.size()-1)].valueExpectation.toInt()+1;
                qDebug()<<"column"<<returnList71col;
                double Matrix711 [returnList71Row][returnList71col],Matrix7111 [returnList71.size()];
                double Matrix712 [returnList71Row][returnList71col],Matrix7121 [returnList71.size()];
                for(int i =0;i<returnList71.size();i++)
                {
                    Matrix711[returnList71[i].QualityParameterName.toInt()][returnList71[i].valueExpectation.toInt()] = returnList71[i].valuequalityResult;
                    Matrix712[returnList71[i].QualityParameterName.toInt()][returnList71[i].valueExpectation.toInt()] = returnList71[i].Evalue;
                    Matrix7111[i]=returnList71[i].valuequalityResult;
                    Matrix7121[i]=returnList71[i].Evalue;
                }
                double Matrix711_OVER[returnList71Row*returnList71col];
                double Matrix712_OVER[returnList71Row*returnList71col];
                int Matrix71_row_flag=0;
                int Matrix71_col_flag=0;
                for(int i=0;i<returnList71Row*returnList71col;i++)
                {
                    Matrix711_OVER[i]=Matrix711[Matrix71_row_flag][Matrix71_col_flag];
                    Matrix712_OVER[i]=Matrix712[Matrix71_row_flag][Matrix71_col_flag];
                    Matrix71_row_flag++;
                    if(Matrix71_row_flag == returnList71Row)
                    {
                        Matrix71_row_flag=0;
                        Matrix71_col_flag++;
                    }
                }

                // Matrix61 over
                vector<Entity_Step7_2> returnList72 = sqlite.queryStep7_2Data();
                if(returnList72.size()!=0)
                {
                    int  returnList72Row = (int)returnList72[(returnList72.size()-1)].qualityParameterNameRow.toInt()+1;
                    int  returnList72col = (int)returnList72[(returnList72.size()-1)].qualityParameterNameRank.toInt()+1;
                    double Matrix721[returnList72Row][returnList72col];
                    double Matrix722[returnList72Row][returnList72col];
                    for(int i =0;i<returnList72.size();i++)
                    {
                        Matrix721[returnList72[i].qualityParameterNameRow.toInt()][returnList72[i].qualityParameterNameRank.toInt()]
                                = returnList72[i].valueQualityType.toDouble();
                        Matrix722[returnList72[i].qualityParameterNameRow.toInt()][returnList72[i].qualityParameterNameRank.toInt()]
                                = returnList72[i].BValue;
                    }
                    double Matrix721_OVER[returnList72Row*returnList72col];
                    double Matrix722_OVER[returnList72Row*returnList72col];
                    int Matrix72_row_flag=0;
                    int Matrix72_col_flag=0;
                    for(int i=0;i<returnList72Row*returnList72col;i++)
                    {
                        Matrix721_OVER[i]=Matrix721[Matrix72_row_flag][Matrix72_col_flag];
                        Matrix722_OVER[i]=Matrix722[Matrix72_row_flag][Matrix72_col_flag];
                        Matrix72_row_flag++;
                        if(Matrix72_row_flag == returnList72Row)
                        {
                            Matrix72_row_flag=0;
                            Matrix72_col_flag++;
                        }
                    }
                    //Matrix721_OVER ==>step721
                    //Matrix722_OVER ==>step722
                    mxArray *matrixA = mxCreateDoubleMatrix(returnList5Row,2,mxREAL);//定义数组，行，列，double类型
                    memcpy((void *)mxGetPr(matrixA),(void *)Matrix51_OVER,sizeof(Matrix51_OVER));

                    mxArray *matrixB = mxCreateDoubleMatrix(returnList61Row,returnList61col,mxREAL);//定义数组，行，列，double类型
                    memcpy((void *)mxGetPr(matrixB),(void *)Matrix61_OVER,sizeof(Matrix61_OVER));

                    mxArray *matrixE = mxCreateDoubleMatrix(returnList72Row,returnList72col,mxREAL);//定义数组，行，列，double类型
                    memcpy((void *)mxGetPr(matrixE),(void *)Matrix721_OVER,sizeof(Matrix721_OVER));

                    mxArray *matrixF = mxCreateDoubleMatrix(returnList72Row,returnList72col,mxREAL);//定义数组，行，列，double类型
                    memcpy((void *)mxGetPr(matrixF),(void *)Matrix722_OVER,sizeof(Matrix722_OVER));


                    qDebug()<<"start"<<endl;

                    mxArray *matrixC = mxCreateDoubleMatrix(returnList71Row,returnList71col,mxREAL);//定义数组，行，列，double类型
                    memcpy((void *)mxGetPr(matrixC),(void *)Matrix711_OVER,sizeof(Matrix711_OVER));
                    mxArray *matrixD = mxCreateDoubleMatrix(returnList71Row,returnList71col,mxREAL);//定义数组，行，列，double类型
                    memcpy((void *)mxGetPr(matrixD),(void *)Matrix712_OVER,sizeof(Matrix712_OVER));

                    mxArray *matrixResult = mxCreateDoubleMatrix(returnList71Row*2,(returnList5Row*2+2),mxREAL);//定义数组，行，列，double类型

                    Pcom_mlfStep7 pcom_mlfStep7 = (Pcom_mlfStep7)mylib.resolve("mlfMatStep7");
                    if(pcom_mlfStep7)
                    {
                        pcom_mlfStep7(1,&matrixResult,matrixA,matrixB,matrixC,matrixD,matrixE,matrixF);
                        double * pr = mxGetPr(matrixResult);
                        double result [returnList71col][returnList5Row*2+2];
                        int rowFlag =0;
                        int colFlag =0;

                        for(int i=0;i<returnList71col*(returnList5Row*2+2);i++)
                        {
                            result[rowFlag][colFlag] = pr[i];
                            rowFlag++;
                            if(rowFlag == returnList71col)
                            {
                                colFlag++;
                                rowFlag=0;
                            }
                        }
                        QString aa;
                        sqlite.deleteStep7_3Data();
                        vector<Entity_Step1>returnList1 = sqlite.queryStep1Data();
                         vector<Entity_Step4_2>returnList4_2 = sqlite.queryStep4_2Data();
                        int xxx=0;
                        QStringList StrList;

                        for (int i=0;i<returnList5Row;i++) {
                            StrList.push_back(returnList4_2[i].chooseQualityParameterName+"主值");
                        }
                        StrList.push_back("常数主值");
                        for (int i=0;i<returnList5Row;i++) {
                            StrList.push_back(returnList4_2[i].chooseQualityParameterName+"展值");
                        }
                        StrList.push_back("常数展值");
                        for(int i =0;i<returnList71col;i++)
                        {
                            for(int j=0;j<returnList5Row*2+2;j++){

                                QString valueExpectationColumn = returnList1[i].valueIndexName;
                               // sqlite.saveStep7_3Table(valueExpectationRow,valueExpectationColumn,result[i][j]);
                                 sqlite.saveStep7_3Table(QString::number(i),QString::number(j),result[i][j]);
                            }
                            xxx++;
                        }

                    }
                     qDebug()<<"Finish Step7"<<endl;
                        qDebug()<<"Finish Step7"<<endl;
                size_t M,N;int aNOE;double* p;double i;
                   qDebug() << "  Step7out" << endl;

                    M = mxGetM(matrixResult);                   //M为矩阵行数   （size_t == unsigned int64）
                     N = mxGetN(matrixResult);                   //N为矩阵列数
                     aNOE = mxGetNumberOfElements(matrixResult);   //统计矩阵元素个数
                    qDebug() << "矩阵a的行列值分别是: " << M << "和" << N << endl;
                    qDebug() << "矩阵a的元素个数是: " << aNOE << endl;
                     i= 1;
                     p = mxGetPr(matrixResult);              //实部指针
                    while (p != nullptr && i <= aNOE)       //打印各个元素
                    {
                        qDebug() << "第" << i << "个是：" << *p++ << endl;
                        i++;
                    }




                    qDebug() << "step51" << endl;
                     M = mxGetM(matrixA);                   //M为矩阵行数   （size_t == unsigned int64）
                     N = mxGetN(matrixA);                   //N为矩阵列数
                     aNOE = mxGetNumberOfElements(matrixA);   //统计矩阵元素个数
                    qDebug() << "矩阵a的行列值分别是: " << M << "和" << N << endl;
                    qDebug() << "矩阵a的元素个数是: " << aNOE << endl;
                     i = 1;
                    p = mxGetPr(matrixA);              //实部指针
                    while (p != nullptr && i <= aNOE)       //打印各个元素
                    {
                        qDebug() << "第" << i << "个是：" << *p++ << endl;
                        i++;
                    }



                    qDebug() << "step61" << endl;
                     M = mxGetM(matrixB);                   //M为矩阵行数   （size_t == unsigned int64）
                     N = mxGetN(matrixB);                   //N为矩阵列数
                     aNOE = mxGetNumberOfElements(matrixB);   //统计矩阵元素个数
                    qDebug() << "矩阵a的行列值分别是: " << M << "和" << N << endl;
                    qDebug() << "矩阵a的元素个数是: " << aNOE << endl;
                     i = 1;
                    p = mxGetPr(matrixB);              //实部指针
                    while (p != nullptr && i <= aNOE)       //打印各个元素
                    {
                        qDebug() << "第" << i << "个是：" << *p++ << endl;
                        i++;
                    }

                    qDebug() << "step711" << endl;
                     M = mxGetM(matrixC);                   //M为矩阵行数   （size_t == unsigned int64）
                     N = mxGetN(matrixC);                   //N为矩阵列数
                     aNOE = mxGetNumberOfElements(matrixC);   //统计矩阵元素个数
                    qDebug() << "矩阵a的行列值分别是: " << M << "和" << N << endl;
                    qDebug() << "矩阵a的元素个数是: " << aNOE << endl;
                     i = 1;
                    p = mxGetPr(matrixC);              //实部指针
                    while (p != nullptr && i <= aNOE)       //打印各个元素
                    {
                        qDebug() << "第" << i << "个是：" << *p++ << endl;
                        i++;
                    }

                    qDebug() << "step712" << endl;
                     M = mxGetM(matrixD);                   //M为矩阵行数   （size_t == unsigned int64）
                     N = mxGetN(matrixD);                   //N为矩阵列数
                     aNOE = mxGetNumberOfElements(matrixD);   //统计矩阵元素个数
                    qDebug() << "矩阵a的行列值分别是: " << M << "和" << N << endl;
                    qDebug() << "矩阵a的元素个数是: " << aNOE << endl;
                     i = 1;
                    p = mxGetPr(matrixD);              //实部指针
                    while (p != nullptr && i <= aNOE)       //打印各个元素
                    {
                        qDebug() << "第" << i << "个是：" << *p++ << endl;
                        i++;
                    }

                    qDebug() << "step721" << endl;
                     M = mxGetM(matrixE);                   //M为矩阵行数   （size_t == unsigned int64）
                     N = mxGetN(matrixE);                   //N为矩阵列数
                     aNOE = mxGetNumberOfElements(matrixE);   //统计矩阵元素个数
                    qDebug() << "矩阵a的行列值分别是: " << M << "和" << N << endl;
                    qDebug() << "矩阵a的元素个数是: " << aNOE << endl;
                     i = 1;
                    p = mxGetPr(matrixE);              //实部指针
                    while (p != nullptr && i <= aNOE)       //打印各个元素
                    {
                        qDebug() << "第" << i << "个是：" << *p++ << endl;
                        i++;
                    }

                    qDebug() << "step722" << endl;
                     M = mxGetM(matrixF);                   //M为矩阵行数   （size_t == unsigned int64）
                     N = mxGetN(matrixF);                   //N为矩阵列数
                     aNOE = mxGetNumberOfElements(matrixF);   //统计矩阵元素个数
                    qDebug() << "矩阵a的行列值分别是: " << M << "和" << N << endl;
                    qDebug() << "矩阵a的元素个数是: " << aNOE << endl;
                     i = 1;
                    p = mxGetPr(matrixF);              //实部指针
                    while (p != nullptr && i <= aNOE)       //打印各个元素
                    {
                        qDebug() << "第" << i << "个是：" << *p++ << endl;
                        i++;
                    }
                }
            }

        }

    }
    return true;
}













