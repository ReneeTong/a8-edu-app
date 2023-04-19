/**
 * @brief Scroll Carousel
 *
 * @author Jeffrey Le
 *
 */

#ifndef SCROLLCAROUSEL_H
#define SCROLLCAROUSEL_H

#include"ingredient.h"

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
    explicit ScrollCarousel(QWidget *parent = nullptr);
    ScrollCarousel(bool, QWidget *parent = nullptr);

    void addWidget(QWidget*);

    void addFilter(bool (*)(QWidget*));
    void removeFilter(bool (*)(QWidget*));
    void sortWidgetsBy(std::function<bool(QWidget*, QWidget*)>);


protected:
    void wheelEvent(QWheelEvent *event) override;

private:
    void reset();
    void rearrangeWidgets();


    QBoxLayout *scrollLayout;

    QList<QWidget*> widgets;
    QMap<QWidget*, bool> widgetVisible;

    QList<bool (*)(QWidget*)> filterList;

    QPropertyAnimation *horizontalAnimation;
    QPropertyAnimation *verticalAnimation;





};

#endif // SCROLLCAROUSEL_H
