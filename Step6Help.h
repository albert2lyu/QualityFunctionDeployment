#ifndef STEP6HELP_H
#define STEP6HELP_H

#include <QDialog>

namespace Ui {
class Step6Help;
}

class Step6Help : public QDialog
{
    Q_OBJECT

public:
    explicit Step6Help(QWidget *parent = nullptr);
    ~Step6Help();

private:
    Ui::Step6Help *ui;
};

#endif // STEP6HELP_H
