
#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>
#include <vector>
#include <Box2D/Box2D.h>


class ingredient
{
public:
    ingredient(std::string name, std::string category, std::string color, std::string image, std::vector<std::string> tags, b2BodyDef box2ddef );

    // Getter methods
    std::string getName() const;
    std::string getCategory() const;
    std::string getColor() const;
    std::string getImage() const;
    std::vector<std::string> getTags() const;
    b2BodyDef getBox2dDef() const;

private:
    std::string name;
    std::string category;
    std::string color;
    std::string image;
    std::vector<std::string> tags;
    b2BodyDef box2ddef;
};

#endif // INGREDIENT_H
