#ifndef Step9_H
#define Step9_H

#include <QWidget>
#include<QPainter>
#include<QPen>
namespace Ui {
class Step9;
}

class Step9 : public QWidget
{
    Q_OBJECT

public:
    explicit Step9(QWidget *parent = 0);
         void paintEvent(QPaintEvent *);
    ~Step9();

private:
    Ui::Step9 *ui;
};

#endif // Step9_H
