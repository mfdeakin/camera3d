
#include <QtGui/QApplication>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "kinwnd.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    kinwnd *wnd = new kinwnd();
    wnd->show();
    app.setActiveWindow(wnd);
    int ret = app.exec();
    freenect_sync_stop();
    return ret;
}
