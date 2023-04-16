#include "s1Pantry.h"
#include "ui_s1Pantry.h"

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

    // very messy implementation
    // we need to keep track of "filters" to apply
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
