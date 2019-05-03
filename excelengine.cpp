#include "excelengine.h"
#include "qt_windows.h"
#include "sqlite.h"
#include "entity_step1.h"
#include <QHeaderView>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDebug>
#include <QComboBox>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QButtonGroup>
#include <QRadioButton>
#include <QCheckBox>

QExcelEngine::QExcelEngine()
{
    pExcel     = nullptr;
    pWorkbooks = nullptr;
    pWorkbook  = nullptr;
    pWorksheet = nullptr;

    sXlsFile     = "";
    nRowCount    = 0;
    nColumnCount = 0;
    nStartRow    = 0;
    nStartColumn = 0;

    bIsOpen     = false;
    bIsValid    = false;
    bIsANewFile = false;
    bIsSaveAlready = false;

    HRESULT r = OleInitialize(nullptr);
    if (r != S_OK && r != S_FALSE)
    {
        qDebug("Qt: Could not initialize OLE (error %x)", (unsigned int)r);
    }
}

QExcelEngine::QExcelEngine(QString xlsFile)
{
    pExcel     = nullptr;
    pWorkbooks = nullptr;
    pWorkbook  = nullptr;
    pWorksheet = nullptr;

    sXlsFile     = xlsFile;
    nRowCount    = 0;
    nColumnCount = 0;
    nStartRow    = 0;
    nStartColumn = 0;

    bIsOpen     = false;
    bIsValid    = false;
    bIsANewFile = false;
    bIsSaveAlready = false;

    HRESULT r = OleInitialize(nullptr);
    if (r != S_OK && r != S_FALSE)
    {
        qDebug("Qt: Could not initialize OLE (error %x)", (unsigned int)r);
    }
}

QExcelEngine::~QExcelEngine()
{
    if ( bIsOpen )
    {
        //析构前，先保存数据，然后关闭workbook
        Close();
    }
    OleUninitialize();
}

/**
  *@brief 打开sXlsFile指定的excel报表
  *@return true : 打开成功
  *        false: 打开失败
  */
bool QExcelEngine::Open(int nSheet, bool visible)
{
    if ( bIsOpen )
    {
        Close();
    }

    nCurrSheet = nSheet;
    bIsVisible = visible;

    if ( nullptr == pExcel )
    {
        pExcel = new QAxObject("Excel.Application");        //连接Excel控件
        if ( pExcel )
        {
            bIsValid = true;
        }
        else
        {
            bIsValid = false;
            bIsOpen  = false;
            return bIsOpen;
        }

        pExcel->dynamicCall("SetVisible(bool)", bIsVisible);    //bIsVisible 是否显示窗体
        pExcel->setProperty("DisplayAlerts", false);            //不显示任何警告信息
        pWorkbooks = pExcel->querySubObject("WorkBooks"); //获取工作簿
    }

    if ( !bIsValid )
    {
        bIsOpen  = false;
        return bIsOpen;
    }

    if ( sXlsFile.isEmpty() )
    {
        bIsOpen  = false;
        return bIsOpen;
    }

    //如果指向的文件不存在，则需要新建一个
    QFile f(sXlsFile);
    if (!f.exists())
    {
        bIsANewFile = true;
    }
    else
    {
        bIsANewFile = false;
    }

    if (!bIsANewFile)
    {
        pWorkbook = pWorkbooks->querySubObject("Open(QString, QVariant)", sXlsFile, QVariant(0)); //打开xls对应的工作簿
        //  pWorkbooks->dynamicCall("Add");                       //添加一个新的工作薄
        //  pWorkbook  = pExcel->querySubObject("ActiveWorkBook"); //新建一个xls
    }
    else
    {
        pWorkbooks->dynamicCall("Add");                       //添加一个新的工作薄
        pWorkbook  = pExcel->querySubObject("ActiveWorkBook"); //新建一个xls
    }

    pWorksheet = pWorkbook->querySubObject("WorkSheets(int)", nCurrSheet);//打开第一个sheet

    //至此已打开，开始获取相应属性
    QAxObject *usedrange = pWorksheet->querySubObject("UsedRange");//获取该sheet的使用范围对象
    QAxObject *rows = usedrange->querySubObject("Rows");
    QAxObject *columns = usedrange->querySubObject("Columns");

    //因为excel可以从任意行列填数据而不一定是从0,0开始，因此要获取首行列下标
    nStartRow    = usedrange->property("Row").toInt();    //第一行的起始位置
    nStartColumn = usedrange->property("Column").toInt(); //第一列的起始位置

    nRowCount    = rows->property("Count").toInt();       //获取行数
    nColumnCount = columns->property("Count").toInt();    //获取列数

    bIsOpen  = true;
    return bIsOpen;
}
bool QExcelEngine::Open2(int nSheet, bool visible)
{
    if ( bIsOpen )
    {
        Close();
    }

    nCurrSheet = nSheet;
    bIsVisible = visible;

    if ( nullptr == pExcel )
    {
        pExcel = new QAxObject("Excel.Application");        //连接Excel控件
        if ( pExcel )
        {
            bIsValid = true;
        }
        else
        {
            bIsValid = false;
            bIsOpen  = false;
            return bIsOpen;
        }

        pExcel->dynamicCall("SetVisible(bool)", bIsVisible);    //bIsVisible 是否显示窗体
        pExcel->setProperty("DisplayAlerts", false);            //不显示任何警告信息
        pWorkbooks = pExcel->querySubObject("WorkBooks"); //获取工作簿
    }

    if ( !bIsValid )
    {
        bIsOpen  = false;
        return bIsOpen;
    }

    if ( sXlsFile.isEmpty() )
    {
        bIsOpen  = false;
        return bIsOpen;
    }

    //如果指向的文件不存在，则需要新建一个
    QFile f(sXlsFile);
    if (!f.exists())
    {
        bIsANewFile = true;
    }
    else
    {
        bIsANewFile = false;
    }

    if (!bIsANewFile)
    {
        //pWorkbook = pWorkbooks->querySubObject("Open(QString, QVariant)", sXlsFile, QVariant(0)); //打开xls对应的工作簿
        pWorkbooks->dynamicCall("Add");                       //添加一个新的工作薄
        pWorkbook  = pExcel->querySubObject("ActiveWorkBook"); //新建一个xls
    }
    else
    {
        pWorkbooks->dynamicCall("Add");                       //添加一个新的工作薄
        pWorkbook  = pExcel->querySubObject("ActiveWorkBook"); //新建一个xls
    }

    pWorksheet = pWorkbook->querySubObject("WorkSheets(int)", nCurrSheet);//打开第一个sheet

    //至此已打开，开始获取相应属性
    QAxObject *usedrange = pWorksheet->querySubObject("UsedRange");//获取该sheet的使用范围对象
    QAxObject *rows = usedrange->querySubObject("Rows");
    QAxObject *columns = usedrange->querySubObject("Columns");

    //因为excel可以从任意行列填数据而不一定是从0,0开始，因此要获取首行列下标
    nStartRow    = usedrange->property("Row").toInt();    //第一行的起始位置
    nStartColumn = usedrange->property("Column").toInt(); //第一列的起始位置

    nRowCount    = rows->property("Count").toInt();       //获取行数
    nColumnCount = columns->property("Count").toInt();    //获取列数

    bIsOpen  = true;
    return bIsOpen;
}

/**
  *@brief Open()的重载函数
  */
bool QExcelEngine::Open(QString xlsFile, int nSheet, bool visible)
{
    sXlsFile = xlsFile;
    nCurrSheet = nSheet;
    bIsVisible = visible;

    return Open(nCurrSheet,bIsVisible);
}
bool QExcelEngine::Open2(QString xlsFile, int nSheet, bool visible)
{
    sXlsFile = xlsFile;
    nCurrSheet = nSheet;
    bIsVisible = visible;

    return Open2(nCurrSheet,bIsVisible);
}

/**
  *@brief 保存表格数据，把数据写入文件
  */
void QExcelEngine::Save()
{
    if ( pWorkbook )
    {
        if (bIsSaveAlready)
        {
            return ;
        }

        if (!bIsANewFile)
        {
            pWorkbook->dynamicCall("Save()");
        }
        else //如果该文档是新建出来的，则使用另存为COM接口
        {
            // pWorkbook->dynamicCall("SaveAs (const QString&,int,const QString&,const QString&,bool,bool)",sXlsFile,56,QString(""),QString(""),false,false);
            pWorkbook->dynamicCall("SaveAs(const QString&)", sXlsFile);
        }

        bIsSaveAlready = true;
    }
}

/**
  *@brief 关闭前先保存数据，然后关闭当前Excel COM对象，并释放内存
  */
void QExcelEngine::Close()
{
    //关闭前先保存数据
    //    Save();

    if ( pExcel && pWorkbook )
    {
        pWorkbook->dynamicCall("Close(bool)", true);
        pExcel->dynamicCall("Quit()");
        delete pExcel;
        pExcel = nullptr;
        bIsOpen     = false;
        bIsValid    = false;
        bIsANewFile = false;
        bIsSaveAlready = true;
    }
}

/**
  *@brief 把tableWidget中的数据保存到excel中
  *@param tableWidget : 指向GUI中的tablewidget指针
  *@return 保存成功与否 true : 成功
  *                  false: 失败
  */
bool QExcelEngine::SaveDataFrTable(QTableWidget *tableWidget)
{
    if ( nullptr == tableWidget )
    {
        return false;
    }
    if ( !bIsOpen )
    {
        return false;
    }

    int tableR = tableWidget->rowCount();
    int tableC = tableWidget->columnCount();

    //获取表头写做第一行
    for (int i=0; i<tableC; i++)
    {
        if ( tableWidget->horizontalHeaderItem(i) != nullptr )
        {
            this->SetCellData(1, i+1, tableWidget->horizontalHeaderItem(i)->text());
        }
    }

    //写数据
    for (int i=0; i<tableR; i++)
    {
        for (int j=0; j<tableC; j++)
        {
            if ( tableWidget->item(i,j) != nullptr )
            {
                this->SetCellData(i+2, j+1, tableWidget->item(i,j)->text());
            }
        }
    }

    //保存
    Save();

    return true;
}
///////////////////////////////////////////////////////////////
/// \brief QExcelEngine::Step1SaveData Step1保存数据
/// \param tableWidget
/// \return
///
bool QExcelEngine::Step1SaveData(QTableWidget *tableWidget)
{
    qDebug()<<"QExcelEngine::Step1SaveData";
    Sqlite sqlite;
    sqlite.deleteStep1Data();
    int tableR = tableWidget->rowCount();
    QString valueExpectation;
    QString valueOperator;
    QString expectations;
    QString stakeholders;
    for (int i=0; i<tableR; i++)
    {
        if (tableWidget->item(i,0) != nullptr)
            valueExpectation = tableWidget->item(i,0)->data(Qt::DisplayRole).toString();
        if (tableWidget->item(i,1) != nullptr)
            valueOperator = tableWidget->item(i,1)->data(Qt::DisplayRole).toString();
        if (tableWidget->item(i,2) != nullptr)
            expectations = tableWidget->item(i,2)->data(Qt::DisplayRole).toString();
        if (tableWidget->item(i,3) != nullptr)
            stakeholders = tableWidget->item(i,3)->data(Qt::DisplayRole).toString();
        sqlite.saveStep1Table(valueExpectation,valueOperator,expectations,stakeholders);
    }
    return true;
}
/////////////
/// \brief QExcelEngine::Step1QueryData  Step1显示数据
/// \return
///
bool QExcelEngine::Step1QueryData(QTableWidget *tableWidget)
{
    qDebug()<<"QExcelEngine::Step1QueryData";
    Sqlite sqlite;
    vector<Entity_Step1>returnList = sqlite.queryStep1Data();
    //先把table的内容清空
    int tableColumn = tableWidget->columnCount();
    tableWidget->clear();
    for (int n=0; n<tableColumn; n++)
    {
        tableWidget->removeColumn(0);
    }
    tableWidget->setColumnCount(4); //设置列数
    QStringList header;
    header<<"价值期望名称"<<"操作符"<<"期望值"<<"单位";
    tableWidget->setHorizontalHeaderLabels(header);

    for(int i =0;i<returnList.size();i++)
    {

        tableWidget->setItem(i,0,new QTableWidgetItem(returnList[i].valueIndexName));
        tableWidget->setItem(i,1,new QTableWidgetItem(returnList[i].valueOperator));
        tableWidget->setItem(i,2,new QTableWidgetItem(returnList[i].expectations));
        tableWidget->setItem(i,3,new QTableWidgetItem(returnList[i].stakeholders));
    }
    return true;
}


bool QExcelEngine::Step7QueryData(QTableWidget *tableWidget)
{
    qDebug()<<"QExcelEngine::Step1QueryData";
    Sqlite sqlite;
    vector<Entity_Step1>returnList1 = sqlite.queryStep1Data();
    vector<Entity_Step4_2>returnList5 = sqlite.queryStep4_2Data();
    int  RowNum=returnList5.size()*2+2;
    int ColumnNum=returnList1.size();
    vector<Entity_Step7_3>returnList = sqlite.queryStep7_3Data();
    qDebug()<<returnList.size();
    QStringList HStrList;
    QStringList VStrList;
    for (int i=0;i<returnList5.size();i++) {
        HStrList.push_back(returnList5[i].chooseQualityParameterName+"主值");
    }

    HStrList.push_back("常数主值");
    for (int i=0;i<returnList5.size();i++) {
        HStrList.push_back(returnList5[i].chooseQualityParameterName+"展值");
    }
    HStrList.push_back("常数展值");
    for(int i=0;i<ColumnNum;i++){
        VStrList.push_back(returnList1[i].valueIndexName);
    }
    //先把table的内容清空
    int tableColumn = tableWidget->columnCount();
    tableWidget->clear();
    for (int n=0; n<tableColumn; n++)
    {
        tableWidget->removeColumn(0);
    }
    tableWidget->setColumnCount(ColumnNum); //设置列数
    tableWidget->setColumnCount(RowNum);
    tableWidget->setHorizontalHeaderLabels(HStrList);
    tableWidget->setVerticalHeaderLabels(VStrList);
    int x=0;
    for(int i =0;i<RowNum;i++)
    {
        for(int j=0;j<ColumnNum;j++){
            qDebug()<<returnList[x].valuequalityResult<<endl;
            tableWidget->setItem(j,i,new QTableWidgetItem(QString::number(returnList[x].valuequalityResult)));x++;
        }
    }
    x=0;
    return true;
}

bool QExcelEngine::Step6QueryData(QTableWidget *tableWidget)
{
    qDebug()<<"QExcelEngine::Step1QueryData";
    Sqlite sqlite;
    vector<Entity_Step4_2>returnList5 = sqlite.queryStep4_2Data();
    int  RowNum=returnList5.size(),ColumnNum=returnList5.size()+1;
    vector<Entity_Step6_3>returnList = sqlite.queryStep6_3Data();
    qDebug()<<returnList.size();
    QStringList HStrList,VStrList;
    for (int i=0;i<returnList5.size();i++) {
        HStrList.push_back(returnList5[i].chooseQualityParameterName);
        VStrList.push_back(returnList5[i].chooseQualityParameterName);
    }
     VStrList.push_back("常数值");
    //先把table的内容清空
    int tableColumn = tableWidget->columnCount();
    tableWidget->clear();
    for (int n=0; n<tableColumn; n++)
    {
        tableWidget->removeColumn(0);
    }
    tableWidget->setColumnCount(ColumnNum); //设置列数
    tableWidget->setRowCount(RowNum);
    tableWidget->setHorizontalHeaderLabels(VStrList);
    tableWidget->setVerticalHeaderLabels(HStrList);
    int x=0;
    for(int i =0;i<RowNum;i++)
    {
        for(int j=0;j<ColumnNum;j++){
            tableWidget->setItem(i,j,new QTableWidgetItem(QString::number(returnList[x].autocorrelationResult)));x++;
        }
    }
    x=0;
    return true;
}


///////////////
/// \brief QExcelEngine::Step2SaveData1
/// \param tableWidget
/// \return
///
bool QExcelEngine::Step2SaveData1(QTableWidget *tableWidget)
{
    qDebug()<<"QExcelEngine::Step2SaveData1";
    Sqlite sqlite;
    int tableR  = tableWidget->rowCount();
    QString valueIndexName;
    QString relativeImportanceRating;
    for (int i=0; i<tableR; i++)
    {
        if (tableWidget->item(i,0) != nullptr)
            valueIndexName = tableWidget->item(i,0)->data(Qt::DisplayRole).toString();
        if (tableWidget->item(i,1) != nullptr)
            relativeImportanceRating = tableWidget->item(i,1)->data(Qt::DisplayRole).toString();
        sqlite.saveStep2Table(valueIndexName,relativeImportanceRating);
    }
    return true;
}
/////////////
/// \brief QExcelEngine::Step2QueryData1
/// \param tableWidget
/// \return
///
bool QExcelEngine::Step2QueryData1(QTableWidget *tableWidget)
{
    qDebug()<<"QExcelEngine::Step2QueryData1";
    Sqlite sqlite;
    vector<Entity_Step2>returnList = sqlite.queryStep2Data();
    //先把table的内容清空
    int tableColumn = tableWidget->columnCount();
    tableWidget->clear();
    for (int n=0; n<tableColumn; n++)
    {
        tableWidget->removeColumn(0);
    }
    tableWidget->setColumnCount(2); //设置列数
    QStringList header;
    header<<"价值期望名称"<<"相对重要评级";
    tableWidget->setHorizontalHeaderLabels(header);
    for(int i =0;i<returnList.size();i++)
    {
        tableWidget->setItem(i,0,new QTableWidgetItem(returnList[i].valueExpectation));
        double retuC =returnList[i].relativeImportanceRating.toDouble();
        tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(retuC,'d',3)));
    }
    return true;
}
bool QExcelEngine::Step4QueryData(QTableWidget *tableWidget)
{
    qDebug()<<"QExcelEngine::Step4QueryData";
    Sqlite sqlite;
    vector<Entity_Step4_2>returnList = sqlite.queryStep4_2Data();
    //先把table的内容清空
    int tableColumn = tableWidget->columnCount();
    tableWidget->clear();
    for (int n=0; n<tableColumn; n++)
    {
        tableWidget->removeColumn(0);
    }
    tableWidget->setColumnCount(1); //设置列数
    QStringList header;
    header<<"质量参数名称";
    tableWidget->setHorizontalHeaderLabels(header);
    for(int i =0;i<returnList.size();i++)
    {    QString  valueIndexName = returnList[i].chooseQualityParameterName;
        tableWidget->setItem(i,0,new QTableWidgetItem(valueIndexName));

    }
    return true;
}
bool QExcelEngine::Step5QueryData(QTableWidget *tableWidget)
{
    qDebug()<<"QExcelEngine::Step5QueryData";
    Sqlite sqlite;
    vector<Entity_Step5>returnList = sqlite.queryStep5Data();
    //先把table的内容清空
    int tableColumn = tableWidget->columnCount();
    tableWidget->clear();
    for (int n=0; n<tableColumn; n++)
    {
        tableWidget->removeColumn(0);
    }
    tableWidget->setColumnCount(5); //设置列数
    QStringList header;
    header<<"质量参数名称"<<"数据类型"<<"取值下界"<<"取值上界"<<"质量参数单位";
    tableWidget->setHorizontalHeaderLabels(header);
    for(int i =0;i<returnList.size();i++)
    {    QString  valueIndexName1 = returnList[i].qualityParameterName;
        tableWidget->setItem(i,0,new QTableWidgetItem(valueIndexName1));
        QString  valueIndexName2 = returnList[i].dataType;
        tableWidget->setItem(i,1,new QTableWidgetItem(valueIndexName2));
      double  valueIndexName3 = returnList[i].lowerBoundValue;
      tableWidget->setItem(i,2,new QTableWidgetItem(QString::number(valueIndexName3,'d',3)));
       double  valueIndexName4 = returnList[i].upperBoundValue;
      tableWidget->setItem(i,3,new QTableWidgetItem(QString::number(valueIndexName4,'d',3)));
      QString  valueIndexName5 = returnList[i].Unit;
      tableWidget->setItem(i,4,new QTableWidgetItem(valueIndexName5));

    }
    return true;
}
////////////////
/// \brief QExcelEngine::Step2SaveData2
/// \param tableWidget
/// \return
///
bool QExcelEngine::Step2SaveData2(QTableWidget *tableWidget)
{
    qDebug()<<"QExcelEngine::Step2SaveData2";
    Sqlite sqlite = * new Sqlite();
    for(int i = 0;i<tableWidget->horizontalHeader()->count();i++)
    {
        for(int j =0;j<tableWidget->verticalHeader()->count();j++)
        {
            QString valueExpectationRow = tableWidget->horizontalHeaderItem(i)->data(Qt::DisplayRole).toString();
            QString valueExpectationRank = tableWidget->verticalHeaderItem(j)->data(Qt::DisplayRole).toString();
            QString relativeImportanceRating = tableWidget->item(i,j)->data(Qt::DisplayRole).toString();
            if( valueExpectationRow!=nullptr && valueExpectationRank!=nullptr && relativeImportanceRating!=nullptr)
            {
                sqlite.saveStep2_2Table(valueExpectationRow,valueExpectationRank,relativeImportanceRating);
            }
        }
    }

    return true;
}
bool QExcelEngine::Step3_2SaveData(QTableWidget *tableWidget)
{
    qDebug()<<"QExcelEngine::Step3_2SaveData";
    Sqlite sqlite = * new Sqlite();;
    sqlite.deleteStep3_2Data();
    int tableR = tableWidget->rowCount();
    int tableC = tableWidget->columnCount();
    for(int i=0;i<tableR;i++)
    {
        for(int j=1; j<tableC; j++)
        {
            QString competitiveEvaluation = tableWidget->item(i,j)->data(Qt::DisplayRole).toString();
            qDebug()<<"QExcelEngine::Step3_2SaveData::competitiveEvaluation"<<competitiveEvaluation;
            if(competitiveEvaluation != nullptr)
            {
                sqlite.saveStep3_2Table(QString::number(i),QString::number(j-1),competitiveEvaluation);
            }
        }
    }
    return true;
}
bool QExcelEngine::Step3_3SaveData(QTableWidget *tableWidget)
{
    qDebug()<<"QExcelEngine::Step3_3SaveData";
    Sqlite sqlite = * new Sqlite();
    sqlite.deleteStep3_3Data();
    int tableR = tableWidget->rowCount();
    qDebug()<<"QExcelEngine::Step3_3SaveData::tableR"<<tableR;
    int tableC = tableWidget->columnCount();
    qDebug()<<"QExcelEngine::Step3_3SaveData::tableC"<<tableC;
    for(int i=0;i<tableR;i++)
    {
        for(int j=1; j<tableC; j++)
        {
            QString expectedRank = tableWidget->item(i,j)->data(Qt::DisplayRole).toString();
            qDebug()<<"QExcelEngine::Step3_3SaveData::expectedRank"<<expectedRank;
            if(expectedRank != nullptr)
            {
                sqlite.saveStep3_3Table(QString::number(i),QString::number(j-1),expectedRank);
            }
        }
    }
    return true;
}
bool QExcelEngine::Step3_4SaveData(QTableWidget *tableWidget)
{
    qDebug()<<"QExcelEngine::Step3_4SaveData";
    Sqlite sqlite = * new Sqlite();
    sqlite.deleteStep3_4Data();
    int tableR = tableWidget->rowCount();
    qDebug()<<"QExcelEngine::Step3_4SaveData::tableR"<<tableR;
    int tableC = tableWidget->columnCount();
    qDebug()<<"QExcelEngine::Step3_4SaveData::tableC"<<tableC;
    for(int i=0;i<tableR;i++)
    {
        for(int j=1; j<tableC; j++)
        {
            QString criticality = tableWidget->item(i,j)->data(Qt::DisplayRole).toString();
            qDebug()<<"QExcelEngine::Step3_3SaveData::expectedRank"<<criticality;
            if(criticality != nullptr)
            {
                sqlite.saveStep3_4Table(QString::number(i),QString::number(j-1),criticality);
            }
        }
    }
    return true;
}
bool QExcelEngine::Step4_1SaveData(QTableWidget *tableWidget)
{
    qDebug()<<"QExcelEngine::Step4_1SaveData";
    int row = tableWidget->rowCount();
    qDebug()<<"row::"<<row;
    int col = tableWidget->columnCount();
    qDebug()<<"col::"<<col;
    Sqlite sqlite;
    sqlite.deleteStep4_1Data();
    for(int i =0;i<row;i++)
    {
        for(int j =0;j<col;j++)
        {
            QWidget *widget = tableWidget->cellWidget(i,j);
            QList<QCheckBox *> rad = widget->findChildren<QCheckBox *>();
            if(rad.count()!=0)
            {
                if(rad.at(0)->isChecked())
                {
                    qDebug()<<"QExcelEngine::Step4_1SaveData::rad"<<rad.at(0)->objectName();
                    QString valueIndexName = rad.at(0)->objectName();
                    sqlite.saveStep4_1Table(valueIndexName);
                }
            }
        }
    }

    return true;
}
bool QExcelEngine::Step4_2SaveData(QTableWidget *tableWidget,QTableWidget *tableWidget2)
{
    qDebug()<<"QExcelEngine::Step4_2SaveData";
    int row = tableWidget->rowCount();
    int col = tableWidget->columnCount();
    int row2 = tableWidget2->rowCount();
    Sqlite sqlite;
    sqlite.deleteStep4_2Data();
    for(int i =0;i<row;i++)
    {
        for(int j =0;j<col;j++)
        {
            QWidget *widget = tableWidget->cellWidget(i,j);
            QList<QCheckBox *> rad = widget->findChildren<QCheckBox *>();
            if(rad.count()!=0)
            {
                if(rad.at(0)->isChecked())
                {
                    qDebug()<<"QExcelEngine::Step4_1SaveData::rad"<<rad.at(0)->objectName();
                    QString chooseQualityParameterName = rad.at(0)->objectName();
                    sqlite.saveStep4_2Table(chooseQualityParameterName);
                }
            }
        }
    }
    qDebug()<<row2;
    for(int i =0;i<row2;i++)
    {
        QString chooseQualityParameterName =  tableWidget2->item(i,0)->data(Qt::DisplayRole).toString();
        sqlite.saveStep4_2Table(chooseQualityParameterName);

    }
    return true;
}
bool QExcelEngine::Step5SaveData(QTableWidget *tableWidget)
{
    qDebug()<<"QExcelEngine::Step5SaveData";
    int row = tableWidget->rowCount();
    Sqlite sqlite;
    sqlite.deleteStep5Data();
 for(int i=0;i<row;i++)
    {
        QString qualityParameterName = tableWidget->item(i,0)->data(Qt::DisplayRole).toString();
        QString Unit=tableWidget->item(i,2)->data(Qt::DisplayRole).toString();
         qDebug()<<"QExcelEngine::Step5SaveData::{}"<<qualityParameterName;
        QString w;
         QString ww;
          QString www;
           w=tableWidget->item(i,1)->data(Qt::DisplayRole).toString();
                 if (w.left(1) == "(")
             qDebug()<<w.remove(0, 1);
                 if (w.right(1) == ")")
                     qDebug()<<w.remove(w.length() - 1, 1);
                 if (w.left(1) == "{")
             qDebug()<<w.remove(0, 1);
                 if (w.right(1) == "}")
                     qDebug()<<w.remove(w.length() - 1, 1);
          ww= w.section(',', 0, 0);
          www=w.section(',', -1,-1);

//          qDebug()<<"QExcelEngine::ww"<<ww;
//          qDebug()<<"QExcelEngine::www"<<www;

         if (w[0]=="{")
      {  QString dataType = "离散型";
             double  lowerBoundValue = ww.toDouble();
             double   upperBoundValue= www.toDouble();
             if(qualityParameterName != nullptr && dataType != nullptr)
             {
                 sqlite.saveStep5Table(qualityParameterName,dataType,lowerBoundValue,upperBoundValue,Unit);
             }
        }
        else {
             QString dataType = "连续型";
             double  lowerBoundValue = ww.toDouble();
             double   upperBoundValue= www.toDouble();
             if(qualityParameterName != nullptr && dataType != nullptr)
             {
                 sqlite.saveStep5Table(qualityParameterName,dataType,lowerBoundValue,upperBoundValue,Unit);
             }
        }


    }
    return true;
}
//for(int i=0;i<row;i++)
//{
//    QWidget *widget = tableWidget->cellWidget(i,1);
//    QList<QComboBox *> rad = widget->findChildren<QComboBox *>();
//    qDebug()<<rad.count();
//    QString qualityParameterName = tableWidget->item(i,0)->data(Qt::DisplayRole).toString();
//    QString dataType =  rad.at(0)->currentText();
//    double  upperBoundValue = tableWidget->item(i,2)->data(Qt::DisplayRole).toString().toDouble();
//    double  lowerBoundValue = tableWidget->item(i,3)->data(Qt::DisplayRole).toString().toDouble();
//    if(qualityParameterName != nullptr && dataType != nullptr)
//    {
//        sqlite.saveStep5Table(qualityParameterName,dataType,upperBoundValue,lowerBoundValue);
//    }
//}
//return true;

//}
bool QExcelEngine::Step6_1SaveData(QTableWidget *tableWidget)
{
    qDebug()<<"QExcelEngine::Step6_1SaveData";
    int row = tableWidget->rowCount();
    Sqlite sqlite;
    sqlite.deleteStep6_1Data();
    for(int i=0;i<tableWidget->horizontalHeader()->count();i++)
    {
        QString valueExpectationRow = tableWidget->horizontalHeaderItem(i)->data(Qt::DisplayRole).toString();
        for(int j=0;j<row;j++)
        {
            double value = tableWidget->item(j,i)->data(Qt::DisplayRole).toString().toDouble();
            if(valueExpectationRow != nullptr)
            {
                sqlite.saveStep6_1Table(QString::number(j),QString::number(i),value);
            }
        }
    }
    return true;
}
bool QExcelEngine::Step6_2SaveData(QTableWidget *tableWidget)
{
    qDebug()<<"QExcelEngine::Step6_2SaveData";
    Sqlite sqlite;
    sqlite.deleteStep6_2Data();
    int row = tableWidget->rowCount();
    int col = tableWidget->columnCount();
    qDebug()<<"QExcelEngine::Step6_2SaveData::row"<<row;
    qDebug()<<"QExcelEngine::Step6_2SaveData::col"<<col;
    for(int i =0;i<row;i++)
    {
        for(int j =0;j<col;j++)
        {
            QWidget *widget = tableWidget->cellWidget(i,j);
            QList<QComboBox *> rad = widget->findChildren<QComboBox *>();
            if(rad.count() !=0)
            {
                QString valueQualityType = rad.at(0)->currentText();
                QString valueQualityType2;
                if(valueQualityType=="积极正相关")
                {
                     valueQualityType2 ="1";
                } else  if(valueQualityType=="消极正相关"){ valueQualityType2 ="2";}
                else  if(valueQualityType=="消极负相关"){ valueQualityType2 ="3";}
                else  if(valueQualityType=="积极负相关"){ valueQualityType2 ="4";}
                else  if(valueQualityType=="正相关"){ valueQualityType2 ="5";}
                else  if(valueQualityType=="负相关"){ valueQualityType2 ="6";}
                else { valueQualityType2 ="0";}
                double BValue = rad.at(1)->currentText().toDouble();
                sqlite.saveStep6_2Table(QString::number(i),QString::number(j),valueQualityType2,BValue);
            }

        }
    }
    return true;
}
//bool QExcelEngine::Step7_1SaveData(QTableWidget *tableWidget)
//{
//    qDebug()<<"QExcelEngine::Step7_1SaveData";
//    int row = tableWidget->rowCount();
//    Sqlite sqlite;
//    sqlite.connect();
//    sqlite.deleteStep7_1Data();
//    for(int i=0;i<tableWidget->horizontalHeader()->count();i++)
//    {
//        QString valueExpectationRow = tableWidget->horizontalHeaderItem(i)->data(Qt::DisplayRole).toString();
//        for(int j=0;j<row;j++)
//        {
//            double value = tableWidget->item(j,i)->data(Qt::DisplayRole).toString().toDouble();
//             double value2 = tableWidget->item(j,i)->data(Qt::DisplayRole).toString().toDouble();
//            if(valueExpectationRow != nullptr)
//            {
//                sqlite.saveStep6_1Table(QString::number(j),QString::number(i),value);
//            }
//        }
//    }
//    return true;
//}
bool QExcelEngine::Step7_1SaveData(QTableWidget *tableWidget)
{
    qDebug()<<"QExcelEngine::Step7_1SaveData";
    int row = tableWidget->rowCount();
    int column = tableWidget->horizontalHeader()->count();
    qDebug()<<row<<column;
    Sqlite sqlite;
    sqlite.deleteStep7_1Data();
    vector<Entity_Step1>returnList1 = sqlite.queryStep1Data();//价值
    vector<Entity_Step4_2>returnList5 = sqlite.queryStep4_2Data();//质量
    //int Cvalue[row][column],Evalue[row][column];
    //int x=0;
    for(int j=0;j<row;j++)
    {
        for(int i=0;i<column;i+=2)
        {
            // QString valueExpectationColumn = tableWidget->verticalHeaderItem(i)->data(Qt::DisplayRole).toString();
            qDebug()<<"QExcelEngine::Step7_1SaveData222";
            double value=tableWidget->item(j,i)->data(Qt::DisplayRole).toString().toDouble();
            double value2=tableWidget->item(j,i+1)->data(Qt::DisplayRole).toString().toDouble();
            qDebug()<<"QExcelEngine::Step7_1SaveData222";
            sqlite.saveStep7_1Table(QString::number(j),QString::number(i/2),value,value2);
            qDebug()<<"QExcelEngine::Step7_1SaveData333";
           // x++;
        }
      //   x=0;
    }

    return true;
}
bool QExcelEngine::Step7_2SaveData(QTableWidget *tableWidget)
{
    qDebug()<<"QExcelEngine::Step7_2SaveData";
    Sqlite sqlite;
    sqlite.deleteStep7_2Data();
    int row = tableWidget->rowCount();
    int col = tableWidget->columnCount();
    qDebug()<<"QExcelEngine::Step7_2SaveData::row"<<row;
    qDebug()<<"QExcelEngine::Step7_2SaveData::col"<<col;
    for(int i =0;i<row;i++)
    {
        for(int j =0;j<col;j++)
        {
            QWidget *widget = tableWidget->cellWidget(i,j);
            QList<QComboBox *> rad = widget->findChildren<QComboBox *>();
            if(rad.count() !=0)
            {

                QString valueQualityType = rad.at(0)->currentText();
                QString valueQualityType2;
                if(valueQualityType=="积极正相关")
                {

                   valueQualityType2 ="1";
                } else  if(valueQualityType=="消极正相关"){ valueQualityType2 ="2";}
                else  if(valueQualityType=="消极负相关"){ valueQualityType2 ="3";}
                else  if(valueQualityType=="积极负相关"){ valueQualityType2 ="4";}
                else  if(valueQualityType=="正相关"){ valueQualityType2 ="5";}
                else  if(valueQualityType=="负相关"){ valueQualityType2 ="6";}
                else { valueQualityType2 ="0";}
                double BValue = rad.at(1)->currentText().toDouble();
                sqlite.saveStep7_2Table(QString::number(i),QString::number(j),valueQualityType2,BValue);

            }
        }
    }
    return true;
}
bool QExcelEngine::Step8QueryData(QTableWidget *tableWidget)
{
    qDebug()<<"QExcelEngine::Step8QueryData";
    Sqlite sqlite;
    vector<Entity_Step8>returnList8 = sqlite.queryStep8Data();
    //先把table的内容清空
    int tableColumn = tableWidget->columnCount();
    tableWidget->clear();
    for (int n=0; n<tableColumn; n++)
    {
        tableWidget->removeColumn(0);
    }
    tableWidget->setColumnCount(2); //设置列数
    QStringList header;
    header<<"质量参数名称"<<"相对重要评级";
    tableWidget->setHorizontalHeaderLabels(header);
    for(int i =0;i<returnList8.size();i++)
    {
        tableWidget->setItem(i,0,new QTableWidgetItem(returnList8[i].QualityParameters));
        double retuC =returnList8[i].relativeImportanceRating;
        tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(retuC,'d',3)));
    }
    return true;
}
bool QExcelEngine::Step9_2SaveData(QTableWidget *tableWidget)
{
    qDebug()<<"QExcelEngine::Step9_2SaveData";
    Sqlite sqlite = * new Sqlite();
    sqlite.deleteStep9_2Data();
    int tableR = tableWidget->rowCount();
    int tableC = tableWidget->columnCount();
    for(int i=0;i<tableR;i++)
    {
        for(int j=1; j<tableC; j++)
        {
            QString competitiveEvaluation = tableWidget->item(i,j)->data(Qt::DisplayRole).toString();
            qDebug()<<"QExcelEngine::Step9_2SaveData::competitiveEvaluation"<<competitiveEvaluation;
            if(competitiveEvaluation != nullptr)
            {
                sqlite.saveStep9_2Table(QString::number(i),QString::number(j-1),competitiveEvaluation);
            }
        }
    }
    return true;
}
bool QExcelEngine::Step9_3SaveData(QTableWidget *tableWidget)
{
    qDebug()<<"QExcelEngine::Step9_3SaveData";
    Sqlite sqlite = * new Sqlite();
    sqlite.deleteStep9_3Data();
    int tableR = tableWidget->rowCount();
    qDebug()<<"QExcelEngine::Step9_3SaveData::tableR"<<tableR;
    int tableC = tableWidget->columnCount();
    qDebug()<<"QExcelEngine::Step9_3SaveData::tableC"<<tableC;
    for(int i=0;i<tableR;i++)
    {
        for(int j=1; j<tableC; j++)
        {
            QString expectedRank = tableWidget->item(i,j)->data(Qt::DisplayRole).toString();
            qDebug()<<"QExcelEngine::Step9_3SaveData::expectedRank"<<expectedRank;
            if(expectedRank != nullptr)
            {
                sqlite.saveStep9_3Table(QString::number(i),QString::number(j-1),expectedRank);
            }
        }
    }
    return true;
}
bool QExcelEngine::Step9_4SaveData(QTableWidget *tableWidget)
{
    qDebug()<<"QExcelEngine::Step9_4SaveData";
    Sqlite sqlite = * new Sqlite();
    sqlite.deleteStep9_4Data();
    int tableR = tableWidget->rowCount();
    qDebug()<<"QExcelEngine::Step9_4SaveData::tableR"<<tableR;
    int tableC = tableWidget->columnCount();
    qDebug()<<"QExcelEngine::Step9_4SaveData::tableC"<<tableC;
    for(int i=0;i<tableR;i++)
    {
        for(int j=1; j<tableC; j++)
        {
            QString criticality = tableWidget->item(i,j)->data(Qt::DisplayRole).toString();
            qDebug()<<"QExcelEngine::Step9_4SaveData::expectedRank"<<criticality;
            if(criticality != nullptr)
            {
                sqlite.saveStep9_4Table(QString::number(i),QString::number(j-1),criticality);
            }
        }
    }
    return true;
}
bool QExcelEngine::Step10QueryData(QTableWidget *tableWidget)
{
    qDebug()<<"QExcelEngine::Step10QueryData";
    Sqlite sqlite;
    vector<Entity_Step10>returnList10 = sqlite.queryStep10Data();
    //先把table的内容清空
    int  returnList10Row = (int)returnList10[(returnList10.size()-1)].QualityParameterName.toInt()+1;
 //   int  returnList62col = (int)returnList10[(returnList10.size()-1)].qualityParameterNameRank.toInt()+1;
    int tableColumn = tableWidget->columnCount();
    tableWidget->clear();
    for (int n=0; n<tableColumn; n++)
    {
        tableWidget->removeColumn(0);
    }
    tableWidget->setColumnCount(4); //设置列数
    QStringList header;
    header<<"质量参数名称"<<"取值下界"<<"取值上界"<<"质量参数单位";
    tableWidget->setHorizontalHeaderLabels(header);
   vector<Entity_Step5> returnlist = sqlite.queryStep5Data();
//    if( returnlist.size()!=0)
//    {
//        QStringList HStrList;
//        for(int i=0;i<returnlist.size();i++)
//        {
//            QString valueIndexName = returnlist[i].qualityParameterName;
//            HStrList.push_back(valueIndexName);
//        }
//         tableWidget->setVerticalHeaderLabels(HStrList); //设置行标签
//    }
    for(int i =0;i<returnList10Row;i++)
    {
        QString valueIndexName = returnlist[i].qualityParameterName;
        QString unitsum = returnlist[i].Unit;
        double retuC =returnList10[2*i].outputValue;
        double retuD =returnList10[2*i+1].outputValue;
        tableWidget->setItem(i,0,new QTableWidgetItem(valueIndexName));
        tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(retuC,'d',3)));
        tableWidget->setItem(i,2,new QTableWidgetItem(QString::number(retuD,'d',3)));
        tableWidget->setItem(i,3,new QTableWidgetItem(unitsum));
    }
    return true;
}
/**
  *@brief 从指定的xls文件中把数据导入到tableWidget中
  *@param tableWidget : 执行要导入到的tablewidget指针
  *@return 导入成功与否 true : 成功
  *                   false: 失败
  */
bool QExcelEngine::ReadDataToTable(QTableWidget *tableWidget)
{
    if ( nullptr == tableWidget )
    {
        return false;
    }

    //先把table的内容清空
    int tableColumn = tableWidget->columnCount();
    tableWidget->clear();
    for (int n=0; n<tableColumn; n++)
    {
        tableWidget->removeColumn(0);
    }

    int rowcnt    = nStartRow + nRowCount;
    int columncnt = nStartColumn + nColumnCount;

    //获取excel中的第一行数据作为表头
    QStringList headerList;
    for (int n = nStartColumn; n<columncnt; n++ )
    {
        QAxObject * cell = pWorksheet->querySubObject("Cells(int,int)", nStartRow, n);
        if ( cell )
        {
            headerList << cell->dynamicCall("Value2()").toString();
        }
    }

    //重新创建表头
    tableWidget->setColumnCount(nColumnCount);
    tableWidget->setHorizontalHeaderLabels(headerList);

    //插入新数据
    for (int i = nStartRow + 1, r = 0; i < rowcnt; i++, r++ )  //行
    {
        tableWidget->insertRow(r); //插入新行
        for (int j = nStartColumn, c = 0; j < columncnt; j++, c++ )  //列
        {
            QAxObject * cell = pWorksheet->querySubObject("Cells(int,int)", i, j );//获取单元格

            //在r新行中添加子项数据
            if ( cell )
            {
                tableWidget->setItem(r,c,new QTableWidgetItem(cell->dynamicCall("Value2()").toString()));
                tableWidget->item(r, c)->setTextAlignment(Qt::AlignCenter);
            }
        }
    }

    return true;
}

/**
  *@brief 获取指定单元格的数据
  *@param row : 单元格的行号
  *@param column : 单元格的列号
  *@return [row,column]单元格对应的数据
  */
QVariant QExcelEngine::GetCellData(int row, int column)
{
    QVariant data;

    QAxObject *cell = pWorksheet->querySubObject("Cells(int,int)",row,column);//获取单元格对象
    if ( cell )
    {
        data = cell->dynamicCall("Value2()");
    }

    return data;
}

/**
  *@brief 修改指定单元格的数据
  *@param row : 单元格的行号
  *@param column : 单元格指定的列号
  *@param data : 单元格要修改为的新数据
  *@return 修改是否成功 true : 成功
  *                   false: 失败
  */
bool QExcelEngine::SetCellData(int row, int column, QVariant data)
{
    bool op = false;

    QAxObject *cell = pWorksheet->querySubObject("Cells(int,int)",row,column);//获取单元格对象
    if ( cell )
    {
        QString strData = data.toString(); //excel 居然只能插入字符串和整型，浮点型无法插入
        cell->dynamicCall("SetValue(const QVariant&)",strData); //修改单元格的数据
        op = true;
    }
    else
    {
        op = false;
    }

    return op;
}

/**
 * @brief 清空整个Excel表格
 */
void QExcelEngine::ClearAllData(QString strData)
{
    for (int i=0; i<nStartRow+nRowCount; i++)
    {
        for (int j=0; j<nStartColumn+nColumnCount; j++)
        {
            this->SetCellData(i, j, strData);
        }
    }

    //保存
    Save();
}

/**
  *@brief 清空除报表之外的数据
  */
void QExcelEngine::Clear()
{
    sXlsFile     = "";
    nRowCount    = 0;
    nColumnCount = 0;
    nStartRow    = 0;
    nStartColumn = 0;
}

/**
  *@brief 判断excel是否已被打开
  *@return true : 已打开
  *        false: 未打开
  */
bool QExcelEngine::IsOpen()
{
    return bIsOpen;
}

/**
  *@brief 判断excel COM对象是否调用成功，excel是否可用
  *@return true : 可用
  *        false: 不可用
  */
bool QExcelEngine::IsValid()
{
    return bIsValid;
}

/**
  *@brief 获取excel的行数
  */
int QExcelEngine::GetRowCount() const
{
    return nRowCount;
}

/**
  *@brief 获取excel的列数
  */
int QExcelEngine::GetColumnCount() const
{
    return nColumnCount;
}
