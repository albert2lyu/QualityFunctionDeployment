#include "Step1_1.h"
#include "ui_Step1_1.h"
//#include "excelengine.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDebug>
#include <QComboBox>
#include <QFileDialog>

Step1_1::Step1_1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Step1_1)
{
        ui->setupUi(this);
        qDebug()<<"Step1_1:ui";

        setWindowTitle(tr("TableWidget"));//设置对话框的标题
        ui->qTableWidget->setWindowTitle("QTableWidget");
        ui->qTableWidget->verticalHeader()->setVisible(false);//纵向表头可视化
        ui->qTableWidget->horizontalHeader()->setVisible(true);//横向表头可视化
        ui->qTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//设置表格选择方式：设置表格为整行选中
        //ui->qTableWidget->setSelectionBehavior(QAbstractItemView::SelectColumns);//设置表格选择方式：设置表格为整列选中
        ui->qTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);//选择目标方式
        ui->qTableWidget->setStyleSheet("selection-background-color:grey");//设置选中颜色：粉色
        ui->qTableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);//设置水平滚动条
        ui->qTableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);//设置垂直滚动条
        //设置列标签
        QStringList HStrList;
        HStrList.push_back(QString("价值指标名称"));
        HStrList.push_back(QString("操作符"));
        HStrList.push_back(QString("期望值"));
        HStrList.push_back(QString("单位"));
        int HlableCnt = HStrList.count();
        ui->qTableWidget->setRowCount(0);//
        ui->qTableWidget->setColumnCount(HlableCnt);
        //设置列标签
        ui->qTableWidget->setHorizontalHeaderLabels(HStrList);
        QComboBox *comBox = new QComboBox();
        comBox->addItem("");
        comBox->addItem("");

    }

Step1_1::~Step1_1()
{
    delete ui;
}

void Step1_1::on_pushButton_clicked()
{
    qDebug()<<"on_pushButton_clicked";
//    QAbstractItemModel *model = ui->tableWidget->model();
//     model->insertRow(model->rowCount());
    int cols=ui->qTableWidget->columnCount();
    int rows=ui->qTableWidget->rowCount();
    qDebug()<<rows;
    ui->qTableWidget->insertRow(rows);
    for(int i=0;i<cols;i++)
    {
       // ui->qTableWidget->setItem(rows,i,new QTableWidgetItem("new"+QString::number(rows)));
        ui->qTableWidget->setItem(rows,i,new QTableWidgetItem(""));
    }
    ui->qTableWidget->selectRow(rows);
}

void Step1_1::on_pushButton_2_clicked()
{
    qDebug()<<"on_pushButton_2_clicked";
    QTableWidgetItem * item = ui->qTableWidget->currentItem();
    if(item==Q_NULLPTR)return;
    ui->qTableWidget->removeRow(item->row());
}
//////
/// \brief Step1_1::on_pushButton_3_clicked
///
void Step1_1::on_pushButton_3_clicked()
{
    qDebug()<<"on_pushButton_3_clicked";
      ui->qTableWidget->clear();
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
//将文件数据导入表格
void Step1_1::on_pushButton_4_clicked()
{
    qDebug()<<"on_pushButton_4_clicked";
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

///////
/// \brief Step1_1::on_pushButton_5_clicked
/// 将数据存储到数据库中
void Step1_1::on_pushButton_5_clicked()
{
   qDebug()<<"on_pushButton_5_clicked";
   QExcelEngine excelEngine=*new QExcelEngine();
   //清空表格之前的所有内容
   excelEngine.ClearAllData(" ");

   //Step1 save data 打开数据库，并保存数据
   excelEngine.Step1SaveData(ui->qTableWidget);
   //----------------------------
   excelEngine.Close();

  QMessageBox::information(this, "excel提示", "保存成功");

}














