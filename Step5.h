#ifndef Step5_H
#define Step5_H

#include <QWidget>

namespace Ui {
class Step5;
}

class Step5 : public QWidget
{
    Q_OBJECT

public:
    explicit Step5(QWidget *parent = 0);
    ~Step5();

private:
    Ui::Step5 *ui;
};

#endif // Step5_H
