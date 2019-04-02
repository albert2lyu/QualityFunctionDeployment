#ifndef STEP9DATA_H
#define STEP9DATA_H

#include <QWidget>
#include<QPixmap>
#include<QComboBox>
#include<QFileDialog>
namespace Ui {
class Step9Data;
}

class Step9Data : public QWidget
{
    Q_OBJECT

public:
    explicit Step9Data(QWidget *parent = nullptr);
    ~Step9Data();
private slots:
    void on_pushButton_clicked();
private:
    Ui::Step9Data *ui;
};

#endif // STEP9DATA_H
