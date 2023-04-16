/**
 * @brief Scroll Carousel
 *
 * @author Jeffrey Le
 *
 */


#include "scrollcarousel.h"

/**
 * @brief The SquareButton class
 */
class SquareButton : public QPushButton {
public:
    SquareButton();
    SquareButton(int);
    SquareButton(int, const QString &);
};

SquareButton::SquareButton() : QPushButton() {}

SquareButton::SquareButton(int size) : QPushButton() {
    setFixedSize(size, size);
}

SquareButton::SquareButton(int size, const QString &text) : SquareButton(size) {
    setText(text);
}


/**
 * @brief ScrollCarousel::ScrollCarousel
 * @param parent
 */
ScrollCarousel::ScrollCarousel(QWidget *parent) : QScrollArea(parent) {
    setStyleSheet(
                "QScrollArea {background-color: transparent; border: 0px}"
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

        QWidget *gridContent = new QWidget(this);
        QBoxLayout *scrollContents =  isHorizontal ? static_cast<QBoxLayout*>(new QHBoxLayout(gridContent)) :
                                         static_cast<QBoxLayout*>(new QVBoxLayout(gridContent));

        scrollContents->setSpacing(25);
        scrollContents->setContentsMargins(isHorizontal * 25, 0, isHorizontal * 25, 0);
        scrollContents->setAlignment(Qt::AlignHCenter);
        gridContent->setLayout(scrollContents);

        for (int i = 0; i < 25; i++) {
            SquareButton *button = new SquareButton(75, QString::number(i));
            scrollContents->addWidget(button);
        }
        setWidget(gridContent);
    });
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
