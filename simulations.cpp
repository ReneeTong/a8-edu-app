#include "simulations.h"
#include "QtGui/qevent.h"
#include "mycontactlistener.h"
#include <QPainter>
#include <QDebug>

simulations::simulations(QWidget *parent)
    : QWidget(parent),
      world(b2Vec2(0.0f, 10.0f)),
      timer(this),
      image(":/sprites/icons/brick.png"),
      imageTomato(":/sprites/icons/tomato.png"),
      imageWok(":/sprites/icons/Wok.PNG")
{
    qDebug() << "simulations";

    //Tzhou: box2d
    createWokBody();
    createGroundBody();
    //createBoxes();
    connect(&timer, &QTimer::timeout, this, &simulations::updateWorld);
    timer.start(10);

    // Add the collision listener to the world
    MyContactListener* listener = new MyContactListener(boxes);
    world.SetContactListener(listener);

    qDebug() << "Address of Boxes S3: " <<&boxes;

    connect(listener, &MyContactListener::cut, this, &simulations::handleCut);
//    connect(ui->tomato, &QPushButton::clicked, this, [this]{
//        test = true;
//    } );
    testTrue();
}

void simulations::testTrue(){
    test = true;
}

void simulations::paintEvent(QPaintEvent *)
{

    QPainter painter(this);

//    //Draw the ground box
//    for (b2Fixture* f = wokBody->GetFixtureList(); f; f = f->GetNext()) {
//        if (f->GetType() == b2Shape::e_polygon) {
//            b2PolygonShape* shape = dynamic_cast<b2PolygonShape*>(f->GetShape());
//            if (shape) {
//                b2Vec2 vertices[b2_maxPolygonVertices];
//                for (int i = 0; i < shape->m_count; ++i) {
//                    vertices[i] = wokBody->GetWorldPoint(shape->m_vertices[i]);
//                }
//                painter.setPen(Qt::black);
//                for (int i = 0; i < shape->m_count - 1; ++i) {
//                    painter.drawLine((int)vertices[i].x*20, (int)vertices[i].y*20, (int)vertices[i+1].x*20, (int)vertices[i+1].y*20);
//                }
//                painter.drawLine((int)vertices[shape->m_count - 1].x*20, (int)vertices[shape->m_count - 1].y*20, (int)vertices[0].x*20, (int)vertices[0].y*20);
//            }
//        }
//    }

//    //Draw the ground box
//    for (b2Fixture* f = groundBody->GetFixtureList(); f; f = f->GetNext()) {
//        if (f->GetType() == b2Shape::e_polygon) {
//            b2PolygonShape* shape = dynamic_cast<b2PolygonShape*>(f->GetShape());
//            if (shape) {
//                b2Vec2 vertices[b2_maxPolygonVertices];
//                for (int i = 0; i < shape->m_count; ++i) {
//                    vertices[i] = groundBody->GetWorldPoint(shape->m_vertices[i]);
//                }
//                painter.setPen(Qt::black);
//                for (int i = 0; i < shape->m_count - 1; ++i) {
//                    painter.drawLine((int)vertices[i].x*20, (int)vertices[i].y*20, (int)vertices[i+1].x*20, (int)vertices[i+1].y*20);
//                }
//                painter.drawLine((int)vertices[shape->m_count - 1].x*20, (int)vertices[shape->m_count - 1].y*20, (int)vertices[0].x*20, (int)vertices[0].y*20);
//            }
//        }
//    }

    //Draw the ingredients: TODO - Need to change imageGrass to the picked ingredients
//    for(Box b : boxes){
//         b2Vec2 position = b.getBody()->GetPosition();
//        //float angle1 = b.getBody()->GetAngle();
//        //painter.rotate(angle1);
//        painter.drawImage((int)(position.x*20), (int)(position.y*20), imageGrass);
//    }

    //Draw the imageWok at the position of the groundBody: TODO - Need to change to the pot
       b2Vec2 groundPos = wokBody->GetPosition();
       painter.drawImage((int)((groundPos.x*13)), (int)(groundPos.y*16), imageWok);


   //draw the object
    for (auto& body : drawBodies) {
       b2Vec2 position = body->GetPosition();
       std::string ingredientName = static_cast<const char*>(body->GetUserData());

       //draw image based on the object
       if(ingredientName.compare("pieces") == 0){
            QImage pieces(":/sprites/icons/tomato_pieces.png");
//            QImage resizedImage = pieces.scaled(32, 32);
            painter.drawImage((int)(position.x*20), (int)(position.y*20), pieces);
        }else{
            painter.drawImage((int)(position.x*20), (int)(position.y*20), imageTomato);
       }

    }

    painter.end();


}

void simulations::updateWorld()
{

    world.Step(1.0/60.0, 6, 2);

    //handle collision, add to the world in between callback loop
    if(isCut){
        //destroyParticles();
        cut();
        //world.DestroyBody(body);
    }
    update();
}

void simulations::createGroundBody()
{
    // Define the ground body.
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(15.0f, 27.0f); // y is where the floor


    // The body is also added to the world.
    groundBody = world.CreateBody(&groundBodyDef);

    const char* userDataString = "ground";
    char* userDataChar = new char[strlen(userDataString) + 1];
    strcpy(userDataChar, userDataString);
    groundBody->SetUserData(userDataChar);


    // Define the ground box shape.
    b2PolygonShape groundBox;

    //Ruini add
    b2FixtureDef groundFixtureDef;
    groundFixtureDef.shape = &groundBox;
    groundFixtureDef.isSensor = true;

    // The extents are the half-widths of the box.
    groundBox.SetAsBox(15.0f, 1.5f);


    // Add the ground fixture to the ground body.
    groundBody->CreateFixture(&groundBox, 0.0f);
}

void simulations::createWokBody()
{
    // Define the ground body.
    b2BodyDef wokBodyDef;
    wokBodyDef.position.Set(16.0f, 27.0f); // y is where the floor

    // The body is also added to the world.
    wokBody = world.CreateBody(&wokBodyDef);

    const char* userDataString = "wok";
    char* userDataChar = new char[strlen(userDataString) + 1];
    strcpy(userDataChar, userDataString);
    wokBody->SetUserData(userDataChar);

    // Define the ground box shape.
    b2PolygonShape groundBox;

    // The extents are the half-widths of the box.
    groundBox.SetAsBox(6.0f, 3.0f);

    // Add the ground fixture to the ground body.
    wokBody->CreateFixture(&groundBox, 0.0f);


}

//Ruini
void simulations::mousePressEvent(QMouseEvent *event)
{
    //qDebug() <<event->pos();
    if (event->button() == Qt::LeftButton) {
        createBox(event->pos(), "tomato");
        //mouse position convert to box2d coordinates
        b2Vec2 pos(event->pos().x()/20, event->pos().y()/20);
        if(test == true){
            createBox(event->pos(), "tomato");
            test = false;
        }else{
            for (auto &key : boxes.keys()) {
                b2Body* current = boxes.value(key);
                if(current != nullptr && current->GetType() == b2_dynamicBody){
                    for (b2Fixture* fixture = current->GetFixtureList(); fixture; fixture = fixture->GetNext()) {
                        //check if mouse coordinate is within the object
                        if (fixture->TestPoint(pos)) {
                            qDebug() << key[0];
                            selectedObject = current;
                            isSelected = true;
                            //return;
                        }
//                        else if (fixture->RayCast(&output, input, 0)) {
//                            // The ray cast intersects this fixture
//                            // You can use this information to determine which object was clicked
//                            // For example, you can use the body's user data to identify the object
//                            qDebug() << "Object clicked";
//                            return;
//                        }
                    }
                }

            }
        }


        //qDebug() <<event->pos();
    }
}

void simulations::mouseMoveEvent(QMouseEvent *event) {
    //qDebug() <<"move";
    b2Vec2 pos(event->pos().x()/20, event->pos().y()/20);
    //qDebug() << selectedObject[0];
    if(isSelected){
         selectedObject->SetTransform(pos, selectedObject->GetAngle());
    }

}

void simulations::mouseReleaseEvent(QMouseEvent *event)
{
    //qDebug() <<event->pos();
    //createBox(event->pos(), "tomato");
}

//void s3Cooking::createBoxes()
//{
//    const int numBoxes = 10;

//    for(int i =0; i<numBoxes; i++){
//        Box b;
//        float xrand = 10.0f + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/20.0f));
//        float yrand = 20.0f + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/25.0f));
//        //b.init(&world, b2Vec2(xrand,-yrand ));
//        //boxes.push_back(b);
//    }
//}

void simulations::createBox(QPoint pos, std::string name)
{
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;

    //convert qt coordinate to box2D coordinate
    int x = pos.x();
    int y = pos.y();

    float scale = 20;
    float bx = x /scale;
    float by = y /scale;

    bodyDef.position.Set(bx, by);
    body = world.CreateBody(&bodyDef);

    //store the user data
    const char* userDataString = "tomato";
    char* userDataChar = new char[strlen(userDataString) + 1];
    strcpy(userDataChar, userDataString);
    body->SetUserData(userDataChar);

    drawBodies.push_back(body);
    boxes.insert(name, body);

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

}

void simulations::handleCut(std::string name){
    isCut = true;
}

void simulations::cut() {

    //qDebug()<< "cut" << &worldBox;
    //b2World world = *worldBox;
    b2Vec2 velocity(1.0f, 2.0f);
    //QPoint position(body->GetPosition().x*20, body->GetPosition().y*20);
    b2Body* current = body;
    for (int i = 0; i < 4; i++) {

        //get a random position for particles
        std::random_device rd; // obtain a random seed from the hardware
        std::mt19937 gen(rd()); // initialize the random number engine with the seed
        std::uniform_int_distribution<> dist(1, 100); // define the range of the distribution

        //create new particles
        b2BodyDef bodyDef;
        bodyDef.type = b2_dynamicBody;
        bodyDef.position.Set(body->GetPosition().x + dist(gen) % 10 - 5, body->GetPosition().y + dist(gen) % 10 - 5);
        bodyDef.linearVelocity.Set(velocity.x + dist(gen) % 20 - 10, velocity.y + dist(gen) % 20 - 10);
        b2Body* particle = world.CreateBody(&bodyDef);

        //destroy the biggiest ingredient
        if(i == 0){
            world.DestroyBody(current);
        }

        //store user data for particles
        const char* userDataString = "pieces";
        char* userDataChar = new char[strlen(userDataString) + 1];
        strcpy(userDataChar, userDataString);
        particle->SetUserData(userDataChar);

        particles.push_back(particle);
        drawBodies.push_back(particle);
        //qDebug() << "cut";

        //set particles's fixture
        b2PolygonShape dynamicBox;
        dynamicBox.SetAsBox(1.0f, 1.0f);
        b2FixtureDef fixtureDef;
        fixtureDef.shape = &dynamicBox;
        fixtureDef.density = 1.0;
        fixtureDef.friction = 0.3f;
        fixtureDef.restitution = 0.5;
        particle->CreateFixture(&fixtureDef);
    }
    isCut = false;

}

void simulations::destroyParticles(){

    //destroy current particles
    int size = particles.size();
    for (int i = 0;i < size; i++) {
        b2Body* particle =particles.back();
        particles.pop_back();
        world.DestroyBody(particle);
    }

}
