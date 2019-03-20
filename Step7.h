#ifndef Step7_H
#define Step7_H

#include <QWidget>

namespace Ui {
class Step7;
}

class Step7 : public QWidget
{
    Q_OBJECT

public:
    explicit Step7(QWidget *parent = 0);
    ~Step7();

private:
    Ui::Step7 *ui;
};

#endif // Step7_H
