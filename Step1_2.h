#ifndef Step1_2_H
#define Step1_2_H

#include <QWidget>

namespace Ui {
class Step1_2;
}

class Step1_2 : public QWidget
{
    Q_OBJECT

public:
    explicit Step1_2(QWidget *parent = nullptr);
    ~Step1_2();

private:
    Ui::Step1_2 *ui;
};

#endif // Step1_2_H
