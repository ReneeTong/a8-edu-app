#ifndef RENDER_H
#define RENDER_H

#include "model.h"
#include <Box2D/Box2D.h>

#include <QObject>
#include <QWidget>

class Render : public QWidget
{
    Q_OBJECT
public:
    static const int WINDOW_WIDTH = 750;
    static const int WINDOW_HEIGHT = 600;

    static const int GROUND_HEIGHT = 30;

    explicit Render(QWidget *parent = nullptr);

    Model* getModel() { return &model; }

protected:
    void mousePressEvent(QMouseEvent * event) override;
    void mouseMoveEvent(QMouseEvent * event) override;
    void mouseReleaseEvent(QMouseEvent * event) override;

    void paintEvent(QPaintEvent* event) override;
    void dropEvent(QDropEvent*) override;
    void dragEnterEvent(QDragEnterEvent* event) override;
    void dragLeaveEvent(QDragLeaveEvent* event) override;
    void dragMoveEvent(QDragMoveEvent* event) override;

    using QWidget::QWidget;

private:
    void renderWorld();

    b2World world;
    QList<b2MouseJoint*> m_mouseJoints;

    Model model;

    Ingredient currentDrop;

    QVector<Shape*> shapes;
    Shape* fryingPan;


signals:
    void mouseClicked(QPoint);
    void itemDrop(QPoint);

};

#endif // RENDER_H
