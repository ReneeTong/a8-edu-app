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
    static const int WINDOW_WIDTH = 600;
    static const int WINDOW_HEIGHT = 500;

    static const int GROUND_HEIGHT = 30;

    explicit Render(QWidget *parent = nullptr);

    Model* getModel() { return &model; }
    void mousePressEvent(QMouseEvent * event) override;

protected:
    void paintEvent(QPaintEvent* event) override;
    void dropEvent(QDropEvent*) override;
    void dragEnterEvent(QDragEnterEvent* event) override;
    void dragLeaveEvent(QDragLeaveEvent* event) override;
    void dragMoveEvent(QDragMoveEvent* event) override;
    using QWidget::QWidget;

private:
    void renderWorld();

    b2World world;
    Model model;

    Ingredient currentDrop;

signals:
    void mouseClicked(QPoint);
    void itemDrop(QPoint);

};

#endif // RENDER_H
