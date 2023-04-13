#ifndef BOX_H
#define BOX_H
#include<Box2D/Box2D.h>


class Box
{
public:
    Box();
    void init(b2World* world, const b2Vec2& position);
    b2Body *getBody();
    b2Fixture *getFixture();

private:
    b2Body* body=nullptr;
    b2Fixture* fixture = nullptr;
};

#endif // BOX_H
