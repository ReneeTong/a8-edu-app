#include "s2recipetransition.h"
#include "qtimer.h"
#include "ui_s2recipetransition.h"

s2RecipeTransition::s2RecipeTransition(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::s2RecipeTransition)
{
    ui->setupUi(this);

    movie = new QMovie(":/path/to/your/gif/file.gif");
    gifLabel = new QLabel(this);
    gifLabel->setMovie(movie);
    movie->start();

    ui->prepLab->setText("Getting Everything Ready");

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
    progressBar->setValue(progressBarValue);
    loadingTimer->start(2000); // Start the timer for 2 seconds (2000 milliseconds)
    progressBarTimer->start(20); // Start the timer for updating the progress bar
}


void s2RecipeTransition::updateProgressBar()
{
    progressBarValue += 1;
    progressBar->setValue(progressBarValue);
    if (progressBarValue >= 100)
    {
        progressBarTimer->stop();
    }
}
