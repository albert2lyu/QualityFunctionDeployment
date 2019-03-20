#ifndef TABLETHREE2FORM_H
#define TABLETHREE2FORM_H

#include <QWidget>

namespace Ui {
class TableThree2Form;
}

class TableThree2Form : public QWidget
{
    Q_OBJECT

public:
    explicit TableThree2Form(QWidget *parent = 0);
    ~TableThree2Form();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
private:
    Ui::TableThree2Form *ui;
};

#endif // TABLETHREE2FORM_H
