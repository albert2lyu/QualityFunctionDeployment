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
    int RowNum=10;
    int ColumnNum=4;
    setWindowTitle(tr("TableWidget"));//设置对话框的标题
        ui->qTableWidget->setColumnCount(ColumnNum);//设置列数
       ui->qTableWidget->setRowCount(RowNum);//设置行数
       //table->setRowCount(RowCount+1);
        //ui->qTableWidget->setRowCount(row_count+1); ;//设置行数
        ui->qTableWidget->setWindowTitle("QTableWidget");
        QStringList m_Header;
        m_Header<<QString("价值期望名称")<<QString("价值期望符号")<<QString("符号")<<QString("期望值");
        ui->qTableWidget->setHorizontalHeaderLabels(m_Header);//添加横向表头
        ui->qTableWidget->verticalHeader()->setVisible(false);//纵向表头可视化
        //ui->qTableWidget->horizontalHeader()->setVisible(false); //隐藏行表头
       ui->qTableWidget->horizontalHeader()->setVisible(true);//横向表头可视化
        //ui->tableWidget->setShowGrid(false);//隐藏栅格
        //ui->qTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置编辑方式：禁止编辑表格
        ui->qTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//设置表格选择方式：设置表格为整行选中
        //ui->qTableWidget->setSelectionBehavior(QAbstractItemView::SelectColumns);//设置表格选择方式：设置表格为整列选中
        ui->qTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);//选择目标方式
        ui->qTableWidget->setStyleSheet("selection-background-color:green");//设置选中颜色：粉色
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
                ui->qTableWidget->setColumnWidth(columns,755/ColumnNum);//hangkuan
            ui->qTableWidget->setRowHeight(rows,395/RowNum);//列宽
                //ui->qTableWidget->horizontalHeader()->setResizeMode(QHeaderView::Strtch);  //使行列头自适应宽度，所有列平均分来填充空白部分
                ui->qTableWidget->item(rows,columns)->setTextAlignment(Qt::AlignCenter);//居中显示
                ui->qTableWidget->item(rows,columns)->setBackgroundColor(QColor(85,170,255));//设置前景颜色
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
        HStrList.push_back(QString("指标序号"));
        HStrList.push_back(QString("价值指标"));
        HStrList.push_back(QString("关系符号"));
        HStrList.push_back(QString("期望值"));
        //HStrList.push_back(QString("other"));
        //设置行列数(只有列存在的前提下，才可以设置列标签)
        int HlableCnt = HStrList.count();
        ui->qTableWidget->setRowCount(RowNum);//
        ui->qTableWidget->setColumnCount(HlableCnt);
        //设置列标签
        ui->qTableWidget->setHorizontalHeaderLabels(HStrList);

       //把QTableWidgetItem对象内容转换为QString
        //QString str =ui->qTableWidget->item(0,0)->data(Qt::DisplayRole).toString();

        //具体单元格中添加ComboBox控件，下拉列表
        QComboBox *comBox = new QComboBox();
        comBox->addItem("");
        comBox->addItem("");
        //ui->qTableWidget->setCellWidget(0,3,comBox);

        //ui->qTableWidget->removeColumn(0);//删除列
        //ui->qTableWidget->removeRow(0);//删除行
        //ui->qTableWidget->clear();//清空掉表格内所有内容，包括标题头
        //ui->qTableWidget->clearContents();//这个清空所有内容不包括标题头
    }

Step1_1::~Step1_1()
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

void Step1_1::on_pushButton_clicked()
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

void Step1_1::on_pushButton_2_clicked()
{
    QTableWidgetItem * item = ui->qTableWidget->currentItem();
    if(item==Q_NULLPTR)return;
    ui->qTableWidget->removeRow(item->row());
}
//将表格数据写入文件
void Step1_1::on_pushButton_3_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(0,tr("保存文件"),
                                                tr("/root/Projects/product/bin/config/未命名.xls"),
                                                tr("file(*.txt *.xls);;Allfile(*.*)"));
    if(!fileName.isEmpty())
    {
        //将表格数据写入文件
        if(QFileInfo(fileName).suffix().isEmpty())
        {
            fileName.append(".xls");
        }
        QFile file;
        file.setFileName(fileName);
        //打开文件
        if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QMessageBox msg;
            msg.setText("打开文件失败!");
            msg.exec();
        }
        else
        {
            qDebug("open file success:::");
            QTextStream out(&file);
            int rowCount = ui->qTableWidget->rowCount();
            int colCount = ui->qTableWidget->columnCount();
            //将表头写入文件
            qDebug()<<"row count:::"<<rowCount<<"col count:::"<<colCount;
            for(int i = 0; i < colCount; i++)
            {
                QString rowHeaderString = ui->qTableWidget->horizontalHeaderItem(i)->text();
                out << rowHeaderString << "\t";
            }
            out << "\n";
            for(int j = 0; j < rowCount; j++)
            {
                QString colHeaderString = ui->qTableWidget->verticalHeaderItem(j)->text();
                out << colHeaderString << "\t";
            }
            out << "\n";
            qDebug("saveTable start:::");
            //读取单元格的数据并写入文件
            qDebug()<<"row count:::"<<rowCount<<"col count:::"<<colCount;
            for(int row = 0; row < rowCount; row++)
            {
                for(int col = 0; col < colCount; col++)
                {
                    QString text = ui->qTableWidget->item(row,col)->text();
                    qDebug()<<"text:::"<<text;
                    if(text.isEmpty())
                    {
                        out << "null" << "\t";
                    }
                    else
                    {
                        out << text << "\t";
                    }
                }
                out << "\n";       //linux下换行符是'\n'
            }
            out.flush();
            qDebug("saveTable end:::");
            file.close();       //关闭文件
            QMessageBox::information(0,tr("提示"),tr("导出成功!"));
        }
    }
    else
    {
        QMessageBox::warning(0,tr("警告"),tr("文件名未指定!"),QMessageBox::Ok);
    }
}
//将文件数据导入表格
void Step1_1::on_pushButton_4_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(0, tr("导入文件"),
                                                tr("/root/Projects/product/bin/config"),
                                                tr("file(*.txt *.xls);;Allfile(*.*)"));
    if(!fileName.isEmpty())
    {
        QFile file;
        file.setFileName(fileName);
        //打开文件
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QMessageBox msg;
            msg.setText("打开文件失败!");
            msg.exec();
        }
        else
        {
            if(!file.size())
            {
                QMessageBox::warning(0,tr("警告"),tr("文件大小为空!"),QMessageBox::Ok);
            }
            else
            {
                //将文件数据导入表格
                int r_count = 0;        //统计文件的行数
                QStringList textList;   //记录文件中每一行的数据
                QTextStream in(&file);
                while (!in.atEnd())
                {
                    QString line = in.readLine();
                    textList.append(line);          //保存文件的数据
                    r_count++;                      //记录文件的行数 前两行为表头
                }
                file.close();       //关闭文件
                if(!textList.isEmpty())
                {
                    QStringList listColHeader = textList.at(1).split("\t");
                    QStringList listRowHeader = textList.at(0).split("\t");
                    int c_count = listRowHeader.count();
                    ui->qTableWidget->clear();
                    ui->qTableWidget->setRowCount(r_count-2);      //前两行是行列表头
                    ui->qTableWidget->setColumnCount(c_count-1);   //最后一行是“\t"
                    ui->qTableWidget->setHorizontalHeaderLabels(listRowHeader);
                    ui->qTableWidget->setVerticalHeaderLabels(listColHeader);
                    qDebug()<<"start importTable row count:::"<<r_count<<"col count:::"<<c_count;
                    for(int row = 2; row < r_count; row++)
                    {
                        QStringList tmpList;
                        tmpList = textList.at(row).split("\t");
                        for(int col = 0; col < c_count; col++)
                        {
                            QTableWidgetItem *item = new QTableWidgetItem(tmpList.at(col));
                            ui->qTableWidget->setItem(row-2, col, item);
                        }
                    }
                    QMessageBox::information(0,tr("提示"),tr("导入成功!"));
                }
            }
        }
    }
    else
    {
        QMessageBox::warning(0,tr("警告"),tr("文件名未指定!"),QMessageBox::Ok);
    }
}


















