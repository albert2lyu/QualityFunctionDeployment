#ifndef STEP2_2_H
#define STEP2_2_H

#include <QWidget>
#include <QFile>
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include <QTableWidget>
#include <QPainter>
#include<QAxObject>
#include <QDesktopServices>
#include <excelengine.h>
namespace Ui {
class Step2_2;
}

class Step2_2 : public QWidget
{
    Q_OBJECT

public:
    explicit Step2_2(QWidget *parent = nullptr);

    ~Step2_2();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();




private:
    Ui::Step2_2 *ui;
};

#endif // STEP2_2_H
