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


    xmaps.insert("tomato",QPixmap(":/sprites/icons/tomato.png"));
    xmaps.insert("carrot",QPixmap(":/sprites/icons/carrot.png"));

    createLables();

    //static label for ingredient
    DragAndDropLabel * label2 = new DragAndDropLabel(parent);
    label2->setParent(ui->leftFrame);
    QPixmap pixCarrot(":/sprites/icons/carrot.png");
    label2->setGeometry(QRect(5,5,50,50));
    label2->setPixmap(pixCarrot);
    label2->setScaledContents(true);
    label2->show();
    label2->setStyleSheet("background-color: rgba(0,0,0,0);");
    label2->move(50, 50);

    //Ruini:add backgound image
    QPixmap image(":/sprites/icons/Kitchen.PNG");
    QLabel* background = ui->backgoundImage;
    background->setPixmap(image);
    background->setScaledContents(true); // Scale the image to fit the label
    background->setGeometry(QRect(0, 0, background->width(), background->height()));
    background->lower();

    //    connect(listener, &MyContactListener::cut, this, &s3Cooking::handleCut);
    //    connect(ui->tomato, &QPushButton::clicked, ui->widget, &simulations::testTrue);

    //Andy Tran: connection to communicate btw Model and S3
    //connect(&m_model, &ModelNew::onS3Update, this, &s3Cooking::onS3Update);
    //connect(this, &s3Cooking::onStepCookingUpdate, &m_model, &Model::onStepCookingUpdate);
    //Ruini edit
    //connect(ui->widget->listener, &MyContactListener::onStepCookingUpdate, &m_model, &ModelNew::onStepCookingUpdate);

}

s3Cooking::~s3Cooking()
{
    delete ui;
}

void s3Cooking::nextPage()
{
    emit goToPage4();
}

//Andy Tran: on s3 update
void s3Cooking::onS3Update(int curStep, QHash<Ingredient*, int>* todoList){
    ui->labelStep->setText("Step " + QString::number(curStep));
    this->todoList = todoList;

    //Update Left Frame and Right Frame to display properly

}
//----------------------------------------------------------------------------


void s3Cooking::recieveSelectedRecipe(RecipeNew* recipe) {
    render->getModel()->setRecipe(recipe);

    ui->ingredientList->clearWidgets();
    for (const auto& ingredient : recipe->getIngredeints()) {
        DragAndDropLabel *label = new DragAndDropLabel(this);
        label->setStyleSheet("background-color: transparent");
        label->setFixedSize(50, 50);
        label->setPixmap(ingredient.getPixmap());
        label->setScaledContents(true);
        label->show();

        ui->ingredientList->addWidget(label);
    }
}


void s3Cooking::createLables(){


}
