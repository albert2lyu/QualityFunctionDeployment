#ifndef STEP4DATA_H
#define STEP4DATA_H

#include <QWidget>

namespace Ui {
class Step4Data;
}

class Step4Data : public QWidget
{
    Q_OBJECT

public:
    explicit Step4Data(QWidget *parent = nullptr);
    ~Step4Data();

private:
    Ui::Step4Data *ui;
};

#endif // STEP4DATA_H
