#ifndef Step1_1_H
#define Step1_1_H

#include <QWidget>
#include <QFile>
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include <QTableWidget>

namespace Ui {
class Step1_1;
}

class Step1_1 : public QWidget
{
    Q_OBJECT

public:
    explicit Step1_1(QWidget *parent = 0);
    ~Step1_1();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();



private:
    Ui::Step1_1 *ui;
};



#endif // Step1_1_H
