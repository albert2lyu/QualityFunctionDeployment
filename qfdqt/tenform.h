#ifndef TENFORM_H
#define TENFORM_H

#include <QWidget>

namespace Ui {
class TenForm;
}

class TenForm : public QWidget
{
    Q_OBJECT

public:
    explicit TenForm(QWidget *parent = 0);
    ~TenForm();

private:
    Ui::TenForm *ui;
};

#endif // TENFORM_H
