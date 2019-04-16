#ifndef STEP3_4_H
#define STEP3_4_H

#include <QWidget>

namespace Ui {
class Step3_4;
}

class Step3_4 : public QWidget
{
    Q_OBJECT

public:
    explicit Step3_4(QWidget *parent = nullptr);
    ~Step3_4();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
private:
    Ui::Step3_4 *ui;
};

#endif // STEP3_4_H
