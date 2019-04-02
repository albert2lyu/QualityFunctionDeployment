#ifndef STEP10_1_H
#define STEP10_1_H

#include <QWidget>
#include <QFile>
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include <QTableWidget>
#include <QPainter>
#include<QAxObject>
#include <QDesktopServices>
#include<excelengine.h>
namespace Ui {
class Step10_1;
}

class Step10_1 : public QWidget
{
    Q_OBJECT

public:
    explicit Step10_1(QWidget *parent = nullptr);

    ~Step10_1();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();




private:
    Ui::Step10_1 *ui;
};
#endif // STEP10_1_H
