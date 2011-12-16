#ifndef KINWND_H
#define KINWND_H

#include <QMainWindow>

namespace Ui {
    class kinwnd;
}

class kinwnd : public QMainWindow
{
    Q_OBJECT

public:
    explicit kinwnd(QWidget *parent = 0);
    ~kinwnd();

private:
    Ui::kinwnd *ui;
};

#endif // KINWND_H
