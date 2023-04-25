#include "recipebutton.h"
#include "ui_recipebutton.h"

recipeButton::recipeButton(RecipeNew *recipe, QList<Ingredient*> pantry, QWidget *parent) :
    QPushButton(parent),
    ui(new Ui::RecipeButton),
    m_recipe(recipe)
{
    ui->setupUi(this);
    setObjectName("mainRecipeButton");
    setFixedSize(400,425);

    setTitle(recipe->getName());
    setDescription(recipe->getDescription());
    setLearnMore(recipe->getLearnMore());
    setDifficulty(recipe->getDifficulty());
    setPixmap(recipe->getPixmap());
    setIngredientList(recipe->getIngredeints(), pantry);

    connect(this, &QPushButton::clicked, this, [this]() {
        setSelected(!getSelected());
    });
}

// [== ABSTRACTION ADDED BY JEFFREY ==]
void recipeButton::setTitle(QString text) {
    ui->recipeName->setText(text);
};

void recipeButton::setDescription(QString text) {
    connect(ui->stepsBtn, &QPushButton::clicked, this, [this, text]() {
        QMessageBox *msgBox = new QMessageBox(this);
        msgBox->setWindowTitle("Step By Step");
        msgBox->setText(text);
        msgBox->setStandardButtons(QMessageBox::Ok);
        msgBox->exec();
    });
};

void recipeButton::setLearnMore(QString text) {
    connect(ui->aboutBtn, &QPushButton::clicked, this, [this, text]() {
        QMessageBox *msgBox = new QMessageBox(this);

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
        msgBox->setStyleSheet(msgBoxStyle);

        msgBox->setWindowTitle("Learn more");
        msgBox->setInformativeText(text);
        msgBox->setStandardButtons(QMessageBox::Ok);
        msgBox->setTextFormat(Qt::RichText);

        msgBox->setStandardButtons(QMessageBox::Ok);
        msgBox->exec();
    });
};

void recipeButton::setDifficulty(int difficulty) {
    ui->recipeDifficulty->setValue(difficulty);

    QString text = "Difficulty: %1/5";
    text = text.arg(difficulty);
    ui->difficultyLab->setText(text);
};

void recipeButton::setPixmap(QPixmap pixmap){
    ui->imageLab->setPixmap(pixmap);
    ui->imageLab->setScaledContents(true);
};

void recipeButton::setIngredientList(QList<Ingredient> ingredients, QList<Ingredient*> pantry) {
    matchingCount = 0;
    for (const auto &ingredient : ingredients) {
        QListWidgetItem *listItem = new QListWidgetItem(ui->matchingList);
        listItem->setText(ingredient.getName());

        listItem->setForeground(Qt::gray);
        for (const auto& selected : pantry) {
            if (selected->getName() == ingredient.getName()) {
                listItem->setForeground(Qt::green);
                matchingCount++;
                break;
            }
        }
    }

    QString matchingText = "%1/%2";
    matchingText = matchingText.arg(matchingCount);
    matchingText = matchingText.arg(ingredients.size());
    ui->matchingLab->setText(matchingText);
};

// [== END ==]

recipeButton::~recipeButton()
{
    delete ui;
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





