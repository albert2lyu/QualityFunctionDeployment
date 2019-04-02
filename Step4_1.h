#ifndef STEP4_1_H
#define STEP4_1_H
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
class Step4_1;
}

class Step4_1 : public QWidget
{
    Q_OBJECT

public:
    explicit Step4_1(QWidget *parent = nullptr);

    ~Step4_1();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();




private:
    Ui::Step4_1 *ui;
};

#endif // STEP4_1_H
