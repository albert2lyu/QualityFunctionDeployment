#ifndef Step4_H
#define Step4_H

#include <QWidget>
#include<QPainter>
#include<QPen>
namespace Ui {
class Step4;
}

class Step4 : public QWidget
{
    Q_OBJECT

public:
    explicit Step4(QWidget *parent = 0);
         void paintEvent(QPaintEvent *);
    ~Step4();

private:
    Ui::Step4 *ui;
};

#endif // Step4_H
