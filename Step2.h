#ifndef Step2_H
#define Step2_H

#include <QWidget>
#include<QPainter>
#include<QPen>
namespace Ui {
class Step2;
}

class Step2 : public QWidget
{
    Q_OBJECT

public:
    explicit Step2(QWidget *parent = 0);
         void paintEvent(QPaintEvent *);
    ~Step2();

private:
    Ui::Step2 *ui;
};

#endif // Step2_H
