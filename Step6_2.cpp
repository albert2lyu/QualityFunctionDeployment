#include "Step6_2.h"
#include "ui_Step6_2.h"
//#include "excelengine.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDebug>
#include <QComboBox>
#include <QFileDialog>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDebug>
#include <QComboBox>
#include <QFileDialog>
#include "sqlite.h"
#include "matlabfunction.h"

Step6_2::Step6_2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Step6_2)
{
    ui->setupUi(this);

        ui->qTableWidget->setWindowTitle("QTableWidget");
        ui->qTableWidget->verticalHeader()->setVisible(true);//纵向表头可视化
        ui->qTableWidget->horizontalHeader()->setVisible(true);//横向表头可视化
        ui->qTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//设置表格选择方式：设置表格为整行选中
        ui->qTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);//选择目标方式
        ui->qTableWidget->setStyleSheet("selection-background-color:grey");//设置选中颜色：粉色
//        setStyleSheet(QString::fromUtf8("border:1px solid black"));

        Sqlite sqlite;
        sqlite.connect();
        vector<Entity_Step4_2>returnList = sqlite.queryStep4_2Data();
        int RowNum = (int)returnList.size();
        QStringList HStrList;
        for(int i =0;i<RowNum;i++)
        {
            QString qualityParameterName = returnList[i].chooseQualityParameterName;
            HStrList.push_back(qualityParameterName);
        }
        int HlableCnt = HStrList.count();
        ui->qTableWidget->setRowCount(RowNum);
        ui->qTableWidget->setColumnCount(HlableCnt);
        ui->qTableWidget->setHorizontalHeaderLabels(HStrList);
        ui->qTableWidget->setVerticalHeaderLabels(HStrList);

        QVector<QComboBox*> Combox;
        for(int i=0;i<HlableCnt*RowNum*2;i++)
        {
            if(i%2==0)
            {
                QComboBox *tmp= new QComboBox();
                tmp->addItem("积极正相关");
                tmp->addItem("消极正相关");
                tmp->addItem("积极负相关");
                tmp->addItem("消极负相关");
                tmp->addItem("正相关");
                tmp->addItem("负相关");
                tmp->addItem("无关");
                tmp->setCurrentIndex(6) ;
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
        for(int i=0;i<HlableCnt*RowNum;i++)
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
            for(int j=0;j<HlableCnt;j++)
            {
                ui->qTableWidget->setCellWidget(i,j,ThreeCombox.at(x));
                x++;
            }
        }
        x=0;
}

Step6_2::~Step6_2()
{
    delete ui;
}
void Step6_2::on_pushButton_clicked()
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

void Step6_2::on_pushButton_2_clicked()
{
    QTableWidgetItem * item = ui->qTableWidget->currentItem();
    if(item==Q_NULLPTR)return;
    ui->qTableWidget->removeRow(item->row());
}
//将表格数据写入文件
void Step6_2::on_pushButton_3_clicked()
{
     QExcelEngine excelEngine=*new QExcelEngine();

    QString filename="0";// = QFileDialog::getSaveFileName(this, tr("Save as..."), "../datafile", tr("EXCEL files (*.xls *.xlsx);;HTML-Files (*.txt);;"));
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
void Step6_2::on_pushButton_4_clicked()
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


void Step6_2::on_pushButton_5_clicked()
{

    QExcelEngine excelEngine=*new QExcelEngine();

    excelEngine.Step6_2SaveData(ui->qTableWidget);




    excelEngine.Close();

    QMessageBox::information(this, "excel提示", "保存成功");

}

void Step6_2::on_pushButton_6_clicked()
{



    MatlabFunction matlabFunction = *new MatlabFunction();
    matlabFunction.matStep6(ui->qTableWidget);


    QMessageBox::information(this, "提示", "计算完毕");

}
