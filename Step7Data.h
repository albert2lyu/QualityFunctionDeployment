#ifndef STEP7DATA_H
#define STEP7DATA_H

#include <QWidget>
#include<QPixmap>
#include<QComboBox>
#include<QFileDialog>
namespace Ui {
class Step7Data;
}

class Step7Data : public QWidget
{
    Q_OBJECT

public:
    explicit Step7Data(QWidget *parent = nullptr);
    ~Step7Data();
private slots:
    void on_pushButton_clicked();
private:
    Ui::Step7Data *ui;
};

#endif // STEP7DATA_H
