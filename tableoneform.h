#ifndef TABLEONEFORM_H
#define TABLEONEFORM_H

#include <QWidget>
#include <QFile>
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include <QTableWidget>

namespace Ui {
class TableOneForm;
}

class TableOneForm : public QWidget
{
    Q_OBJECT

public:
    explicit TableOneForm(QWidget *parent = 0);
    ~TableOneForm();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();



private:
    Ui::TableOneForm *ui;
};



#endif // TABLEONEFORM_H
