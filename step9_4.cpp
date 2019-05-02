#include "step9_4.h"
#include "ui_step9_4.h"
#include "sqlite.h"
#include <QString>
#include "excelengine.h"
#include "matlabfunction.h"

Step9_4::Step9_4(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Step9_4)
{
    ui->setupUi(this);
    setWindowTitle(tr("TableWidget"));
    ui->qTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->qTableWidget->setSelectionBehavior(QAbstractItemView::SelectColumns);
    ui->qTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->qTableWidget->setStyleSheet("selection-background-color:grey");

    Sqlite sqlite;
    sqlite.connect();
    vector<Entity_Step8>returnList = sqlite.queryStep8Data();
    int tableColumn = returnList.size()+1;
    int RowNum = 1;
    QStringList  HStrList;
    HStrList<<"关键度";
    for(int i =0;i<returnList.size();i++)
    {
        QString vExpectation = returnList[i].QualityParameters;
        qDebug()<<"Step9_2::vExpectation"<<vExpectation;
        HStrList.push_back(vExpectation);
    }
    ui->qTableWidget->setRowCount(0);
    ui->qTableWidget->setColumnCount(tableColumn);
    ui->qTableWidget->setHorizontalHeaderLabels(HStrList);
    ui->qTableWidget->setWindowTitle("QTableWidget");
    ui->qTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->qTableWidget->setSelectionBehavior(QAbstractItemView::SelectColumns);
    ui->qTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->qTableWidget->setStyleSheet("selection-background-color:grey");
    ui->qTableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->qTableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->qTableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->qTableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

}

Step9_4::~Step9_4()
{
    delete ui;
}
void Step9_4::on_pushButton_clicked()
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
void Step9_4::on_pushButton_2_clicked()
{
    qDebug()<<"on_pushButton_2_clicked";
    QTableWidgetItem * item = ui->qTableWidget->currentItem();
    if(item==Q_NULLPTR)return;
    ui->qTableWidget->removeRow(item->row());
}
void Step9_4::on_pushButton_3_clicked()
{

}
void Step9_4::on_pushButton_4_clicked()
{

}
void Step9_4::on_pushButton_5_clicked()
{
    qDebug()<<"Step9_4::on_pushButton_5_clicked";
    QExcelEngine excelEngine = *new QExcelEngine();

    excelEngine.ClearAllData("");

    excelEngine.Step9_4SaveData(ui->qTableWidget);

    MatlabFunction matlabFunction = *new MatlabFunction();
    matlabFunction.mlfStep9(ui->qTableWidget);

    QMessageBox::information(this, "end", "end");
    excelEngine.Close();
}


