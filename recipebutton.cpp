#include "recipebutton.h"
#include "ui_recipebutton.h"

recipeButton* recipeButton::previousClickedRecipe = nullptr;

recipeButton::recipeButton(const Recipe &recipe, QWidget *parent) :
    QPushButton(parent),
    ui(new Ui::recipeButton)
{
    ui->setupUi(this);

    Recipe recipeCopy = recipe;
    this->recipe = new Recipe(recipeCopy);

    ui->recipeName->setText(recipe.getName());
    qDebug() << "Recipe name:" << recipe.getName();
    ui->recipeDifficulty->setValue(recipe.getDifficulty());
    ui->recipeDifficulty->setRange(0, 100); // Set range from 0 to 100
    ui->recipeDifficulty->setValue((recipe.getDifficulty() * 100) / 5); // Calculate the percentage based on difficulty level
    setFixedSize(350,425);
    ui->difficultyLab->setText(QString("Difficulty: %1/5").arg(recipe.getDifficulty()));


    QVector<Ingredient*> chosenIngredients;
    chosenIngredients.push_back(new Ingredient("broccoli"));
    chosenIngredients.push_back(new Ingredient("carrot"));
    chosenIngredients.push_back(new Ingredient("riceNoodles"));

    // Populate the ingredients list
    populateIngredientsList(recipe.getTasks(), chosenIngredients);


//   connect(this, &QPushButton::clicked, this, &recipeButton::toggleSelected);

   connect(this, &QPushButton::clicked, this, [this]() {
       setSelected(!getSelected());
   });
   connect(this, &QPushButton::clicked, this, &recipeButton::onClicked);
}

recipeButton::~recipeButton()
{
    delete ui;
}

Recipe* recipeButton::getRecipe(){
    return recipe;
}

bool recipeButton::isIngredientChosen(Ingredient *ingredient, const QList<Ingredient*> &chosenIngredients)
{
    for (Ingredient *chosenIngredient : chosenIngredients) {
        if (ingredient->getName() == chosenIngredient->getName()) {
            return true;
        }
    }
    return false;
}

void recipeButton::populateIngredientsList(const  QMap<Ingredient, int> tasks, const QList<Ingredient *> &chosenIngredients)
{
    int matchingIngredientsCount = 0;

    for (auto it = tasks.constBegin(); it != tasks.constEnd(); ++it)
    {
        Ingredient ingredient = it.key();
        int amount = it.value();

        QListWidgetItem *listItem = new QListWidgetItem(ui->matchingList);
        listItem->setText(QString("%1 x %2").arg(amount).arg(ingredient.getName()));

        if (isIngredientChosen(&ingredient, chosenIngredients))
        {
            listItem->setForeground(Qt::green);
            matchingIngredientsCount++;
        }
        else
        {
            listItem->setForeground(Qt::red);
        }

        ui->matchingList->addItem(listItem);
    }

    // Update the matching ingredients label
    ui->matchingLab->setText(QString("Matching ingredients: %1").arg(matchingIngredientsCount));
}

bool recipeButton::getSelected() const {
    return selected;
}

//void recipeButton::setSelected(bool selected) {
//    this->selected = selected;
//    update();
//}

//void recipeButton::paintEvent(QPaintEvent *event)
//{
//    QPushButton::paintEvent(event); // Call the base class paintEvent method

//    if (selected) {
//        QPainter painter(this);
//        QPen pen(Qt::red, 2);
//        painter.setPen(pen);
//        painter.drawRect(1, 1, width() - 2, height() - 2);
//    }
//}

//void recipeButton::toggleSelected() {
//    setSelected(!selected);
//}

void recipeButton::setSelected(bool selected) {
    this->selected = selected;
    if (selected) {
        setStyleSheet("QPushButton {border: 2px solid red};");
    } else {
        setStyleSheet("QPushButton {};");
    }
}

void recipeButton::onClicked()
{
    if (previousClickedRecipe != nullptr) {
        previousClickedRecipe->setStyleSheet("QPushButton {};");
    }
    setStyleSheet("QPushButton {border: 2px solid red};");
    previousClickedRecipe = this;
}
