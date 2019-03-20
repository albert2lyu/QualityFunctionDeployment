#ifndef NINEFORM_H
#define NINEFORM_H

#include <QWidget>
namespace Ui {
class NineForm;
}

class NineForm : public QWidget
{
    Q_OBJECT

public:
    explicit NineForm(QWidget *parent = 0);
    ~NineForm();

private:
    Ui::NineForm *ui;
};

#endif // NINEFORM_H
