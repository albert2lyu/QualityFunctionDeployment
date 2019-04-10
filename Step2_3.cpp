#include "Step2_3.h"
#include "ui_Step2_3.h"
//#include "excelengine.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDebug>
#include <QComboBox>
#include <QFileDialog>
#include "sqlite.h"
#include "entity_step1.h"
Step2_3::Step2_3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Step2_3)
{
        qDebug()<<"Step2_3::ui*****************************************";
        ui->setupUi(this);
        int RowNum=6;
        int ColumnNum=6;
        setWindowTitle(tr("TableWidget"));//设置对话框的标题
        ui->qTableWidget->setColumnCount(ColumnNum);//设置列数
        ui->qTableWidget->setRowCount(RowNum);//设置行数
        //table->setRowCount(RowCount+1);
        //ui->qTableWidget->setRowCount(row_count+1); ;//设置行数
        ui->qTableWidget->setWindowTitle("QTableWidget");
        //QStringList m_Header;
        //m_Header<<QString("价值期望名称")<<QString("价值期望符号")<<QString("符号")<<QString("期望值");
        //ui->qTableWidget->setHorizontalHeaderLabels(m_Header);//添加横向表头
        ui->qTableWidget->verticalHeader()->setVisible(true);//纵向表头可视化
        ui->qTableWidget->horizontalHeader()->setVisible(true);//横向表头可视化
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
                ui->qTableWidget->item(rows,columns)->setTextAlignment(Qt::AlignCenter);//居中显示
                ui->qTableWidget->item(rows,columns)->setBackgroundColor(QColor(255,255,255));//设置前景颜色
                ui->qTableWidget->item(rows,columns)->setTextColor(QColor(0,0,0));//设置文本颜色
                ui->qTableWidget->item(rows,columns)->setFont(QFont("Helvetica"));//设置字体为黑体
            }
        }
        ui->qTableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);//设置水平滚动条
        ui->qTableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);//设置垂直滚动条
        //////////
        /// \brief sqlite 根据第一步输入数据刻画矩阵
        ///
        Sqlite sqlite = * new Sqlite();
        sqlite.connect();
        vector<Entity_Step1> returnlist = sqlite.queryStep1Data();
        QStringList HStrList;
        for(int i=0;i<=returnlist.size();i++)
        {
            HStrList.push_back(returnlist[i].valueIndexName);
        }
        int HlableCnt = HStrList.count();
        ui->qTableWidget->setRowCount(HlableCnt);//
        ui->qTableWidget->setColumnCount(HlableCnt);
        //设置列标签
        ui->qTableWidget->setHorizontalHeaderLabels(HStrList);
        //设置行标签
        ui->qTableWidget->setVerticalHeaderLabels(HStrList);
        //QComboBox *comBox = new QComboBox();
        //comBox->addItem("");
        //comBox->addItem("");
    }

Step2_3::~Step2_3()
{
    delete ui;
}

void Step2_3::on_pushButton_clicked()
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

void Step2_3::on_pushButton_2_clicked()
{
    QTableWidgetItem * item = ui->qTableWidget->currentItem();
    if(item==Q_NULLPTR)return;
    ui->qTableWidget->removeRow(item->row());
}
//将表格数据写入文件
void Step2_3::on_pushButton_3_clicked()
{
    QExcelEngine excelEngine=*new QExcelEngine();

    QString filename="0";
    if(filename.isEmpty())
        return;
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
void Step2_3::on_pushButton_4_clicked()
{
    QMessageBox::StandardButton rb = QMessageBox::information(this, "warning", "从excel文件中导入数据将会覆盖之前所有内容，\n确定导入吗？",
                             QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

    if(rb == QMessageBox::Yes)
    {
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
void Step2_3::on_pushButton_5_clicked()
{
    qDebug()<<"Step2_3::on_pushButton_5_clicked";
    QExcelEngine excelEngine=*new QExcelEngine();
    //清空表格之前的所有内容
    excelEngine.ClearAllData("");
    excelEngine.Close();
    //打开数据库，并保存数据
    QMessageBox::information(this, "excel提示", "保存成功");

}


