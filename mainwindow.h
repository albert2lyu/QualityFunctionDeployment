#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Step1.h"
#include "Step2.h"
#include "Step3.h"
#include "Step4.h"
#include "Step5.h"
#include "Step6.h"
#include "Step7.h"
#include "Step8.h"
#include "Step9.h"
#include "Step10.h"
#include <QStringListModel>
#include<qnavigationwidget.h>
#include <QStandardItemModel>
#include <QModelIndex>
#include<QVBoxLayout>
#include<QHBoxLayout>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
private:
    Ui::MainWindow *ui;
    QWidget *mainWidget;
    QWidget *rightWidget;
    QHBoxLayout *mainLayout;
    QVBoxLayout *rightLayout;
    QNavigationWidget *navigationWidget;
    Step1 *Step1_Page;//创建窗口页面指针
    Step2 *Step2_Page;
    Step3 *Step3_Page;
    Step4 *Step4_Page;
    Step5 *Step5_Page;
    Step6 *Step6_Page;
    Step7 *Step7_Page;
    Step8 *Step8_Page;
    Step9 *Step9_Page;
    Step10 *Step10_Page;
    QStandardItemModel *standardItemModel;//声明model


};

#endif // MAINWINDOW_H
