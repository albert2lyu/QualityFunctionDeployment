#ifndef STEP10DATA_H
#define STEP10DATA_H

#include <QWidget>
#include<QPixmap>
#include<QComboBox>
#include<QFileDialog>
namespace Ui {
class Step10Data;
}

class Step10Data : public QWidget
{
    Q_OBJECT

public:
    explicit Step10Data(QWidget *parent = nullptr);
    ~Step10Data();
private slots:
    void on_pushButton_clicked();
private:
    Ui::Step10Data *ui;
};

#endif // STEP1DATA_H
