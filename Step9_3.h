#ifndef STEP9_3_H
#define STEP9_3_H

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
class Step9_3;
}

class Step9_3 : public QWidget
{
    Q_OBJECT

public:
    explicit Step9_3(QWidget *parent = nullptr);

    ~Step9_3();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();




private:
    Ui::Step9_3 *ui;
};
#endif // STEP9_1_H
