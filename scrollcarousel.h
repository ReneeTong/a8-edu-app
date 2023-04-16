/**
 * @brief Scroll Carousel
 *
 * @author Jeffrey Le
 *
 */

#ifndef SCROLLCAROUSEL_H
#define SCROLLCAROUSEL_H

#include <QObject>

#include <QScroller>
#include <QScrollArea>
#include <QScrollBar>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPropertyAnimation>
#include <QWheelEvent>
#include <QTimer>
#include <QScrollerProperties>

class ScrollCarousel : public QScrollArea
{
    Q_OBJECT
public:
    ScrollCarousel(QWidget *parent = nullptr);

    void addWidget(QWidget*);

protected:
    void wheelEvent(QWheelEvent *event) override;

private:
    QBoxLayout *scrollLayout;

    QMap<QWidget*, bool> widgetVisible;
    QMap<QWidget*, int> widgetPosition;

    QPropertyAnimation *horizontalAnimation;
    QPropertyAnimation *verticalAnimation;
};

#endif // SCROLLCAROUSEL_H
