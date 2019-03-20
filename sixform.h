#ifndef SIXFORM_H
#define SIXFORM_H

#include <QWidget>

namespace Ui {
class SixForm;
}

class SixForm : public QWidget
{
    Q_OBJECT

public:
    explicit SixForm(QWidget *parent = 0);
    ~SixForm();

private:
    Ui::SixForm *ui;
};

#endif // SIXFORM_H
