//#include "simulations.h"
#include "s3Cooking.h"
#include "render.h"
#include "ui_s3Cooking.h"
#include"draganddrop.h"
#include"model.h"
#include <QPainter>
#include <QDebug>

s3Cooking::s3Cooking(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::s3Cooking)
{
    ui->setupUi(this);
    ui->widget->show();

    // jeffeeeeeeeee
    QTimer::singleShot(0, this, [this]() {
        ui->scrollArea->addWidget(render);//render moved to .h
    });
    connect(render->getModel(), &Model::updateDisplayText, ui->stepLabel, &QLabel::setText);

    //Andy Tran:
    //Step label
    ui->labelStep->setText("STEP 1");
    setAcceptDrops(true);

    xmaps.insert("Tomato",QPixmap(":/sprites/icons/Tomato.png"));
    xmaps.insert("Carrot",QPixmap(":/sprites/icons/Carrot.png"));

    //Ruini:add backgound image
    QPixmap image(":/sprites/icons/Kitchen.PNG");
    QLabel* background = ui->backgoundImage;
    background->setPixmap(image);
    background->setScaledContents(true); // Scale the image to fit the label
    background->setGeometry(QRect(0, 0, background->width(), background->height()));
    background->lower();
}

s3Cooking::~s3Cooking()
{
    delete ui;
}

void s3Cooking::nextPage()
{
    emit goToPage4();
}


void s3Cooking::recieveSelectedRecipe(RecipeNew* recipe) {
    render->getModel()->setRecipe(recipe);


    ui->ingredientList->clearWidgets();
    for (const auto& ingredient : recipe->getIngredeints()) {
        DragAndDropLabel *label = new DragAndDropLabel(this);
        label->setProperty("Ingredient", QVariant::fromValue(ingredient));
        label->setText(ingredient.getName());
        label->setStyleSheet("background-color: transparent");
        label->setFixedSize(50, 50);
        if (!ingredient.getPixmap().isNull()) {
            label->setPixmap(ingredient.getPixmap());
            label->setScaledContents(true);
        }
        label->show();

        ui->ingredientList->addWidget(label);
    }
}
