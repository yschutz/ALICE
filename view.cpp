#include <QKeyEvent>
#include <qmath.h>
#include <QOpenGLFunctions>
#include <QTimer>

#include "scene.h"
#include "view.h"

//===================================================================
View::View(int refreshRate) : QOpenGLWindow(),
    mAspect(45.0), mPhiRotation(0.0), mThetaRotation(-90.0)
{
    // ctor

    setTitle("titre");
    mScene = new Scene(this);

    QSurfaceFormat format;
    format.setMajorVersion(3);
    format.setMinorVersion(4);
    format.setProfile(QSurfaceFormat::CoreProfile);
    format.setSamples(4);
    format.setDepthBufferSize(24);
    setFormat(format);

    mDebugLogger = new QOpenGLDebugLogger(this);
    connect(mDebugLogger, SIGNAL(messageLogged(QOpenGLDebugMessage)), this, SLOT(printLog(QOpenGLDebugMessage)));

    resize(800, 600);
    mMousePosition = QPointF(width() / 2, height() / 2);

//    mEyePos     = QVector3D(0.0, 0.0, 50.0);
//    mViewCenter = QVector3D(0.0, 0.0, -1.0);
//    mEyeUp      = QVector3D(0.0, 1.0,  0.0);

    mEyePos     = QVector3D(0.0, 0.0, -50.0);
    mViewCenter = QVector3D(0.0, 0.0, 1.0);
    mEyeUp      = QVector3D(0.0, 1.0,  0.0);

    int second = 10000; // 1 second = 1000 ms
    int timerInterval = second / refreshRate;
    mTimer = new QTimer(this);
    connect(mTimer, SIGNAL(timeout()), this, SLOT(timeOutSlot()));
    mTimer->start(timerInterval);
}

//===================================================================
void View::initializeGL()
{
    // initialisation of QOpenGL (called once)

    qDebug() << Q_FUNC_INFO;
    setDebugger(true);
    mScene->setContext(context());

    stage(); // to be implemented by derived class

    mScene->createMeshes();
    context()->functions()->glViewport(0, 0, width(), height());

}

//===================================================================
void View::keyPressEvent(QKeyEvent *event)
{
    // define action in response to keyboard key pressed

    switch (event->key()) {
    case Qt::Key_Escape:
        close();
        break;
    case Qt::Key_F1:
        toggleFullScreen();
        break;
    case Qt::Key_PageUp:
        mEyePos.setZ(mEyePos.z() - 10.);
        break;
    case Qt::Key_PageDown:
        mEyePos.setZ(mEyePos.z() + 10.);
        break;
    default:
        break;
    }
}

//===================================================================
void View::mouseMoveEvent(QMouseEvent *event)
{
    // define action in response to mouse moved
    if(mMouseClicked) {
        const float kSensitivity = 0.05;
        float xOffset = (event->pos().x() - mMousePosition.x()) * kSensitivity;
        float yOffset = (event->pos().y() - mMousePosition.y()) * kSensitivity;

        mThetaRotation += xOffset;
        mPhiRotation   += yOffset;

        if (mPhiRotation > 89.0)
            mPhiRotation = 90.0;
        if (mPhiRotation < -89.0)
            mPhiRotation = -89.0;

        float x = qCos(qDegreesToRadians(mPhiRotation)) * qCos(qDegreesToRadians(mThetaRotation));
        float y = qSin(qDegreesToRadians(mPhiRotation));
        float z = qCos(qDegreesToRadians(mPhiRotation)) * qSin(qDegreesToRadians(mThetaRotation));

        mViewCenter = QVector3D(x, y, z);
        mViewCenter.normalize();

        mMousePosition = event->pos();

        update();
    }
}

//===================================================================
void View::mousePressEvent(QMouseEvent */*event*/)
{
    // set mouse clicked

    mMouseClicked = !mMouseClicked;

}

//===================================================================
void View::paintGL()
{
    // makes the drawing; called each time screen is refreshed

    mScene->setPerspective(mAspect, ((double) width()) / ((double)height()), 1, 100.0f);
    mScene->lookAt(mEyePos, mEyePos + mViewCenter, mEyeUp);
    mScene->draw();
}

//===================================================================
void View::resizeGL(int w, int h)
{
    // resizes the screen

    context()->functions()->glViewport(0, 0, w, h);
}

//===================================================================
void View::toggleFullScreen()
{
    // toggle between full screen mode
    if (mFullScreen) {
        showNormal();
        mFullScreen = false;
    } else {
        showFullScreen();
        mFullScreen = true;
    }
}

//===================================================================
void View::setDebugger(bool active)
{
    // start/stop QOpenGL debug logging
    if(active) {
        mDebugLogger->initialize();
        mDebugLogger->startLogging();
    } else {
        mDebugLogger->stopLogging();
    }
}

//===================================================================
void View::timeOutSlot()
{
//    foreach (Mesh *mesh, mScene->meshes()) {
//        mesh->rotate( 0.5, 1.0, 0.0, 1.0);
//    }
    update();
}

//===================================================================
void View::printLog(const QOpenGLDebugMessage &msg)
{
    qDebug() << msg.id() << msg.message();
}

