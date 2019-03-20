#include "tabletwoform.h"
#include "ui_tabletwoform.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDebug>
#include <QComboBox>
TableTwoForm::TableTwoForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableTwoForm)
{
    ui->setupUi(this);
    setWindowTitle(tr("TableWidget"));//设置对话框的标题
        ui->qqTableWidget->setColumnCount(4);//设置列数
        ui->qqTableWidget->setRowCount(10);//设置行数
        ui->qqTableWidget->setWindowTitle("QTableWidget");
        QStringList m_Header;
        m_Header<<QString("序号")<<QString("姓名")<<QString("性别")<<QString("地址");
        ui->qqTableWidget->setHorizontalHeaderLabels(m_Header);//添加横向表头
        ui->qqTableWidget->verticalHeader()->setVisible(true);//纵向表头可视化
        ui->qqTableWidget->horizontalHeader()->setVisible(true);//横向表头可视化
        //ui->tableWidget->setShowGrid(false);//隐藏栅格
        //ui->qqTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置编辑方式：禁止编辑表格
        ui->qqTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//设置表格选择方式：设置表格为整行选中
        //ui->qTableWidget->setSelectionBehavior(QAbstractItemView::SelectColumns);//设置表格选择方式：设置表格为整列选中
        ui->qqTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);//选择目标方式
        ui->qqTableWidget->setStyleSheet("selection-background-color:pink");//设置选中颜色：粉色
        setStyleSheet(QString::fromUtf8("border:3px solid black"));

        for(int rows=0;rows<10;rows++)
        {
            for(int columns=0;columns<4;columns++)
            {
                if(columns==0)
                {
                    ui->qqTableWidget->setItem(rows,columns,new QTableWidgetItem(""));
                }
                else if(columns==1)
                {
                    ui->qqTableWidget->setItem(rows,columns,new QTableWidgetItem(""));
                }
                else if(columns==2)
                {
                    ui->qqTableWidget->setItem(rows,columns,new QTableWidgetItem(""));
                }
                else
                {
                    ui->qqTableWidget->setItem(rows,columns,new QTableWidgetItem(""));
                }
            }
        }
        for(int rows=0;rows<10;rows++)
        {
            for(int columns=0;columns<4;columns++)
            {
                ui->qqTableWidget->setColumnWidth(columns,125);
                ui->qqTableWidget->setRowHeight(rows,30);
                ui->qqTableWidget->item(rows,columns)->setTextAlignment(Qt::AlignCenter);//居中显示
                ui->qqTableWidget->item(rows,columns)->setBackgroundColor(QColor(85,170,255));//设置前景颜色
                ui->qqTableWidget->item(rows,columns)->setTextColor(QColor(0,0,0));//设置文本颜色
                ui->qqTableWidget->item(rows,columns)->setFont(QFont("Helvetica"));//设置字体为黑体
            }
        }
       // ui->qqTableWidget->setSpan(2, 2,2 ,1);//合并单元格
       // ui->qqTableWidget->setItem(2, 2, new QTableWidgetItem(QIcon("E:\\Qt_Project\\QTableWidget\\1.jpg"), "路飞"));//插入图片
        ui->qqTableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);//设置水平滚动条
        ui->qqTableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);//设置垂直滚动条
        //设置行和列的大小设为与内容相匹配（如果设置了宽高就不要用了）
        //ui->qTableWidget->resizeColumnsToContents();
        //ui->qTableWidget->resizeRowsToContents();

        QString strText = ui->qqTableWidget->item(1, 1)->text();//获取单元格的内容
        qDebug()<<"单元格内容："<<strText;//输出单元格内容

        //设置列标签
        QStringList HStrList;
        HStrList.push_back(QString("id"));
        HStrList.push_back(QString("name"));
        HStrList.push_back(QString("sex"));
        HStrList.push_back(QString("city"));
        HStrList.push_back(QString("other"));
        //设置行列数(只有列存在的前提下，才可以设置列标签)
        int HlableCnt = HStrList.count();
        ui->qqTableWidget->setRowCount(10);
        ui->qqTableWidget->setColumnCount(HlableCnt);
        //设置列标签
        ui->qqTableWidget->setHorizontalHeaderLabels(HStrList);

       //把QTableWidgetItem对象内容转换为QString
        //QString str =ui->qTableWidget->item(0,0)->data(Qt::DisplayRole).toString();

        //具体单元格中添加ComboBox控件，下拉列表
        QComboBox *comBox = new QComboBox();
        comBox->addItem("");
        comBox->addItem("");
        //ui->qqTableWidget->setCellWidget(0,3,comBox);

        //ui->qTableWidget->removeColumn(0);//删除列
        //ui->qTableWidget->removeRow(0);//删除行
        //ui->qTableWidget->clear();//清空掉表格内所有内容，包括标题头
        //ui->qTableWidget->clearContents();//这个清空所有内容不包括标题头
    }


TableTwoForm::~TableTwoForm()
{
    delete ui;
}
