#ifndef STEP7_1_H
#define STEP7_1_H

#include <QWidget>
#include <QFile>
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include <QTableWidget>
#include <QPainter>
#include<QAxObject>
#include <QDesktopServices>
#include "excelengine.h"
namespace Ui {
class Step7_1;
}

class Step7_1 : public QWidget
{
    Q_OBJECT

public:
    explicit Step7_1(QWidget *parent = nullptr);

    ~Step7_1();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();




private:
    Ui::Step7_1 *ui;
};

#endif // STEP7_1_H
