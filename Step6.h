#ifndef Step6_H
#define Step6_H

#include <QWidget>

namespace Ui {
class Step6;
}

class Step6 : public QWidget
{
    Q_OBJECT

public:
    explicit Step6(QWidget *parent = 0);
    ~Step6();

private:
    Ui::Step6 *ui;
};

#endif // Step6_H
