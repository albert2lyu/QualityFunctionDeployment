#ifndef THREEFORM_H
#define THREEFORM_H

#include <QWidget>
#include"tablethreeform.h"
#include"tablethree2form.h"
#include<QPainter>
#include<QPen>

namespace Ui {
class ThreeForm;
}

class ThreeForm : public QWidget
{
    Q_OBJECT

public:
    explicit ThreeForm(QWidget *parent = 0);
     void paintEvent(QPaintEvent *);
    ~ThreeForm();
private slots:
     void on_pushButton_clicked();
     void  on_pushButton_2_clicked();
private:
    Ui::ThreeForm *ui;
    TableThreeForm *TableThreeForm_Page;
    TableThree2Form *TableThree2Form_Page;
};

#endif // THREEFORM_H
