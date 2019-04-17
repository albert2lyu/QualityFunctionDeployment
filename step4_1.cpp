#include "Step4_1.h"
#include "ui_Step4_1.h"
//#include "excelengine.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDebug>
#include <QComboBox>
#include <QFileDialog>

Step4_1::Step4_1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Step4_1)
{
    ui->setupUi(this);
    int RowNum=6;
    int ColumnNum=5;
    setWindowTitle(tr("TableWidget"));//设置对话框的标题
    ui->qTableWidget->setColumnCount(ColumnNum);//设置列数
    ui->qTableWidget->setRowCount(RowNum);//设置行数
    //table->setRowCount(RowCount+1);
    //ui->qTableWidget->setRowCount(row_count+1); ;//设置行数
    ui->qTableWidget->setWindowTitle("QTableWidget");
    QStringList m_Header;
    m_Header<<QString("价值期望名称")<<QString("价值期望符号")<<QString("符号")<<QString("期望值");
   // ui->qTableWidget->setHorizontalHeaderLabels(m_Header);//添加横向表头
    ui->qTableWidget->setVerticalHeaderLabels(m_Header);//添加横向表头
    ui->qTableWidget->verticalHeader()->setVisible(false);//纵向表头可视化
    //ui->qTableWidget->horizontalHeader()->setVisible(false); //隐藏行表头
    ui->qTableWidget->horizontalHeader()->setVisible(false);//横向表头可视化
    //ui->tableWidget->setShowGrid(false);//隐藏栅格
   // ui->qTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置编辑方式：禁止编辑表格
    //ui->qTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//设置表格选择方式：设置表格为整行选中
    //ui->qTableWidget->setSelectionBehavior(QAbstractItemView::SelectColumns);//设置表格选择方式：设置表格为整列选中
    ui->qTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);//选择目标方式
    // ui->qTableWidget->setStyleSheet("selection-background-color:white");//设置选中颜色：粉色
    //  setStyleSheet(QString::fromUtf8("border:1px solid black"));

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
            ui->qTableWidget->setColumnWidth(columns,360/ColumnNum);//hangkuan
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
    qDebug()<<"单元格内容："<<strText;//输出单元格内容

    //设置列标签
    QStringList HStrList;
    HStrList.push_back(QString("质量参数1"));
    HStrList.push_back(QString("质量参数2"));
    HStrList.push_back(QString("价值指标1"));
    HStrList.push_back(QString("价值指标2"));
    //HStrList.push_back(QString("other"));
    //设置行列数(只有列存在的前提下，才可以设置列标签)
    int HlableCnt = HStrList.count();
    ui->qTableWidget->setRowCount(RowNum);//
    ui->qTableWidget->setColumnCount(HlableCnt);
    //设置列标签
    ui->qTableWidget->setHorizontalHeaderLabels(HStrList);

    //把QTableWidgetItem对象内容转换为QString
    //QString str =ui->qTableWidget->item(0,0)->data(Qt::DisplayRole).toString();

    QVector<QComboBox*> Combox;
    for(int i=0;i<ColumnNum*RowNum*3;i++)
    {
        QComboBox *tmp= new QComboBox();
        tmp->addItem("极其重要于");
        tmp->addItem("强烈重要于");
        tmp->addItem("同样重要于");
        Combox.append(tmp);
    }
    QVector<QWidget*> CheckBox;
    for(int i=0;i<ColumnNum*RowNum;i++)
    {
        QWidget *widget1 = new QWidget();
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(10, 8, 101, 31));
        QVBoxLayout  *verticalLayout = new QVBoxLayout(widget1) ;
        verticalLayout->setSpacing(0);
        //verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        // 设置互斥
        QCheckBox *pButton = new QCheckBox(this);
        pButton->setText(QString::fromUtf8("切换1"));
        pButton->setStyleSheet("QPushButton{color:white; background-color:transparent;}");
        verticalLayout->addWidget(pButton);
        CheckBox.append(widget1);
    }
    int x=0;
    for (int i=0;i<RowNum;i++) {
        for(int j=0;j<ColumnNum;j++)
        {
            ui->qTableWidget->setCellWidget(i,j,CheckBox.at(x));
            x++;
        }
    }
    x=0;
    int RowNum_2=6;
    int ColumnNum_2=5;
    ui->qTableWidget_2->setColumnCount(ColumnNum_2);//设置列数
    ui->qTableWidget_2->setRowCount(RowNum_2);//设置行数
    ui->qTableWidget_2->setWindowTitle("qTableWidget_2");
    QStringList m_Header_2;
    m_Header_2<<QString("价值期望名称")<<QString("价值期望符号")<<QString("符号")<<QString("期望值");
    ui->qTableWidget_2->setVerticalHeaderLabels(m_Header_2);//添加横向表头
    ui->qTableWidget_2->verticalHeader()->setVisible(false);//纵向表头可视化
    ui->qTableWidget_2->horizontalHeader()->setVisible(false);//横向表头可视化

    ui->qTableWidget_2->setSelectionMode(QAbstractItemView::SingleSelection);//选择目标方式
    for(int rows=0;rows<RowNum_2;rows++)
    {
        for(int columns=0;columns<ColumnNum_2;columns++)
        {
            if(columns==0)
            {
                ui->qTableWidget_2->setItem(rows,columns,new QTableWidgetItem(""));
            }
            else if(columns==1)
            {
                ui->qTableWidget_2->setItem(rows,columns,new QTableWidgetItem(""));
            }
            else if(columns==2)
            {
                ui->qTableWidget_2->setItem(rows,columns,new QTableWidgetItem(""));
            }
            else
            {
                ui->qTableWidget_2->setItem(rows,columns,new QTableWidgetItem(""));
            }
        }
    }
    for(int rows=0;rows<RowNum_2;rows++)
    {
        for(int columns=0;columns<ColumnNum_2;columns++)
        {
            ui->qTableWidget_2->setColumnWidth(columns,360/ColumnNum_2);//hangkuan
            ui->qTableWidget_2->setRowHeight(rows,335/RowNum_2);//列宽
            //ui->qTableWidget_2->horizontalHeader()->setResizeMode(QHeaderView::Strtch);  //使行列头自适应宽度，所有列平均分来填充空白部分
            ui->qTableWidget_2->item(rows,columns)->setTextAlignment(Qt::AlignCenter);//居中显示
            ui->qTableWidget_2->item(rows,columns)->setBackgroundColor(QColor(255,255,255));//设置前景颜色
            ui->qTableWidget_2->item(rows,columns)->setTextColor(QColor(0,0,0));//设置文本颜色
            ui->qTableWidget_2->item(rows,columns)->setFont(QFont("Helvetica"));//设置字体为黑体
        }
    }
    ui->qTableWidget_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);//设置水平滚动条
    ui->qTableWidget_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);//设置垂直滚动条
    //设置行和列的大小设为与内容相匹配（如果设置了宽高就不要用了）


    QString strText_2 = ui->qTableWidget_2->item(1, 1)->text();//获取单元格的内容
    qDebug()<<"单元格内容："<<strText_2;//输出单元格内容

    //设置列标签
    QStringList HStrList_2;
    HStrList_2.push_back(QString("质量参数1"));
    HStrList_2.push_back(QString("质量参数2"));
    HStrList_2.push_back(QString("价值指标1"));
    HStrList_2.push_back(QString("价值指标2"));
    int HlableCnt_2 = HStrList_2.count();
    ui->qTableWidget_2->setRowCount(RowNum_2);//
    ui->qTableWidget_2->setColumnCount(HlableCnt_2);

    ui->qTableWidget_2->setHorizontalHeaderLabels(HStrList_2);

    }

Step4_1::~Step4_1()
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

void Step4_1::on_pushButton_clicked()
{
//    QAbstractItemModel *model = ui->tableWidget->model();
//     model->insertRow(model->rowCount());
    int cols=ui->qTableWidget_2->columnCount();
    int rows=ui->qTableWidget_2->rowCount();
    qDebug()<<rows;
    ui->qTableWidget_2->insertRow(rows);
    for(int i=0;i<cols;i++)
    {
       // ui->qTableWidget->setItem(rows,i,new QTableWidgetItem("new"+QString::number(rows)));
        ui->qTableWidget_2->setItem(rows,i,new QTableWidgetItem(""));
    }
    ui->qTableWidget_2->selectRow(rows);
}

void Step4_1::on_pushButton_2_clicked()
{
    QTableWidgetItem * item = ui->qTableWidget_2->currentItem();
    if(item==Q_NULLPTR)return;
    ui->qTableWidget_2->removeRow(item->row());
}
//将表格数据写入文件
void Step4_1::on_pushButton_3_clicked()
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
    excelEngine.SaveDataFrTable(ui->qTableWidget_2);
    excelEngine.Close();

    QMessageBox::information(this, "excel提示", "导出成功");
}
//将文件数据导入表格
void Step4_1::on_pushButton_4_clicked()
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
        excelEngine.ReadDataToTable(ui->qTableWidget_2);
        excelEngine.Close();
   QMessageBox::information(this, "excel提示", "导入成功");
}

}


void Step4_1::on_pushButton_5_clicked()
{

   QExcelEngine excelEngine=*new QExcelEngine();

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
  excelEngine.SaveDataFrTable(ui->qTableWidget_2);
  excelEngine.Close();

  QMessageBox::information(this, "excel提示", "保存成功");

}


