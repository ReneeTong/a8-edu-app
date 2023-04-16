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
    Ingredient peanut("peanut", "condiment", true, true);

    // bind a "dynamic property" to link the QWidget to an Ingredient
    // add button to ScrollCarousel
    IngredientButton *button = new IngredientButton(peanut, 75);
    QTimer::singleShot(0, this, [this, button](){ ui->scrollArea->addWidget(button); });
    button->setProperty("Ingredient", QVariant::fromValue(&peanut));

    // creating a filter, checking the Widget's Ingredient
    auto is_peanut = [](QWidget* widget) {
        Ingredient* ingredientFromWidget = qvariant_cast<Ingredient*>(widget->property("Ingredient"));
        if (ingredientFromWidget)
            return ingredientFromWidget->getIsNutAllergic();
        else
            return false;
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


    //Tzhou: To make things even more sore to eyes
//    connect(ui->veganBox, &QCheckBox::stateChanged, this, [this](){
//        if(ui->veganBox->isChecked()){
//            auto is_vegan = [](Ingredient * i){return !i->getIsVegan();};
//            ui->scrollArea->applyFilter(is_vegan);
//        }else{
//            ui->scrollArea->reset();
//            if (ui->veganBox->isChecked()) {
//               auto is_not_vegan = [](Ingredient * i){return i->getIsVegan();};
//                ui->scrollArea->applyFilter(is_not_vegan);
//            }
//        }

//    });

//    connect(ui->allergyBox, &QCheckBox::stateChanged, this, [this](){
//        if(ui->allergyBox->isChecked()){
//            auto is_allergy = [](Ingredient * i){return i->getIsNutAllergic();};
//            ui->scrollArea->applyFilter(is_allergy);
//        }else{
//            ui->scrollArea->reset();
//            if (ui->allergyBox->isChecked()) {
//               auto is_not_allergy = [](Ingredient * i){return !i->getIsVegan();};
//                ui->scrollArea->applyFilter(is_not_allergy);
//            }
//        }

//    });
}

s1Pantry::~s1Pantry()
{
    delete ui;
}

void s1Pantry::nextPage()
{
    emit goToPage2();
}
