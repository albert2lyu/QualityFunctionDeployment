#ifndef STEP5_1_H
#define STEP5_1_H

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
class Step5_1;
}

class Step5_1 : public QWidget
{
    Q_OBJECT

public:
    explicit Step5_1(QWidget *parent = nullptr);

    ~Step5_1();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();




private:
    Ui::Step5_1 *ui;
};

#endif // STEP5_1_H
