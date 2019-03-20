#ifndef FOURFORM_H
#define FOURFORM_H

#include <QWidget>

namespace Ui {
class FourForm;
}

class FourForm : public QWidget
{
    Q_OBJECT

public:
    explicit FourForm(QWidget *parent = 0);
    ~FourForm();

private:
    Ui::FourForm *ui;
};

#endif // FOURFORM_H
