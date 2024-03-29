#include "Step9data.h"
#include "ui_Step9Data.h"
#include "Step9_1.h"
#include<QPixmapCache>

Step9Data::Step9Data(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Step9Data)
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
                ui->qTableWidget->setColumnWidth(columns,306/ColumnNum);//hangkuan
            ui->qTableWidget->setRowHeight(rows,227/RowNum);//列宽
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

//        QString strText = ui->qTableWidget->item(1, 1)->text();//获取单元格的内容
//        qDebug()<<"单元格内容："<<strText;//输出单元格内容

//        //设置列标签
//        QStringList HStrList;
//        HStrList.push_back(QString("指标序号"));
//        HStrList.push_back(QString("价值指标"));
//        HStrList.push_back(QString("关系符号"));
//        HStrList.push_back(QString("期望值"));
//        //HStrList.push_back(QString("other"));
//        //设置行列数(只有列存在的前提下，才可以设置列标签)
//        int HlableCnt = HStrList.count();
//        ui->qTableWidget->setRowCount(RowNum);//
//        ui->qTableWidget->setColumnCount(HlableCnt);
//        //设置列标签
//        ui->qTableWidget->setHorizontalHeaderLabels(HStrList);

//       //把QTableWidgetItem对象内容转换为QString
//        //QString str =ui->qTableWidget->item(0,0)->data(Qt::DisplayRole).toString();

//        //具体单元格中添加ComboBox控件，下拉列表
//        QComboBox *comBox = new QComboBox();
//        comBox->addItem("");
//        comBox->addItem("");
        //ui->qTableWidget->setCellWidget(0,3,comBox);

        //ui->qTableWidget->removeColumn(0);//删除列
        //ui->qTableWidget->removeRow(0);//删除行
        //ui->qTableWidget->clear();//清空掉表格内所有内容，包括标题头
        //ui->qTableWidget->clearContents();//这个清空所有内容不包括标题头
        qDebug()<<"Step9Data:: on_pushButton_clicked";
        QExcelEngine excelEngine=*new QExcelEngine();
        excelEngine.Step8QueryData(ui->qTableWidget);
        excelEngine.Close();
}

Step9Data::~Step9Data()
{
    delete ui;
}
void Step9Data::on_pushButton_clicked(){



    qDebug()<<"Step9Data:: on_pushButton_clicked";
    QExcelEngine excelEngine=*new QExcelEngine();
    excelEngine.Step8QueryData(ui->qTableWidget);
    excelEngine.Close();

}
