#include "Step4_1.h"
#include "ui_Step4_1.h"
//#include "excelengine.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDebug>
#include <QComboBox>
#include <QFileDialog>
#include "sqlite.h"

Step4_1::Step4_1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Step4_1)
{
    qDebug()<<"Step4_1::ui";
    ui->setupUi(this);
    ui->qTableWidget->setWindowTitle("QTableWidget");
    ui->qTableWidget->verticalHeader()->setVisible(false);//纵向表头可视化
    ui->qTableWidget->horizontalHeader()->setVisible(false);//横向表头可视化
    ui->qTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);//选择目标方式

    Sqlite sqlite;
    sqlite.connect();
    vector<Entity_Step4_1>returnList = sqlite.queryStep4_1Data();
    qDebug()<<"Step4_1::ui::returnList.size()::"<<returnList.size();
    if(returnList.size()!= 0 )
    {
        int tableColumn = 4;
        int RowNum= (int)(returnList.size()/4)+1;
        ui->qTableWidget->setRowCount(RowNum);
        ui->qTableWidget->setColumnCount(tableColumn);
        QVector<QWidget*> RadioButton;
        for(int i=0 ; i<(int)returnList.size();i++)
        {
            QString valueExpectation = returnList[i].QualityParameterName;
            QWidget *widget1 = new QWidget();
            widget1->setObjectName(valueExpectation);
            widget1->setGeometry(QRect(10, 8, 101, 31));
            QVBoxLayout  *verticalLayout = new QVBoxLayout(widget1) ;
            verticalLayout->setSpacing(0);
            verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
            verticalLayout->setContentsMargins(0, 0, 0, 0);
            QCheckBox *pButton = new QCheckBox(this);
            pButton->setText(valueExpectation);
            pButton->setStyleSheet("QPushButton{color:white; background-color:transparent;}");
            pButton->setObjectName(valueExpectation);
            verticalLayout->addWidget(pButton);
            RadioButton.append(widget1);
        }
        qDebug()<<"Step4_1::ui::RadioButton.size()::"<<RadioButton.size();
        qDebug()<<"Step4_1::ui::QCheckBox";
        qDebug()<<"Step4_1::ui::tableColumn::"<<tableColumn;
        qDebug()<<"Step4_1::ui::RowNum::"<<RowNum;
        int x =0;
        for(int i=0;i<RowNum;i++)
        {
            for(int j =0;j<tableColumn;j++)
            {
                if(x >= (int)returnList.size())
                {
                    break;
                }
                ui->qTableWidget->setCellWidget(i,j,RadioButton.at(x));
                qDebug()<<"Step4_1::ui::i::"<<i<<"-----j::"<<j;
                x++;
            }


        }
        qDebug()<<"Step4_1::ui::QCheckBox end";
    }

    int RowNum_2=0;
    int ColumnNum_2=1;
    ui->qTableWidget_2->setColumnCount(ColumnNum_2);//设置列数
    ui->qTableWidget_2->setRowCount(RowNum_2);//设置行数
    //设置列标签
    QStringList HStrList_2;
    HStrList_2.push_back(QString("质量参数"));
    qDebug()<<"11"<<endl;
    ui->qTableWidget_2->setHorizontalHeaderLabels(HStrList_2);
}

Step4_1::~Step4_1()
{
    delete ui;
}

void Step4_1::on_pushButton_clicked()
{
    int cols=ui->qTableWidget_2->columnCount();
    int rows=ui->qTableWidget_2->rowCount();
    qDebug()<<rows;
    ui->qTableWidget_2->insertRow(rows);
    for(int i=0;i<cols;i++)
    {
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

    QString filename="0";
    if(filename.isEmpty())
        return;

    bool b = excelEngine.Open2(filename, 1, false); //flase为不显示窗体
    if(b == false)
    {
        QMessageBox::information(this, "excel提示", "文件打开失败");
        return;
    }
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
    //清空表格之前的所有内容
    excelEngine.ClearAllData(" ");

    excelEngine.Step4_2SaveData(ui->qTableWidget,ui->qTableWidget_2);
    excelEngine.Close();
    QMessageBox::information(this, "excel提示", "保存成功");

}

