#ifndef Step3_2_H
#define Step3_2_H

#include <QWidget>

namespace Ui {
class Step3_2;
}

class Step3_2 : public QWidget
{
    Q_OBJECT

public:
    explicit Step3_2(QWidget *parent = 0);
    ~Step3_2();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
private:
    Ui::Step3_2 *ui;
};

#endif // Step3_2_H
