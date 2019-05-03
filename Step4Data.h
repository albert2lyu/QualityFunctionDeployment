#ifndef STEP4DATA_H
#define STEP4DATA_H

#include <QWidget>
#include<QPixmap>
#include<QComboBox>
#include<QFileDialog>
namespace Ui {
class Step4Data;
}

class Step4Data : public QWidget
{
    Q_OBJECT

public:
    explicit Step4Data(QWidget *parent = nullptr);
    ~Step4Data();
private slots:
    void on_pushButton_clicked();

private:
    Ui::Step4Data *ui;
};

#endif // STEP4DATA_H
