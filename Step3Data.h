#ifndef STEP3DATA_H
#define STEP3DATA_H

#include <QWidget>
#include<QPixmap>
#include<QComboBox>
#include<QFileDialog>
namespace Ui {
class Step3Data;
}

class Step3Data : public QWidget
{
    Q_OBJECT

public:
    explicit Step3Data(QWidget *parent = nullptr);
    ~Step3Data();
private slots:
    void on_pushButton_clicked();
private:
    Ui::Step3Data *ui;
};

#endif // STEP1DATA_H
