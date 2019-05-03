#include "step9_4.h"
#include "ui_step9_4.h"
#include "sqlite.h"
#include <QString>
#include "excelengine.h"
#include "matlabfunction.h"
#include <QFileDialog>

Step9_4::Step9_4(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Step9_4)
{
    ui->setupUi(this);
    setWindowTitle(tr("TableWidget"));
    ui->qTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->qTableWidget->setSelectionBehavior(QAbstractItemView::SelectColumns);
    ui->qTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->qTableWidget->setStyleSheet("selection-background-color:grey");

    Sqlite sqlite;
    sqlite.connect();
    vector<Entity_Step8>returnList = sqlite.queryStep8Data();
    int tableColumn = returnList.size()+1;
    int RowNum = 1;
    QStringList  HStrList;
    HStrList<<"关键度";
    for(int i =0;i<returnList.size();i++)
    {
        QString vExpectation = returnList[i].QualityParameters;
        qDebug()<<"Step9_2::vExpectation"<<vExpectation;
        HStrList.push_back(vExpectation);
    }
    ui->qTableWidget->setRowCount(0);
    ui->qTableWidget->setColumnCount(tableColumn);
    ui->qTableWidget->setHorizontalHeaderLabels(HStrList);
    ui->qTableWidget->setWindowTitle("QTableWidget");
    ui->qTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->qTableWidget->setSelectionBehavior(QAbstractItemView::SelectColumns);
    ui->qTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->qTableWidget->setStyleSheet("selection-background-color:grey");
    ui->qTableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);//设置水平滚动条
    ui->qTableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);//设置垂直滚动条

}

Step9_4::~Step9_4()
{
    delete ui;
}
void Step9_4::on_pushButton_clicked()
{
    int cols=ui->qTableWidget->columnCount();
    int rows=ui->qTableWidget->rowCount();
    ui->qTableWidget->insertRow(rows);
    for(int i=0;i<cols;i++)
    {
        ui->qTableWidget->setItem(rows,i,new QTableWidgetItem(""));
    }
    ui->qTableWidget->selectRow(rows);
}
void Step9_4::on_pushButton_2_clicked()
{
    qDebug()<<"on_pushButton_2_clicked";
    QTableWidgetItem * item = ui->qTableWidget->currentItem();
    if(item==Q_NULLPTR)return;
    ui->qTableWidget->removeRow(item->row());
}
void Step9_4::on_pushButton_3_clicked()
{
    QExcelEngine excelEngine=*new QExcelEngine();

   QString filename="0";// = QFileDialog::getSaveFileName(this, tr("Save as..."), "../datafile", tr("EXCEL files (*.xls *.xlsx);;HTML-Files (*.txt);;"));
   if(filename.isEmpty())
       return;
  // QFile::copy("/1.xlsx", filename);

   bool b = excelEngine.Open2(filename, 1, false); //flase为不显示窗体
   if(b == false)
   {
       QMessageBox::information(this, "excel提示", "文件打开失败");
       return;
   }

   //清空表格之前的所有内容
   excelEngine.ClearAllData(" ");
   excelEngine.Close();
   //打开数据库，并保存数据
   excelEngine.Open(filename, 1, false);
   excelEngine.SaveDataFrTable(ui->qTableWidget);
   excelEngine.Close();

   QMessageBox::information(this, "excel提示", "导出成功");
}
void Step9_4::on_pushButton_4_clicked()
{
    QMessageBox::StandardButton rb = QMessageBox::information(this, "warning", "从excel文件中导入数据将会覆盖之前所有内容，\n确定导入吗？",
                             QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

    if(rb == QMessageBox::Yes)
    {
       //从Excel中将表格导入到TableWidget
      QExcelEngine excelEngine=*new QExcelEngine();

       QString m_fileName = QFileDialog::getOpenFileName(this, tr("select file"), "../datafile/", tr("*.xls *.xlsx"));
        if(m_fileName.isEmpty())
            return;

       bool b = excelEngine.Open(m_fileName, 1, false); //flase为不显示窗体
        if(b == false)
        {
            QMessageBox::information(this, "excel提示", "文件打开失败");
            return;
        }
        excelEngine.ReadDataToTable(ui->qTableWidget);
        excelEngine.Close();
   QMessageBox::information(this, "excel提示", "导入成功");
}
}
void Step9_4::on_pushButton_5_clicked()
{
    qDebug()<<"Step9_4::on_pushButton_5_clicked";
    QExcelEngine excelEngine = *new QExcelEngine();

    excelEngine.ClearAllData("");

    excelEngine.Step9_4SaveData(ui->qTableWidget);

    MatlabFunction matlabFunction = *new MatlabFunction();
    matlabFunction.mlfStep9(ui->qTableWidget);

    QMessageBox::information(this, "end", "end");
    excelEngine.Close();
}


