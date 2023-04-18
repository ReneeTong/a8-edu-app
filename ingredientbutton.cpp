#include "ingredientbutton.h"

IngredientButton::IngredientButton(Ingredient ingredient, int size, QWidget *parent) : QPushButton(parent), ingredient(ingredient) {
    //setStyleSheet("IngredientButton {background-color: transparent;};");
    setFixedSize(size, size);

    selected = false;

    QPixmap pixmap = ingredient.getPixmap();
    QIcon icon(pixmap);
    setIcon(icon); // maybe ingredient does not need a pixmap? convert to icon for you?
    setIconSize(QSize(40, 40));
    // setIconSize(this->size());

    connect(this, &QPushButton::clicked, this, [this]() {
        setSelected(!getSelected());
    });
}


Ingredient IngredientButton::getIngredient() const {
    return ingredient;
}

bool IngredientButton::getSelected() const {
    return selected;
}

void IngredientButton::setSelected(bool selected) {
    this->selected = selected;
    if (selected) {
        setStyleSheet("QPushButton {border: 2px solid red};");
    } else {
        setStyleSheet("QPushButton {};");
    }
}
