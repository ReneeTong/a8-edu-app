
#include "box.h"
#include "QtCore/qdebug.h"
#include <QPainter>
#include <random>
Box::Box()
{
}


void Box:: init(b2World* world, QPoint pos, std::vector<b2Body*>& drawBodies)
{
    worldBox = world;
//    this->drawBodies = &drawBodies;

//    qDebug()<< "init" << &world;
//    qDebug()<< "init" << &worldBox;

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;

    //convert qt coordinate to box2D coordinate
    int x = pos.x();
    int y = pos.y();

    //y = this->height() - y;

    float scale = 20;
    float bx = x /scale;
    float by = y /scale;

    bodyDef.position.Set(bx, by);

    body = worldBox->CreateBody(&bodyDef);

    //store the user data
    const char* userDataString = "tomato";
    char* userDataChar = new char[strlen(userDataString) + 1];
    strcpy(userDataChar, userDataString);
    body->SetUserData(userDataChar);

    drawBodies.push_back(body);

    // Define another box shape for our dynamic body.
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(1.0f, 1.0f);

    // Define the dynamic body fixture.
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;

    // Set the box density to be non-zero, so it will be dynamic.
    fixtureDef.density = 1.0f;

    // Override the default friction.
    fixtureDef.friction = 0.3f;
    fixtureDef.restitution = 0.8;
    // Add the shape to the body.
    body->CreateFixture(&fixtureDef);


    body->ApplyTorque(20,false);
    //body->ApplyAngularImpulse(20,true);
    printf("Init world\n");

    //cut(worldBox, drawBodies);

}

//void Box::setName(std::string name){
//    //this->name = name;
//    qDebug() << name[0];
//}

//std::string Box::getName(){
//    //qDebug() << &name;
//    return name;
//}

void Box ::updatePosition(QPoint pos){
    int x = pos.x();
    int y = pos.y();

    //y = this->height() - y;

    float scale = 20;
    float bx = x /scale;
    float by = y /scale;

    //body->position.Set(bx, by);
    b2Vec2 vec (bx, by);
    body->SetTransform(vec, 0);
}

b2Body *Box::getBody()
{
    return body;
}

b2Fixture *Box::getFixture()
{
    return fixture;
}

void Box::cut(b2World* world, std::vector<b2Body*>& drawBodies) {

    //qDebug()<< "cut" << &worldBox;
    //b2World world = *worldBox;
    b2Vec2 velocity(1.0f, 2.0f);
    for (int i = 0; i < 5; i++) {
        b2BodyDef bodyDef;
        bodyDef.type = b2_dynamicBody;
        std::random_device rd; // obtain a random seed from the hardware
        std::mt19937 gen(rd()); // initialize the random number engine with the seed
        std::uniform_int_distribution<> dist(1, 100); // define the range of the distribution

        bodyDef.position.Set(body->GetPosition().x - 20 + dist(gen) % 10 - 5, body->GetPosition().y + dist(gen) % 10 - 5);
        bodyDef.linearVelocity.Set(velocity.x + dist(gen) % 20 - 10, velocity.y + dist(gen) % 20 - 10);
        b2Body* particle = world->CreateBody(&bodyDef);
        drawBodies.push_back(particle);
        qDebug() << "cut";
        b2CircleShape circle;
        circle.m_radius = 0.1;
        b2PolygonShape dynamicBox;
        dynamicBox.SetAsBox(1.0f, 1.0f);
        b2FixtureDef fixtureDef;
        fixtureDef.shape = &dynamicBox;
        fixtureDef.density = 1.0;
        fixtureDef.friction = 0.3f;
        fixtureDef.restitution = 0.5;
        particle->CreateFixture(&fixtureDef);
    }
}
