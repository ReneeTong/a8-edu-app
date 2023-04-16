
#include "ingredient.h"

ingredient::ingredient(std::string name, std::string category, std::string color, std::string image, std::vector<std::string> tags, b2BodyDef box2ddef)
    : name(name), category(category), color(color), image(image), tags(tags), box2ddef(box2ddef) {}

//All getter methods:
std::string ingredient::getName() const {
    return name;
}

std::string ingredient::getCategory() const {
    return category;
}

std::string ingredient::getColor() const {
    return color;
}

std::string ingredient::getImage() const {
    return image;
}

std::vector<std::string> ingredient::getTags() const {
    return tags;
}

b2BodyDef ingredient::getBox2dDef() const {
    return box2ddef;
}
