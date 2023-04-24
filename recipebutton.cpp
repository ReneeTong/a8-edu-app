#include "recipebutton.h"
#include "ui_recipebutton.h"

recipeButton* recipeButton::previousClickedRecipe = nullptr;


recipeButton::recipeButton(const Recipe &recipe, QWidget *parent, const QList<Ingredient *> &selectedIngredients) :
    QPushButton(parent),
    ui(new Ui::RecipeButton)
{
    ui->setupUi(this);
    setObjectName("mainRecipeButton");

    Recipe recipeCopy = recipe;
    this->recipe = new Recipe(recipe);

    ui->matchingList->setEnabled(false);
    ui->recipeName->setText(recipe.getName());
    ui->recipeDifficulty->setValue(recipe.getDifficulty());
    ui->recipeDifficulty->setRange(0, 100); // Set range from 0 to 100
    ui->recipeDifficulty->setValue((recipe.getDifficulty() * 100) / 5); // Calculate the percentage based on difficulty level
    setFixedSize(350,425);
    ui->difficultyLab->setText(QString("Difficulty: %1/5").arg(recipe.getDifficulty()));

     populateIngredientsList(recipe.getIngredients(), selectedIngredients);

    connect(ui->aboutBtn, &QPushButton::clicked, this, [this, &recipe]() {
        QMessageBox msgBox(this);

        // Set up the messagebox style
        QString msgBoxStyle = "QMessageBox {"
                              "background-color: #333333;"
                              "border: 2px solid #555555;"
                              "border-radius: 8px;"
                              "}"
                              "QLabel {"
                              "color: #ffffff;"
                              "}"
                              "QPushButton {"
                              "background-color: #555555;"
                              "color: #ffffff;"
                              "border: 1px solid #666666;"
                              "border-radius: 4px;"
                              "padding: 4px;"
                              "}"
                              "QPushButton:hover {"
                              "background-color: #888888;"
                              "}"
                              "QPushButton:pressed {"
                              "background-color: #444444;"
                              "}";
        msgBox.setStyleSheet(msgBoxStyle);

        msgBox.setWindowTitle("Learn more");
        msgBox.setInformativeText(recipe.getLearnMore());
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setTextFormat(Qt::RichText);

        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
    });

    connect(ui->stepsBtn, &QPushButton::clicked, this, [this, &recipe]() {
        QMessageBox msgBox(this);
        msgBox.setWindowTitle("Step By Step");
        msgBox.setText(recipe.getDescription());
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
    });

    connect(this, &recipeButton::ingredientsReadySignal, this, [this, recipe, selectedIngredients]() {
        populateIngredientsList(recipe.getIngredients(), selectedIngredients);
    });

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

bool recipeButton::isIngredientChosen(const Ingredient &recipeIngredient, const QList<Ingredient *> &selectedIngredients)
{
    for (Ingredient *selectedIngredient : selectedIngredients) {
        if (recipeIngredient == *selectedIngredient) {
            return true;
        }
    }
    return false;

}

void recipeButton::populateIngredientsList(const QList<Ingredient *> &recipeIngredients, const QList<Ingredient *> &selectedIngredients)
{
    int matchingIngredientsCount = 0;
    int totalIngredientsCount = 0;

    for (Ingredient *recipeIngredient : recipeIngredients)
    {
        QListWidgetItem *listItem = new QListWidgetItem(ui->matchingList);
        listItem->setText(recipeIngredient->getName());

        qDebug() << "*recipeIngredient: " << recipeIngredient->getName();
        qDebug() << "selectedIngredients: " << recipeIngredient->getName();
        if (isIngredientChosen(*recipeIngredient, selectedIngredients))
        {
            listItem->setForeground(Qt::green);
            matchingIngredientsCount++;
        }
        else
        {
            listItem->setForeground(Qt::gray);
        }

        ui->matchingList->addItem(listItem);
        totalIngredientsCount++;
    }

    ui->matchingLab->setText(QString("%1/%2").arg(matchingIngredientsCount).arg(totalIngredientsCount));
}

bool recipeButton::getSelected() const {
    return selected;
}

void recipeButton::setSelected(bool selected) {
    this->selected = selected;
    if (selected) {
        setStyleSheet("recipeButton {border: 2px solid rgba(0, 255, 0, 0.5);}");
    } else {
        setStyleSheet("recipeButton {};");
    }
}

void recipeButton::onClicked()
{
    if (previousClickedRecipe != nullptr) {
        previousClickedRecipe->setStyleSheet("");
        setStyleSheet("recipeButton {border: 2px solid rgba(0, 255, 0, 0.5);}");
        previousClickedRecipe = this;
    }
}


