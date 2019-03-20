#ifndef FIVEFORM_H
#define FIVEFORM_H

#include <QWidget>

namespace Ui {
class FiveForm;
}

class FiveForm : public QWidget
{
    Q_OBJECT

public:
    explicit FiveForm(QWidget *parent = 0);
    ~FiveForm();

private:
    Ui::FiveForm *ui;
};

#endif // FIVEFORM_H
