#ifndef STEP10DATA_H
#define STEP10DATA_H

#include <QWidget>

namespace Ui {
class Step10Data;
}

class Step10Data : public QWidget
{
    Q_OBJECT

public:
    explicit Step10Data(QWidget *parent = nullptr);
    ~Step10Data();

private:
    Ui::Step10Data *ui;
};

#endif // STEP10DATA_H
