#ifndef Step8_H
#define Step8_H

#include <QWidget>
#include<QPainter>
#include<QPen>
namespace Ui {
class Step8;
}

class Step8 : public QWidget
{
    Q_OBJECT

public:
    explicit Step8(QWidget *parent = 0);
         void paintEvent(QPaintEvent *);
    ~Step8();

private:
    Ui::Step8 *ui;
};

#endif // Step8_H
