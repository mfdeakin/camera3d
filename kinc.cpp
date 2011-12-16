
#include <QtGui/QApplication>
#include <libfreenect/libfreenect.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "kinwnd.h"

#define WIDTH 640
#define HEIGHT 480

void depthf(freenect_device *dvc, void *depth, uint32_t time);
void freestuff();

struct
{
    freenect_context *ctx;
    freenect_device *dvc;
    float ang;
    kinwnd *window;
} kin;

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    int err;
    err = freenect_init(&kin.ctx, NULL);
    if(!kin.ctx || err < 0)
    {
        fprintf(stderr, "Could not initialize context!\n");
        return 1;
    }
    unsigned kincnt = freenect_num_devices(kin.ctx);
    if(!kincnt)
    {
        printf("No kinects detected!\n");
        freenect_shutdown(kin.ctx);

        return 1;
    }
    freenect_open_device(kin.ctx, &kin.dvc, 0);
    freenect_set_depth_callback(kin.dvc, &depthf);
    freenect_start_depth(kin.dvc);
    atexit(freestuff);
    kin.window = new kinwnd();
    kin.window->setBaseSize(WIDTH, HEIGHT);
    kin.window->show();
    return app.exec();
}

void depthf(freenect_device *dvc, void *depthvp, uint32_t time)
{
}

void freestuff()
{
    freenect_close_device(kin.dvc);
    freenect_shutdown(kin.ctx);

}

