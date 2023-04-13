#include "box.h"

Box::Box()
{

}

void Box::init(b2World *world, const b2Vec2 &position)
{
    b2BodyDef bodyDef;
    bodyDef.type= b2_dynamicBody;
    bodyDef.position.Set(position.x, position.y);
    body = world->CreateBody(&bodyDef);

    b2PolygonShape boxShape;
    boxShape.SetAsBox(1.0f, 1.0f);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = & boxShape;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
     fixtureDef.restitution = 0.5;
    fixture = body->CreateFixture(&fixtureDef);
}

b2Body *Box::getBody()
{
    return body;
}

b2Fixture *Box::getFixture()
{
    return fixture;
}

