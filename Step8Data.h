#ifndef STEP8DATA_H
#define STEP8DATA_H

#include <QWidget>
#include<QPixmap>
#include<QComboBox>
#include<QFileDialog>
namespace Ui {
class Step8Data;
}

class Step8Data : public QWidget
{
    Q_OBJECT

public:
    explicit Step8Data(QWidget *parent = nullptr);
    ~Step8Data();
private slots:
    void on_pushButton_clicked();
private:
    Ui::Step8Data *ui;
};

#endif // STEP8DATA_H
