#include "Step10_1.h"
#include "ui_Step10_1.h"
//#include "excelengine.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDebug>
#include <QComboBox>
#include <QFileDialog>
#include "matlabfunction.h"
#include "sqlite.h"
#include<QVBoxLayout>
Step10_1::Step10_1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Step10_1)
{
    ui->setupUi(this);

    Sqlite sqlite;
    sqlite.connect();
    vector<Entity_Step4_2>returnList42 = sqlite.queryStep4_2Data();
    int ColumnNum =4;
    int RowNum=returnList42.size();
    setWindowTitle(tr("TableWidget"));//设置对话框的标题
        ui->qTableWidget->setColumnCount(ColumnNum);//设置列数
       ui->qTableWidget->setRowCount(RowNum);//设置行数
        ui->qTableWidget->setWindowTitle("QTableWidget");
        QStringList m_Header;
        m_Header<<QString("质量参数名称")<<QString("取值下界")<<QString("取值上界")<<QString("质量参数单位");
        ui->qTableWidget->setHorizontalHeaderLabels(m_Header);//添加横向表头
        ui->qTableWidget->verticalHeader()->setVisible(true);//纵向表头可视化
       ui->qTableWidget->horizontalHeader()->setVisible(true);//横向表头可视化
        ui->qTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//设置表格选择方式：设置表格为整行选中
        ui->qTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);//选择目标方式
        ui->qTableWidget->setStyleSheet("selection-background-color:grey");//设置选中颜色：粉色

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
                ui->qTableWidget->setColumnWidth(columns,306/ColumnNum);//hangkuan
            ui->qTableWidget->setRowHeight(rows,227/RowNum);//列宽
                //ui->qTableWidget->horizontalHeader()->setResizeMode(QHeaderView::Strtch);  //使行列头自适应宽度，所有列平均分来填充空白部分
                ui->qTableWidget->item(rows,columns)->setTextAlignment(Qt::AlignCenter);//居中显示
                ui->qTableWidget->item(rows,columns)->setBackgroundColor(QColor(255,255,255));//设置前景颜色
                ui->qTableWidget->item(rows,columns)->setTextColor(QColor(0,0,0));//设置文本颜色
                ui->qTableWidget->item(rows,columns)->setFont(QFont("Helvetica"));//设置字体为黑体
            }
        }
        ui->qTableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);//设置水平滚动条
        ui->qTableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);//设置垂直滚动条


    }

Step10_1::~Step10_1()
{
    delete ui;
}


void Step10_1::on_pushButton_clicked()
{
    int cols=ui->qTableWidget->columnCount();
    int rows=ui->qTableWidget->rowCount();
    qDebug()<<rows;
    ui->qTableWidget->insertRow(rows);
    for(int i=0;i<cols;i++)
    {
        ui->qTableWidget->setItem(rows,i,new QTableWidgetItem(""));
    }
    ui->qTableWidget->selectRow(rows);
}

void Step10_1::on_pushButton_2_clicked()
{
    QTableWidgetItem * item = ui->qTableWidget->currentItem();
    if(item==Q_NULLPTR)return;
    ui->qTableWidget->removeRow(item->row());
}
//将表格数据写入文件
void Step10_1::on_pushButton_3_clicked()
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
void Step10_1::on_pushButton_4_clicked()
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


//void Step10_1::on_pushButton_5_clicked()
//{

//   QExcelEngine excelEngine=*new QExcelEngine();

//  QString filename =  QDir::tempPath() + QDir::separator() +QCoreApplication::applicationName() + "Step10_1_temp" + "xls";
//  if(filename.isEmpty())
//      return;
//  QFile file(filename);
//       if(!file.open(QIODevice::WriteOnly|QIODevice::Text))
//       {
//        QMessageBox::critical(nullptr,"提示","无法创建文件");
//        return;

//        }
//       QTextStream out(&file);
//       out.flush();
//       file.close();
//  bool b = excelEngine.Open(filename, 1, false); //flase为不显示窗体
//  if(b == false)
//  {
//      QMessageBox::information(this, "excel提示", "文件打开失败");
//      return;
//  }

//  //清空表格之前的所有内容
//  excelEngine.ClearAllData(" ");
//  excelEngine.Close();
//  //打开数据库，并保存数据
//  excelEngine.Open(filename, 1, false);
//  excelEngine.SaveDataFrTable(ui->qTableWidget);
//  excelEngine.Close();

//  QMessageBox::information(this, "excel提示", "保存成功");

//}
void Step10_1::on_pushButton_5_clicked()
{

    QExcelEngine excelEngine=*new QExcelEngine();

    //excelEngine.Step6_2SaveData(ui->qTableWidget);


    MatlabFunction matlabFunction = *new MatlabFunction();
    matlabFunction.matStep10(ui->qTableWidget);

  excelEngine.Close();

   //ui->qTableWidget->horizontalHeader()->setVisible(true);//横向表头可视化
  Sqlite sqlite;
  sqlite.connect();
  vector<Entity_Step10>returnList = sqlite.queryStep10Data();
  vector<Entity_Step5>returnList5 = sqlite.queryStep5Data();
            int tableColumn =returnList.size();
  vector<Entity_Step4_2>returnList42 = sqlite.queryStep4_2Data();
            int RowNum42 = returnList42.size();

            for(int i =0;i<returnList.size()/2;i++)
            {
                QString  valueIndexName = returnList42[i].chooseQualityParameterName;
                ui->qTableWidget->setItem(i,0,new QTableWidgetItem(valueIndexName));
                double vExpectation = returnList[2*i].outputValue;
                ui->qTableWidget->setItem(i,1,new QTableWidgetItem(QString::number(vExpectation,'d',3)));
                double retuC =returnList[2*i+1].outputValue;
                ui->qTableWidget->setItem(i,2,new QTableWidgetItem(QString::number(retuC,'d',3)));
                QString  Unitsum = returnList5[i].Unit;
                ui->qTableWidget->setItem(i,3,new QTableWidgetItem(Unitsum));
            }



    QMessageBox::information(this, "excel提示", "保存成功");

}

