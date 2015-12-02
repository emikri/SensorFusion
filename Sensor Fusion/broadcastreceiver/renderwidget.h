#ifndef RENDERWIDGET_H
#define RENDERWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QQuaternion>

class RenderWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    explicit RenderWidget(QWidget *parent = 0);

signals:

public slots:
};

#endif // RENDERWIDGET_H
