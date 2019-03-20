#ifndef TABLETWOFORM_H
#define TABLETWOFORM_H

#include <QWidget>

namespace Ui {
class TableTwoForm;
}

class TableTwoForm : public QWidget
{
    Q_OBJECT

public:
    explicit TableTwoForm(QWidget *parent = 0);
    ~TableTwoForm();

private:
    Ui::TableTwoForm *ui;
};

#endif // TABLETWOFORM_H
