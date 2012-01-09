#ifndef KINWND_H
#define KINWND_H

#include <gl/gl.h>
#include <stdlib.h>
#include <QtOpenGL/QGLWidget>
#include <QTimer>
//C Synchronous wrapper is very nice :D
#include <libfreenect_sync.h>

#define WIDTH 640
#define HEIGHT 480
#define ARATIO 0.75

class kinwnd : public QGLWidget
{
    Q_OBJECT

public:
    explicit kinwnd(QWidget *parent = NULL, unsigned devicenum = 0);
    ~kinwnd();

public slots:
    void timeout();

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

private:
    //The device to be used in getting the  information
    unsigned dvc;
    //Used for updating the scene
    QTimer *timer;
    GLuint texture;
    GLubyte *texbuf;
};

#endif // KINWND_H
