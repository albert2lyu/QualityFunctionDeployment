#ifndef STEP1DATA_H
#define STEP1DATA_H

#include <QWidget>
#include<QPixmap>
#include<QComboBox>
#include<QFileDialog>
namespace Ui {
class Step1Data;
}

class Step1Data : public QWidget
{
    Q_OBJECT

public:
    explicit Step1Data(QWidget *parent = nullptr);
    ~Step1Data();
private slots:
    void on_pushButton_clicked();
private:
    Ui::Step1Data *ui;
};

#endif // STEP1DATA_H
