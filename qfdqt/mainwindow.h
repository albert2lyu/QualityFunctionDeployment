#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "oneform.h"
#include "twoform.h"
#include "threeform.h"
#include "fourform.h"
#include "fiveform.h"
#include "sixform.h"
#include "sevenform.h"
#include "eightform.h"
#include "nineform.h"
#include "tenform.h"
#include <QStringListModel>
#include <QStandardItemModel>
#include <QModelIndex>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_listWidget_clicked();
//    void on_pushButton_clicked();

//    void on_pushButton_2_clicked();

//    void on_pushButton_3_clicked();

//    void on_pushButton_4_clicked();

//    void on_pushButton_5_clicked();

//    void on_pushButton_6_clicked();

//    void on_pushButton_7_clicked();

//    void on_pushButton_8_clicked();

//    void on_pushButton_9_clicked();

//    void on_pushButton_10_clicked();


//    void on_listWidget_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    OneForm *OneForm_Page;//创建窗口页面指针
    TwoForm *TwoForm_Page;
    ThreeForm *ThreeForm_Page;
    FourForm *FourForm_Page;
    FiveForm *FiveForm_Page;
    SixForm *SixForm_Page;
    SevenForm *SevenForm_Page;
    EightForm *EightForm_Page;
    NineForm *NineForm_Page;
    TenForm *TenForm_Page;
    QStandardItemModel *standardItemModel;//声明model


};

#endif // MAINWINDOW_H
