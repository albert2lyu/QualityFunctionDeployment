#ifndef STEP6_2_H
#define STEP6_2_H
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
class Step6_2;
}

class Step6_2 : public QWidget
{
    Q_OBJECT

public:
    explicit Step6_2(QWidget *parent = nullptr);

    ~Step6_2();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();




private:
    Ui::Step6_2 *ui;
};

#endif // STEP6_2_H
