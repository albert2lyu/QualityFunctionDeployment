#ifndef STEP9_2_H
#define STEP9_2_H

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
class Step9_2;
}

class Step9_2 : public QWidget
{
    Q_OBJECT

public:
    explicit Step9_2(QWidget *parent = nullptr);

    ~Step9_2();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();




private:
    Ui::Step9_2 *ui;
};
#endif // STEP9_1_H
