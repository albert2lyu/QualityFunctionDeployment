#ifndef STEP9_4_H
#define STEP9_4_H

#include <QWidget>

namespace Ui {
class Step9_4;
}

class Step9_4 : public QWidget
{
    Q_OBJECT

public:
    explicit Step9_4(QWidget *parent = nullptr);
    ~Step9_4();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
private:
    Ui::Step9_4 *ui;
};

#endif // STEP9_4_H
