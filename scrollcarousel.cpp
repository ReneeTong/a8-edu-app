

#include "scrollcarousel.h"


ScrollCarousel::ScrollCarousel(QWidget *parent) : QScrollArea(parent) {
    setStyleSheet(
                "QScrollArea > QWidget > QWidget {background-color: transparent;}"
                "ScrollCarousel {background-color: grey;}"
                  );

    setWidgetResizable(true);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // define QScroller
    QScroller::grabGesture(this, QScroller::LeftMouseButtonGesture);
    QScroller *scroller = QScroller::scroller(this);

    QScrollerProperties scrollerProperties = scroller->scrollerProperties();
    scrollerProperties.setScrollMetric(QScrollerProperties::DecelerationFactor, 0.75);
    scrollerProperties.setScrollMetric(QScrollerProperties::OvershootDragDistanceFactor, 0.1);
    scrollerProperties.setScrollMetric(QScrollerProperties::OvershootScrollDistanceFactor, 0.1);

    scroller->setScrollerProperties(scrollerProperties);

    // define scroll animations
    horizontalAnimation = new QPropertyAnimation(horizontalScrollBar(), "value", this);
    horizontalAnimation->setEasingCurve(QEasingCurve::OutQuad);
    horizontalAnimation->setDuration(500);

    verticalAnimation = new QPropertyAnimation(verticalScrollBar(), "value", this);
    verticalAnimation->setEasingCurve(QEasingCurve::OutQuad);
    verticalAnimation->setDuration(500);

    // define scroll layout
    QTimer::singleShot(0, this, [this]() {
        bool isHorizontal = property("isHorizontal").value<bool>();

        verticalScrollBar()->setEnabled(isHorizontal);
        horizontalScrollBar()->setEnabled(isHorizontal);

        QWidget *widgetContents = new QWidget(this);
        scrollLayout =  isHorizontal ? static_cast<QBoxLayout*>(new QHBoxLayout(widgetContents)) :
                                         static_cast<QBoxLayout*>(new QVBoxLayout(widgetContents));

        scrollLayout->setSpacing(25);
        scrollLayout->setContentsMargins(isHorizontal * 25, !isHorizontal * 25, isHorizontal * 25, !isHorizontal * 25);
        scrollLayout->setAlignment(Qt::AlignHCenter);
        widgetContents->setLayout(scrollLayout);

        for (int i = 0; i < 25; i++) {
            QPushButton *button = new QPushButton(QString::number(i));
            button->setFixedSize(75, 75);
            scrollLayout->addWidget(button);
        }
        setWidget(widgetContents);
    });
}

void ScrollCarousel::addWidget(QWidget *widget) {
    scrollLayout->addWidget(widget);
}





void ScrollCarousel::wheelEvent(QWheelEvent *event) {
    // Get current scroll target
    int horizontalOld = horizontalAnimation->endValue().value<int>();
    int verticalOld = verticalAnimation->endValue().value<int>();

    // Adjust scroll target's location
    int horizontalNew = horizontalOld - event->angleDelta().y();
    int verticalNew = verticalOld - event->angleDelta().y();

    // clamp scroll target
    horizontalNew = std::max(0, std::min(horizontalNew, horizontalScrollBar()->maximum()));
    verticalNew = std::max(0, std::min(verticalNew, verticalScrollBar()->maximum()));

    // animate :sunglasses_emoji:
    if (horizontalOld != horizontalNew) {
        horizontalAnimation->stop();
        horizontalAnimation->setStartValue(horizontalScrollBar()->value());
        horizontalAnimation->setEndValue(horizontalNew);
        horizontalAnimation->start();
    }

    if (verticalOld != verticalNew) {
        verticalAnimation->stop();
        verticalAnimation->setStartValue(verticalScrollBar()->value());
        verticalAnimation->setEndValue(verticalNew);
        verticalAnimation->start();
    }
}
