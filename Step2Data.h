#ifndef STEP2DATA_H
#define STEP2DATA_H

#include <QWidget>

namespace Ui {
class Step2Data;
}

class Step2Data : public QWidget
{
    Q_OBJECT

public:
    explicit Step2Data(QWidget *parent = nullptr);
    ~Step2Data();

private:
    Ui::Step2Data *ui;
};

#endif // STEP2DATA_H
