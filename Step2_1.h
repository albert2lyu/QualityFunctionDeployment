#ifndef Step2_1_H
#define Step2_1_H

#include <QWidget>
#include <QMessageBox>

namespace Ui {
class Step2_1;
}

class Step2_1 : public QWidget
{
    Q_OBJECT

public:
    explicit Step2_1(QWidget *parent = 0);
    ~Step2_1();
/*private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();*/
private:
    Ui::Step2_1 *ui;
};

#endif // Step2_1_H
