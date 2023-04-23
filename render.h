#ifndef RENDER_H
#define RENDER_H

#include "modelnew.h"
#include <Box2D/Box2D.h>

#include <QObject>
#include <QWidget>

class Render : public QWidget
{
    Q_OBJECT
public:
    static const int WINDOW_WIDTH = 1000;
    static const int WINDOW_HEIGHT = 150;

    static const int GROUND_HEIGHT = 10;

    explicit Render(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent * event) override;
    void paintEvent(QPaintEvent* event) override;

private:
    void renderWorld();

    b2World world;
    ModelNew model;

signals:
    void mouseClicked(QPoint);

};

#endif // RENDER_H
