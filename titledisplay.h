
#ifndef TITLEDISPLAY_H
#define TITLEDISPLAY_H


#include <QTimer>
#include <QWidget>


class titleDisplay : public QWidget
{
    Q_OBJECT
public:
    explicit titleDisplay(QWidget *parent = nullptr);


protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QTimer animationTimer;
    int animationProgress;

private slots:
    void updateAnimation();

};

#endif // TITLEDISPLAY_H
