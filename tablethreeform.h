#ifndef TABLETHREEFORM_H
#define TABLETHREEFORM_H

#include <QWidget>


namespace Ui {
class TableThreeForm;
}

class TableThreeForm : public QWidget
{
    Q_OBJECT

public:
    explicit TableThreeForm(QWidget *parent = 0);
    ~TableThreeForm();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
private:
    Ui::TableThreeForm *ui;
};

#endif // TABLETHREEFORM_H
