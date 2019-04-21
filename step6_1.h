#ifndef STEP6_1_H
#define STEP6_1_H

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
#include<QVBoxLayout>
#include<QRadioButton>
#include<QButtonGroup>
#include<QLineEdit>
#include<QVBoxLayout>
#include<QButtonGroup>
#include<QRadioButton>
#include<QCheckBox>
namespace Ui {
class Step6_1;
}

class Step6_1 : public QWidget
{
    Q_OBJECT

public:
    explicit Step6_1(QWidget *parent = nullptr);

    ~Step6_1();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();




private:
    Ui::Step6_1 *ui;
};
#endif // STEP6_1_H
