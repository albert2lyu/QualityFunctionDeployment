#ifndef Step10_H
#define Step10_H

#include <QWidget>

namespace Ui {
class Step10;
}

class Step10 : public QWidget
{
    Q_OBJECT

public:
    explicit Step10(QWidget *parent = 0);
    ~Step10();

private:
    Ui::Step10 *ui;
};

#endif // Step10_H