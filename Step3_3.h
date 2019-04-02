#ifndef Step3_3_H
#define Step3_3_H

#include <QWidget>

namespace Ui {
class Step3_3;
}

class Step3_3 : public QWidget
{
    Q_OBJECT

public:
    explicit Step3_3(QWidget *parent = nullptr);
    ~Step3_3();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
private:
    Ui::Step3_3 *ui;
};

#endif // Step3_3_H
