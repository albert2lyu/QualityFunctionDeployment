#ifndef STEP7_2_H
#define STEP7_2_H
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
#include<QLineEdit>
#include<QVBoxLayout>
#include<QButtonGroup>
#include<QRadioButton>
#include<QCheckBox>
namespace Ui {
class Step7_2;
}

class Step7_2 : public QWidget
{
    Q_OBJECT

public:
    explicit Step7_2(QWidget *parent = nullptr);

    ~Step7_2();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();



private:
    Ui::Step7_2 *ui;
};

#endif // STEP6_2_H
