#ifndef TWOFORM_H
#define TWOFORM_H

#include <QWidget>

namespace Ui {
class TwoForm;
}

class TwoForm : public QWidget
{
    Q_OBJECT

public:
    explicit TwoForm(QWidget *parent = 0);
    ~TwoForm();

private:
    Ui::TwoForm *ui;
};

#endif // TWOFORM_H
