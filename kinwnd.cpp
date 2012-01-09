#include "kinwnd.h"

kinwnd::kinwnd(QWidget *parent, unsigned devicenum) :
    QGLWidget(parent)
{
    timer = new QTimer();
    timer->connect(timer, SIGNAL(timeout()), this, SLOT(timeout()));
    timer->start(17);
    dvc = devicenum;
}

kinwnd::~kinwnd()
{
    delete timer;
    delete texbuf;
}

void kinwnd::timeout()
{
    update(0, 0, 640, 480);
}

void kinwnd::initializeGL()
{
    qglClearColor(QColor(255, 255, 255));
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &texture);
    void *data;
    uint32_t time;
    //Run this once here for performance reasons
    freenect_sync_get_depth(&data, &time, dvc, FREENECT_DEPTH_11BIT);
    texbuf = new GLubyte[WIDTH * HEIGHT];
    memset(texbuf, 0, sizeof(GLubyte) * WIDTH * HEIGHT);
}

void kinwnd::paintGL()
{
    void *data;
    uint32_t time;
    //Grab the data from the Kinect
    freenect_sync_get_depth(&data, &time, dvc, FREENECT_DEPTH_11BIT);
    memset(texbuf, 0, sizeof(GLubyte) * WIDTH * HEIGHT);
    for(int i = 0; i < WIDTH; i++)
    {
        for(int j = 0; j < HEIGHT; j++)
        {
            texbuf[i + j * WIDTH] = ((short *)data)[i + (HEIGHT - 1) * WIDTH - j * WIDTH] >> 3;
        }
    }
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDrawPixels(WIDTH, HEIGHT, GL_RED, GL_BYTE, texbuf);
}

void kinwnd::resizeGL(int w, int h)
{
    //Set up the viewport so that we can render a texture on it
    if(w < h)
        glViewport(0, (h - w) / 2, w, w);
    else
        glViewport((w - h) / 2, 0, h, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-0.5, +0.5, -0.5, +0.5, 4.0, 15.0);
}
