#ifndef SEVENFORM_H
#define SEVENFORM_H

#include <QWidget>

namespace Ui {
class SevenForm;
}

class SevenForm : public QWidget
{
    Q_OBJECT

public:
    explicit SevenForm(QWidget *parent = 0);
    ~SevenForm();

private:
    Ui::SevenForm *ui;
};

#endif // SEVENFORM_H
