#include "s1Pantry.h"
#include "ingredientbutton.h"
#include "ui_s1Pantry.h"

#include "ingredient.h"

s1Pantry::s1Pantry(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::s1Pantry)
{
    ui->setupUi(this);
    connect(ui->nextBtn, &QPushButton::clicked, this, &s1Pantry::nextPage);

    auto is_even = [](QWidget* widget) {
        QPushButton *button = dynamic_cast<QPushButton*>(widget);
        int number = button->text().toInt();

        return number % 2 == 0;
    };

    auto is_odd = [](QWidget* widget) {
        QPushButton *button = dynamic_cast<QPushButton*>(widget);
        int number = button->text().toInt();

        return number % 2 == 1;
    };

    connect(ui->evenBox, &QCheckBox::stateChanged, this, [this, is_even]() {
        bool checked = ui->evenBox->isChecked();
        if (checked) {
            ui->scrollArea->addFilter(is_even);
        } else {
            ui->scrollArea->removeFilter(is_even);
        }
    });

    connect(ui->oddBox, &QCheckBox::stateChanged, this, [this, is_odd]() {
        bool checked = ui->oddBox->isChecked();
        if (checked) {
            ui->scrollArea->addFilter(is_odd);
        } else {
            ui->scrollArea->removeFilter(is_odd);
        }
    });

    // create Ingredient
    class FoodLibrary f;

    // bind a "dynamic property" to link the QWidget to an Ingredient
    // add button to ScrollCarousel

    QTimer::singleShot(0, this, [this, f](){
        for (int i = 0; i < 25; i++) {
            int index = rand() % f.getAllIngredients().size();
            Ingredient *ingredient = f.getAllIngredients()[index];

            IngredientButton *button = new IngredientButton(*ingredient, 75);
            button->setText(QString::number(i));
            button->setProperty("Ingredient", QVariant::fromValue(ingredient));

            ui->scrollArea->addWidget(button);
        }
    });

    // creating a filter, checking the Widget's Ingredient
    auto is_peanut = [](QWidget* widget) {
        Ingredient* ingredientFromWidget = qvariant_cast<Ingredient*>(widget->property("Ingredient"));
        if (ingredientFromWidget){
            for(FoodTags tag: ingredientFromWidget->getTags()){
                if(tag==NUT)
                    return false;
            }
        }
        return true;
    };

    // link checkbox with ScrollCarousel's Filter
    connect(ui->allergyBox, &QCheckBox::stateChanged, this, [this, is_peanut]() {
        bool checked = ui->allergyBox->isChecked();
        if (checked) {
            ui->scrollArea->addFilter(is_peanut);
        } else {
            ui->scrollArea->removeFilter(is_peanut);
        }
    });


    auto is_vegan = [](QWidget* widget) {
        IngredientButton *button = dynamic_cast<IngredientButton*>(widget);
        if (button) {
            Ingredient ingredient = button->getIngredient();
            for(FoodTags tag : ingredient.getTags()){
                if(tag==VEGAN)
                    return true;
            }
            return false;
        } else {
            return true;
        }
    };

    connect(ui->veganBox, &QCheckBox::stateChanged, this, [this, is_vegan]() {
        bool checked = ui->veganBox->isChecked();
        if (checked) {
            ui->scrollArea->addFilter(is_vegan);
        } else {
            ui->scrollArea->removeFilter(is_vegan);
        }
    });

}

s1Pantry::~s1Pantry()
{
    delete ui;
}

void s1Pantry::nextPage()
{
    emit goToPage2();
}
