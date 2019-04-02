#ifndef STEP6DATA_H
#define STEP6DATA_H

#include <QWidget>

namespace Ui {
class Step6Data;
}

class Step6Data : public QWidget
{
    Q_OBJECT

public:
    explicit Step6Data(QWidget *parent = nullptr);
    ~Step6Data();

private:
    Ui::Step6Data *ui;
};

#endif // STEP6DATA_H
