#ifndef Step3_1_H
#define Step3_1_H

#include <QWidget>


namespace Ui {
class Step3_1;
}

class Step3_1 : public QWidget
{
    Q_OBJECT

public:
    explicit Step3_1(QWidget *parent = 0);
    ~Step3_1();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
private:
    Ui::Step3_1 *ui;
};

#endif // Step3_1_H
