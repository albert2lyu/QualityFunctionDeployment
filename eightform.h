#ifndef EIGHTFORM_H
#define EIGHTFORM_H

#include <QWidget>

namespace Ui {
class EightForm;
}

class EightForm : public QWidget
{
    Q_OBJECT

public:
    explicit EightForm(QWidget *parent = 0);
    ~EightForm();

private:
    Ui::EightForm *ui;
};

#endif // EIGHTFORM_H
