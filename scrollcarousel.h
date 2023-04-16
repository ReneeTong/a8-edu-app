#ifndef SCROLLCAROUSEL_H
#define SCROLLCAROUSEL_H

#include <QFrame>
#include <QObject>

#include <QAbstractItemView>
#include <QScroller>
#include <QScrollArea>
#include <QScrollBar>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSizePolicy>
#include <QPropertyAnimation>
#include <QWheelEvent>
#include <QCoreApplication>
#include <QTimer>
#include <QScrollerProperties>

class ScrollCarousel : public QScrollArea
{
    Q_OBJECT
public:
    ScrollCarousel(QWidget *parent = nullptr);

protected:
    void wheelEvent(QWheelEvent *event) override;

private:
    QPropertyAnimation *horizontalAnimation;
    QPropertyAnimation *verticalAnimation;
};

#endif // SCROLLCAROUSEL_H
