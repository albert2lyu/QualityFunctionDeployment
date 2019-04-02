#ifndef STEP2DATA_H
#define STEP2DATA_H

#include <QWidget>
#include<QPixmap>
#include<QComboBox>
#include<QFileDialog>
namespace Ui {
class Step2Data;
}

class Step2Data : public QWidget
{
    Q_OBJECT

public:
    explicit Step2Data(QWidget *parent = nullptr);
    ~Step2Data();
private slots:
    void on_pushButton_clicked();
private:
    Ui::Step2Data *ui;
};

#endif // STEP1DATA_H
