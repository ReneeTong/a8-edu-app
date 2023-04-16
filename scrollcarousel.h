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
    ScrollCarousel(QWidget *parent = nullptr);

    void addWidget(QWidget*);

    void addFilter(bool (*)(QWidget*));
    void removeFilter(bool (*)(QWidget*));

protected:
    void wheelEvent(QWheelEvent *event) override;

private:
    void reset();

    QBoxLayout *scrollLayout;

    QList<QWidget*> widgets;
    QMap<QWidget*, bool> widgetVisible;

    QList<bool (*)(QWidget*)> filterList;

    QPropertyAnimation *horizontalAnimation;
    QPropertyAnimation *verticalAnimation;

//    controller controller;
//    QMap<QPushButton*, Ingredient*> buttonIngredientMap;//tzhou: maybe uneccessary, but to make it work
};

#endif // SCROLLCAROUSEL_H
