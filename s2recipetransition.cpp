#include "s2recipetransition.h"
#include "qtimer.h"
#include "ui_s2recipetransition.h"
#include <QFont>
#include <QColor>
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>
#include <QParallelAnimationGroup>

s2RecipeTransition::s2RecipeTransition(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::s2RecipeTransition)
{
    ui->setupUi(this);

    movie = new QMovie(":/sprites/icons/funny.gif");
    gifLabel = new QLabel(this);
    gifLabel->setMovie(movie);
    movie->start();

    startTextAnimations();

    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(100);

    loadingTimer = new QTimer(this);
    loadingTimer->setSingleShot(true);
    connect(loadingTimer, &QTimer::timeout, this, &s2RecipeTransition::loadingFinished);
    progressBarTimer = new QTimer(this);
    connect(progressBarTimer, &QTimer::timeout, this, &s2RecipeTransition::updateProgressBar);

    ui->layout->addWidget(gifLabel, 0, Qt::AlignCenter);
}


s2RecipeTransition::~s2RecipeTransition()
{
    delete ui;
}

void s2RecipeTransition::showLoadingScreen()
{
    progressBarValue = 0;
    ui->progressBar->setValue(progressBarValue);
    loadingTimer->start(2500); // Start the timer for 2 seconds (2000 milliseconds)
    progressBarTimer->start(20); // Start the timer for updating the progress bar
}


void s2RecipeTransition::updateProgressBar()
{
    progressBarValue += 1;
    ui->progressBar->setValue(progressBarValue);
    if (progressBarValue >= 100)
    {
        progressBarTimer->stop();
    }
}

void s2RecipeTransition::startTextAnimations()
{
    QSequentialAnimationGroup *animationGroup = new QSequentialAnimationGroup(ui->prepLab);
    animationGroup->setLoopCount(-1); // Set the loop count to -1 for infinite looping

    QPropertyAnimation *animation1 = new QPropertyAnimation(ui->prepLab, "pos");
    animation1->setDuration(450);
    animation1->setStartValue(ui->prepLab->pos());
    animation1->setEndValue(QPoint(ui->prepLab->pos().x(), ui->prepLab->pos().y() + 20));
    animation1->setEasingCurve(QEasingCurve::InOutSine);

    QPropertyAnimation *animation2 = new QPropertyAnimation(ui->prepLab, "pos");
    animation2->setDuration(450);
    animation2->setStartValue(QPoint(ui->prepLab->pos().x(), ui->prepLab->pos().y() + 20));
    animation2->setEndValue(ui->prepLab->pos());
    animation2->setEasingCurve(QEasingCurve::InOutSine);

    animationGroup->addAnimation(animation1);
    animationGroup->addAnimation(animation2);
    animationGroup->start(); // Start the animation
}

void s2RecipeTransition::setColor(QColor color)
{
    QPalette palette = ui->prepLab->palette();
    palette.setColor(QPalette::WindowText, color);
    ui->prepLab->setPalette(palette);
}
