#ifndef ONEFORM_H
#define ONEFORM_H

#include <QWidget>
#include "tableoneform.h"
#include "tabletwoform.h"
namespace Ui {
class OneForm;
}

class OneForm : public QWidget
{
    Q_OBJECT

public:
    explicit OneForm(QWidget *parent = 0);
    ~OneForm();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
private:
    Ui::OneForm *ui;
    TableOneForm *TableOneForm_Page;//创建窗口页面指针
    TableTwoForm *TableTwoForm_Page;
};

#endif // ONEFORM_H
