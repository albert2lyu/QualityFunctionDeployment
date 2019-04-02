#ifndef STEP7DATA_H
#define STEP7DATA_H

#include <QWidget>

namespace Ui {
class Step7Data;
}

class Step7Data : public QWidget
{
    Q_OBJECT

public:
    explicit Step7Data(QWidget *parent = nullptr);
    ~Step7Data();

private:
    Ui::Step7Data *ui;
};

#endif // STEP7DATA_H
