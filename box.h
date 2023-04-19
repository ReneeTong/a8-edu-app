#ifndef BOX_H
#define BOX_H
#include "QtCore/qpoint.h"
#include<Box2D/Box2D.h>
#include <vector>

class Box
{
public:
    Box();
    void init(b2World* world, QPoint pos, std::vector<b2Body*>& drawBodies);

    b2Body *getBody();
    b2Fixture *getFixture();

    void cut(b2World* world, std::vector<b2Body*>& drawBodies);
    void updatePosition(QPoint pos);

    b2World* worldBox = nullptr;

private:
    b2Body* body=nullptr;
    b2Fixture* fixture = nullptr;

    std::vector<b2Body*>* drawBodies = nullptr;
};

#endif // BOX_H
