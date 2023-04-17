#ifndef BOX_H
#define BOX_H
#include "QtCore/qpoint.h"
#include<Box2D/Box2D.h>
#include <vector>

class Box
{
public:
    Box();
    void init(b2World& world, QPoint pos, std::vector<b2Body*> drawBodies);
    b2Body *getBody();
    b2Fixture *getFixture();
    void cut(const b2Vec2& position, const b2Vec2& velocity);
    void updatePosition(QPoint pos);

private:
    b2Body* body=nullptr;
    b2Fixture* fixture = nullptr;
    b2World* world = nullptr;
    std::vector<b2Body*>* drawBodies = nullptr;
};

#endif // BOX_H
