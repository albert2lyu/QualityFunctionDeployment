#include "Step7_1.h"
#include "ui_Step7_1.h"
//#include "excelengine.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDebug>
#include <QComboBox>
#include <QFileDialog>
#include <sqlite.h>
#include"matlabfunction.h"
Step7_1::Step7_1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Step7_1)
{
    ui->setupUi(this);

    Sqlite sqlite;
    sqlite.connect();
    vector<Entity_Step1>returnList1 = sqlite.queryStep1Data();
    vector<Entity_Step4_2>returnList5 = sqlite.queryStep4_2Data();
    qDebug()<<"Step2::ui::returnList.size()::"<<returnList1.size();qDebug()<<"Step5::ui::returnList.size()::"<<returnList5.size();
    int tableColumn =returnList1.size();
    int tableColumn2 =returnList5.size();
    int ColumnNum=tableColumn*2;
    QStringList HStrList;
    QStringList VStrList;
    int RowNum=returnList5.size();
    for (int i=0;i<RowNum;i++) {

        VStrList.push_back(returnList5[i].chooseQualityParameterName);
    }
    for(int i=0;i<tableColumn;i++){
    HStrList.push_back(returnList1[i].valueIndexName+"中心值");
    HStrList.push_back(returnList1[i].valueIndexName+"展值");
    }

     for(int i=0;i<tableColumn;i++){
     HStrList.push_back(returnList1[i].valueIndexName+"中心值");
     HStrList.push_back(returnList1[i].valueIndexName+"展值");
     }

    setWindowTitle(tr("TableWidget"));//设置对话框的标题
    ui->qTableWidget->setColumnCount(ColumnNum);//设置列数
    ui->qTableWidget->setRowCount(RowNum);//设置行数
    ui->qTableWidget->setHorizontalHeaderLabels(HStrList);
    ui->qTableWidget->setVerticalHeaderLabels(VStrList);
    ui->qTableWidget->setWindowTitle("QTableWidget");

    ui->qTableWidget->verticalHeader()->setVisible(true);//纵向表头可视化
    //ui->qTableWidget->horizontalHeader()->setVisible(false); //隐藏行表头
    ui->qTableWidget->horizontalHeader()->setVisible(true);//横向表头可视化
    //ui->tableWidget->setShowGrid(false);//隐藏栅格
    //ui->qTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置编辑方式：禁止编辑表格
    ui->qTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//设置表格选择方式：设置表格为整行选中
    //ui->qTableWidget->setSelectionBehavior(QAbstractItemView::SelectColumns);//设置表格选择方式：设置表格为整列选中
    ui->qTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);//选择目标方式
    ui->qTableWidget->setStyleSheet("selection-background-color:grey");//设置选中颜色：粉色
    setStyleSheet(QString::fromUtf8("border:1px solid black"));

    for(int rows=0;rows<RowNum;rows++)
    {
        for(int columns=0;columns<ColumnNum;columns++)
        {
            if(columns==0)
            {
                ui->qTableWidget->setItem(rows,columns,new QTableWidgetItem(""));
            }
            else if(columns==1)
            {
                ui->qTableWidget->setItem(rows,columns,new QTableWidgetItem(""));
            }
            else if(columns==2)
            {
                ui->qTableWidget->setItem(rows,columns,new QTableWidgetItem(""));
            }
            else
            {
                ui->qTableWidget->setItem(rows,columns,new QTableWidgetItem(""));
            }
        }
    }
    for(int rows=0;rows<RowNum;rows++)
    {
        for(int columns=0;columns<ColumnNum;columns++)
        {
            ui->qTableWidget->setColumnWidth(columns,705/ColumnNum);//hangkuan
            ui->qTableWidget->setRowHeight(rows,335/RowNum);//列宽
            //ui->qTableWidget->horizontalHeader()->setResizeMode(QHeaderView::Strtch);  //使行列头自适应宽度，所有列平均分来填充空白部分
            ui->qTableWidget->item(rows,columns)->setTextAlignment(Qt::AlignCenter);//居中显示
            ui->qTableWidget->item(rows,columns)->setBackgroundColor(QColor(255,255,255));//设置前景颜色
            ui->qTableWidget->item(rows,columns)->setTextColor(QColor(0,0,0));//设置文本颜色
            ui->qTableWidget->item(rows,columns)->setFont(QFont("Helvetica"));//设置字体为黑体
        }
    }
    //ui->qTableWidget->setSpan(2, 2,2 ,1);//合并单元格
    //ui->qTableWidget->setItem(2, 2, new QTableWidgetItem(QIcon("E:\\Qt_Project\\QTableWidget\\1.jpg"), "路飞"));//插入图片
    ui->qTableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);//设置水平滚动条
    ui->qTableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);//设置垂直滚动条
    //设置行和列的大小设为与内容相匹配（如果设置了宽高就不要用了）
    //ui->qTableWidget->resizeColumnsToContents();
    //ui->qTableWidget->resizeRowsToContents();

    QString strText = ui->qTableWidget->item(1, 1)->text();//获取单元格的内容

}
Step7_1::~Step7_1()
{
    delete ui;
}
//    void MainWindow::on_tableWidget_currentItemChanged(QTableWidgetItem *current, QTableWidgetItem *previous)
//{

//    if(previous!=Q_NULLPTR)//背景颜色修改
//    {
//        previous->setBackgroundColor(Qt::transparent);
//    }
//    if(current==Q_NULLPTR)return;
//    current->setBackgroundColor(Qt::blue);
//}

void Step7_1::on_pushButton_clicked()
{
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

void Step7_1::on_pushButton_2_clicked()
{
    QTableWidgetItem * item = ui->qTableWidget->currentItem();
    if(item==Q_NULLPTR)return;
    ui->qTableWidget->removeRow(item->row());
}
//将表格数据写入文件
void Step7_1::on_pushButton_3_clicked()
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
//将文件数据导入表格
void Step7_1::on_pushButton_4_clicked()
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


void Step7_1::on_pushButton_5_clicked()
{

    QExcelEngine excelEngine=*new QExcelEngine();

    excelEngine.Step7_1SaveData(ui->qTableWidget);


    excelEngine.Close();

}


