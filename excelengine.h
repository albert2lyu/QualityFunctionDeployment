#ifndef _EXCELENGINE_H_
#define _EXCELENGINE_H_
#include <QFile>
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include <QTableWidget>
#include <QAxObject>

class QExcelEngine
{
public:
    QExcelEngine();
    QExcelEngine(QString xlsFile);
    ~QExcelEngine();

public:
    bool Open(int nSheet, bool visible);
    bool Open(QString xlsFile, int nSheet, bool visible);
    bool Open2(int nSheet, bool visible);
    bool Open2(QString xlsFile, int nSheet, bool visible);
    void Save();
    void Close();
    bool SaveDataFrTable(QTableWidget *tableWidget);
    bool ReadDataToTable(QTableWidget *tableWidget);
    QVariant GetCellData(int row, int column);
    bool SetCellData(int row, int column, QVariant data);
    void ClearAllData(QString strData);
    void Clear();
    bool IsOpen();
    bool IsValid();
    int GetRowCount() const;
    int GetColumnCount() const;
    bool Step1SaveData(QTableWidget *tableWidget);
    bool Step1QueryData(QTableWidget *tableWidget);
    bool Step2SaveData1(QTableWidget *tableWidget);
    bool Step2QueryData1(QTableWidget *tableWidget);
    bool Step7QueryData(QTableWidget *tableWidget);
    bool Step6QueryData(QTableWidget *tableWidget);
    bool Step2SaveData2(QTableWidget *tableWidget);
    bool Step2MatBasicsss(QTableWidget *tableWidget);
    bool Step3_2SaveData(QTableWidget *tableWidget);
    bool Step3_3SaveData(QTableWidget *tableWidget);
    bool Step3_4SaveData(QTableWidget *tableWidget);
    bool Step4_1SaveData(QTableWidget *tableWidget);
    bool Step4_2SaveData(QTableWidget *tableWidget,QTableWidget *tableWidget2);
    bool Step5SaveData(QTableWidget *tableWidget);
    bool Step6SaveData(QTableWidget *tableWidget);
    bool Step6_1SaveData(QTableWidget *tableWidget);
    bool Step6_2SaveData(QTableWidget *tableWidget);
    bool Step7_1SaveData(QTableWidget *tableWidget);
    bool Step7_2SaveData(QTableWidget *tableWidget);
    bool Step10SaveData(QTableWidget *tableWidget);
    bool Step8SaveData(QTableWidget *tableWidget);
    bool Step8QueryData(QTableWidget *tableWidget);
    bool Step9_2SaveData(QTableWidget *tableWidget);
    bool Step9_3SaveData(QTableWidget *tableWidget);
    bool Step9_4SaveData(QTableWidget *tableWidget);
    bool Step10QueryData(QTableWidget *tableWidget);
    bool Step4QueryData(QTableWidget *tableWidget);
    bool Step5QueryData(QTableWidget *tableWidget);

private:
    QAxObject *pExcel;
    QAxObject *pWorkbooks;
    QAxObject *pWorkbook;
    QAxObject *pWorksheet;

    QString sXlsFile;

    int nRowCount;
    int nColumnCount;
    int nStartRow;
    int nStartColumn;
    int nCurrSheet;

    bool bIsVisible;
    bool bIsOpen;
    bool bIsValid;
    bool bIsANewFile;
    bool bIsSaveAlready;
};
#endif
