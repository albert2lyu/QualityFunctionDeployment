#include "Step7_2.h"
#include "ui_Step7_2.h"
//#include "excelengine.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDebug>
#include <QComboBox>
#include <QFileDialog>
#include<matlabfunction.h>
#include <sqlite.h>
Step7_2::Step7_2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Step7_2)
{
ui->setupUi(this);
Sqlite sqlite;
sqlite.connect();
vector<Entity_Step2>returnList1 = sqlite.queryStep2Data();
vector<Entity_Step5>returnList5 = sqlite.queryStep5Data();
qDebug()<<"Step2::ui::returnList.size()::"<<returnList1.size();qDebug()<<"Step5::ui::returnList.size()::"<<returnList5.size();
int tableColumn =returnList1.size();
int tableColumn2 =returnList5.size();
int ColumnNum=tableColumn2;
int RowNum=tableColumn;
QStringList HStrList,HStrList2;
for(int i=0;i<ColumnNum;i++){
HStrList.push_back(returnList5[i].qualityParameterName);
}
for(int i=0;i<RowNum;i++){
HStrList2.push_back(returnList1[i].valueExpectation);
}
ui->qTableWidget->setColumnCount(ColumnNum);//设置列数
ui->qTableWidget->setRowCount(RowNum);//设置行数

ui->qTableWidget->setHorizontalHeaderLabels(HStrList);
ui->qTableWidget->setVerticalHeaderLabels(HStrList2);
setWindowTitle(tr("TableWidget"));//设置对话框的标题

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
// setStyleSheet(QString::fromUtf8("border:1px solid black"));

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



QVector<QComboBox*> Combox;
for(int i=0;i<ColumnNum*RowNum*2;i++)
{
    if(i%2==0)
    {
        QComboBox *tmp= new QComboBox();
        tmp->addItem("1");
        tmp->addItem("2");
        tmp->addItem("3");
        tmp->addItem("4");
        tmp->addItem("5");
        tmp->addItem("6");
        Combox.append(tmp);}
    else if(i%2==1)
    {
        QComboBox *tmp= new QComboBox();
        tmp->addItem("1");
        tmp->addItem("2");
        tmp->addItem("3");
        tmp->addItem("4");
        tmp->addItem("5");
        tmp->addItem("6");
        tmp->addItem("7");
        tmp->addItem("8");
        tmp->addItem("9");
        tmp->addItem("10");
        tmp->setCurrentIndex(4) ;
        Combox.append(tmp);
    }
}

QVector<QWidget*> ThreeCombox;
int ss=0;
for(int i=0;i<ColumnNum*RowNum;i++)
{
    QWidget *widget1 = new QWidget();
    widget1->setObjectName(QString::fromUtf8("widget1"));
    widget1->setGeometry(QRect(10, 8, 101, 31));
    QVBoxLayout  *verticalLayout = new QVBoxLayout(widget1) ;
    verticalLayout->setSpacing(0);
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
    verticalLayout->setContentsMargins(0, 0, 0, 0);
    for (int i=0;i<2;i++) {
        verticalLayout->addWidget(Combox.at(ss));ss++;
    }
    ThreeCombox.append(widget1);
}
int x=0;
for (int i=0;i<RowNum;i++) {
    for(int j=0;j<ColumnNum;j++)
    {
        ui->qTableWidget->setCellWidget(i,j,ThreeCombox.at(x));
        x++;
    }
}
x=0;

//ui->qTableWidget->setCellWidget(0,3,comBox);

        //ui->qTableWidget->removeColumn(0);//删除列
        //ui->qTableWidget->removeRow(0);//删除行
        //ui->qTableWidget->clear();//清空掉表格内所有内容，包括标题头
        //ui->qTableWidget->clearContents();//这个清空所有内容不包括标题头
    }

Step7_2::~Step7_2()
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

void Step7_2::on_pushButton_clicked()
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

void Step7_2::on_pushButton_2_clicked()
{
    QTableWidgetItem * item = ui->qTableWidget->currentItem();
    if(item==Q_NULLPTR)return;
    ui->qTableWidget->removeRow(item->row());
}
//将表格数据写入文件
void Step7_2::on_pushButton_3_clicked()
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
void Step7_2::on_pushButton_4_clicked()
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


void Step7_2::on_pushButton_5_clicked()
{

 /*  QExcelEngine excelEngine=*new QExcelEngine();

  QString filename =  QDir::tempPath() + QDir::separator() +QCoreApplication::applicationName() + "Step4_1_temp" + "xls";
  if(filename.isEmpty())
      return;
  QFile file(filename);
       if(!file.open(QIODevice::WriteOnly|QIODevice::Text))
       {
        QMessageBox::critical(nullptr,"提示","无法创建文件");
        return;

        }
       QTextStream out(&file);
       out.flush();
       file.close();
  bool b = excelEngine.Open(filename, 1, false); //flase为不显示窗体
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

  QMessageBox::information(this, "excel提示", "保存成功");
*/
    QExcelEngine excelEngine=*new QExcelEngine();

    excelEngine.Step7_2SaveData(ui->qTableWidget);


    MatlabFunction matlabFunction = *new MatlabFunction();
    matlabFunction.matStep7(ui->qTableWidget);

    excelEngine.Close();

}


