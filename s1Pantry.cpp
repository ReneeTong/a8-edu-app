#include "s1Pantry.h"
#include "ui_s1Pantry.h"

s1Pantry::s1Pantry(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::s1Pantry)
{
    ui->setupUi(this);
    connect(ui->nextBtn, &QPushButton::clicked, this, &s1Pantry::nextPage);


    // very messy implementation
    // we need to keep track of "filters" to apply
    connect(ui->evenBox, &QCheckBox::stateChanged, this, [this]() {
        if (ui->evenBox->isChecked()) {
            auto is_even = [](int x) { return x % 2 == 0; };
            ui->scrollArea->applyFilter(is_even);
        } else {
            ui->scrollArea->reset();
            if (ui->oddBox->isChecked()) {
                auto is_odd = [](int x) { return x % 2 == 1; };
                ui->scrollArea->applyFilter(is_odd);
            }
        }
    });

    connect(ui->oddBox, &QCheckBox::stateChanged, this, [this]() {
        if (ui->oddBox->isChecked()) {
            auto is_odd = [](int x) { return x % 2 == 1; };
            ui->scrollArea->applyFilter(is_odd);
        } else {
            ui->scrollArea->reset();
            if (ui->evenBox->isChecked()) {
                auto is_even = [](int x) { return x % 2 == 0; };
                ui->scrollArea->applyFilter(is_even);
            }
        }
    });

    //Tzhou: To make things even more sore to eyes
    connect(ui->veganBox, QCheckBox::stateChanged, this, [this](){
        if(ui->veganBox->isChecked()){
            auto is_vegan = [](Ingredient * i){return !i->getIsVegan();};
            ui->scrollArea->applyFilter(is_vegan);
        }else{
            ui->scrollArea->reset();
            if (ui->veganBox->isChecked()) {
               auto is_not_vegan = [](Ingredient * i){return i->getIsVegan();};
                ui->scrollArea->applyFilter(is_not_vegan);
            }
        }

    });

    connect(ui->allergyBox, QCheckBox::stateChanged, this, [this](){
        if(ui->allergyBox->isChecked()){
            auto is_allergy = [](Ingredient * i){return i->getIsNutAllergic();};
            ui->scrollArea->applyFilter(is_allergy);
        }else{
            ui->scrollArea->reset();
            if (ui->allergyBox->isChecked()) {
               auto is_not_allergy = [](Ingredient * i){return !i->getIsVegan();};
                ui->scrollArea->applyFilter(is_not_allergy);
            }
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
