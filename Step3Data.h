#ifndef STEP3DATA_H
#define STEP3DATA_H

#include <QWidget>

namespace Ui {
class Step3Data;
}

class Step3Data : public QWidget
{
    Q_OBJECT

public:
    explicit Step3Data(QWidget *parent = nullptr);
    ~Step3Data();

private:
    Ui::Step3Data *ui;
};

#endif // STEP3DATA_H
