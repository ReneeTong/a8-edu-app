#include "ingredientbutton.h"

IngredientButton::IngredientButton(Ingredient ingredient, int size, QWidget *parent) : QPushButton(parent) {
    setStyleSheet("IngredientButton {background-color: transparent;};");

    setFixedSize(size, size);

    QPixmap pixmap = ingredient.getPixmap();
    QIcon icon(pixmap);

    setIcon(icon); // maybe ingredient does not need a pixmap? convert to icon for you?
    setIconSize(this->size());
}
