#include "Step2_2.h"
#include "ui_Step2_2.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDebug>
#include <QComboBox>
#include <QFileDialog>
#include <QMessageBox>
Step2_2::Step2_2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Step2_2)
{
    ui->setupUi(this);
    int RowNum=10;
    int ColumnNum=5;
    setWindowTitle(tr("TableWidget"));
    ui->qTableWidget->setColumnCount(ColumnNum);
    ui->qTableWidget->setRowCount(RowNum);
    ui->qTableWidget->setWindowTitle("QTableWidget");
    QStringList m_Header;
    m_Header<<QString("参数名称")<<QString("参数类型(连续or离散)")<<QString("参数范围");
    ui->qTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->qTableWidget->setSelectionBehavior(QAbstractItemView::SelectColumns);
    ui->qTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->qTableWidget->setStyleSheet("selection-background-color:black");
    for(int rows=0;rows<RowNum;rows++)
    {
        for(int columns=0;columns<ColumnNum;columns++)
        {
            ui->qTableWidget->setItem(rows,columns,new QTableWidgetItem(""));
            ui->qTableWidget->setColumnWidth(columns,660/ColumnNum);
            ui->qTableWidget->setRowHeight(rows,335/RowNum);
            ui->qTableWidget->item(rows,columns)->setTextAlignment(Qt::AlignCenter);
            ui->qTableWidget->item(rows,columns)->setBackgroundColor(QColor(255,255,255));
            ui->qTableWidget->item(rows,columns)->setTextColor(QColor(0,0,0));
            ui->qTableWidget->item(rows,columns)->setFont(QFont("微软雅黑"));
        }
    }
    ui->qTableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->qTableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    QStringList HStrList;
    HStrList.push_back(QString("参数名称"));
    HStrList.push_back(QString("参数类型(连续or离散)"));
    HStrList.push_back(QString("参数范围"));
   // HStrList.push_back(QString("改进可能性"));
    //HStrList.push_back(QString("价值指标关键度"));
    ui->qTableWidget->setRowCount(RowNum);
    ui->qTableWidget->setColumnCount(ColumnNum);
    ui->qTableWidget->setHorizontalHeaderLabels(HStrList);


}


Step2_2::~Step2_2()
{
    delete ui;
}

void Step2_2::on_pushButton_clicked()
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

void Step2_2::on_pushButton_2_clicked()
{
    QTableWidgetItem * item = ui->qTableWidget->currentItem();
    if(item==Q_NULLPTR)return;
    ui->qTableWidget->removeRow(item->row());
}
//将表格数据写入文件
void Step2_2::on_pushButton_3_clicked()
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
void Step2_2::on_pushButton_4_clicked()
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
