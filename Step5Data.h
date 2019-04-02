#ifndef STEP5DATA_H
#define STEP5DATA_H

#include <QWidget>

namespace Ui {
class Step5Data;
}

class Step5Data : public QWidget
{
    Q_OBJECT

public:
    explicit Step5Data(QWidget *parent = nullptr);
    ~Step5Data();

private:
    Ui::Step5Data *ui;
};

#endif // STEP5DATA_H
