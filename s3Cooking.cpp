#include "s3Cooking.h"
#include "QtGui/qevent.h"
#include "mycontactlistener.h"
#include "box2d.h"
#include "ui_s3Cooking.h"
#include <QPainter>
#include <QDebug>

s3Cooking::s3Cooking(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::s3Cooking),
    world(b2Vec2(0.0f, 10.0f)),
    timer(this),
    image(":/sprites/icons/brick.png"),
    imageGrass(":/sprites/icons/grass.png"),
    imageWok(":/sprites/icons/wok.png")
{
    ui->setupUi(this);

    //connect(ui->nextBtn, &QPushButton::clicked, this, &s3Cooking::nextPage);

    //AndyTran
//    imageWok = imageWok.scaled(100, 100, Qt::KeepAspectRatio);

    //Tzhou: box2d
    createWokBody();
    createGroundBody();
    createBoxes();
    connect(&timer, &QTimer::timeout, this, &s3Cooking::updateWorld);
    timer.start(10);

    // Add the collision listener to the world
    MyContactListener* listener = new MyContactListener(boxes);
    world.SetContactListener(listener);

    qDebug() << "Address of Boxes S3: " <<&boxes;

    //Ruini Tong add backgound image
    QPixmap image(":/sprites/icons/Kitchen.PNG");
    QLabel* background = ui->backgoundImage;
    background->setPixmap(image);
    background->setScaledContents(true); // Scale the image to fit the label
    background->setGeometry(QRect(0, 0, background->width(), background->height()));
    background->lower();

    connect(listener, &MyContactListener::cut, this, &s3Cooking::handleCut);

}

s3Cooking::~s3Cooking()
{
    delete ui;
}

void s3Cooking::nextPage()
{
    emit goToPage4();
}

//[==Animation==]@Tzhou
//void s3Cooking::paintEvent(QPaintEvent *)
//{
//    QPainter painter(this);

//    for(int i=0; i<10; i++)
//    {
//        int x =60;
//        int y = 400;
//        painter.drawImage(x*i, y, image);
//    }

//    for(Box b : boxes){
//         b2Vec2 position = b.getBody()->GetPosition();
//        //float angle1 = b.getBody()->GetAngle();
//        //painter.rotate(angle1);
//        painter.drawImage((int)(position.x*20), (int)(position.y*20), imageGrass);
//    }

//    painter.end();
//}

void s3Cooking::paintEvent(QPaintEvent *)
{

    QPainter painter(this);

    //Draw the ground box
    for (b2Fixture* f = wokBody->GetFixtureList(); f; f = f->GetNext()) {
        if (f->GetType() == b2Shape::e_polygon) {
            b2PolygonShape* shape = dynamic_cast<b2PolygonShape*>(f->GetShape());
            if (shape) {
                b2Vec2 vertices[b2_maxPolygonVertices];
                for (int i = 0; i < shape->m_count; ++i) {
                    vertices[i] = wokBody->GetWorldPoint(shape->m_vertices[i]);
                }
                painter.setPen(Qt::black);
                for (int i = 0; i < shape->m_count - 1; ++i) {
                    painter.drawLine((int)vertices[i].x*20, (int)vertices[i].y*20, (int)vertices[i+1].x*20, (int)vertices[i+1].y*20);
                }
                painter.drawLine((int)vertices[shape->m_count - 1].x*20, (int)vertices[shape->m_count - 1].y*20, (int)vertices[0].x*20, (int)vertices[0].y*20);
            }
        }
    }

    //Draw the ground box
    for (b2Fixture* f = groundBody->GetFixtureList(); f; f = f->GetNext()) {
        if (f->GetType() == b2Shape::e_polygon) {
            b2PolygonShape* shape = dynamic_cast<b2PolygonShape*>(f->GetShape());
            if (shape) {
                b2Vec2 vertices[b2_maxPolygonVertices];
                for (int i = 0; i < shape->m_count; ++i) {
                    vertices[i] = groundBody->GetWorldPoint(shape->m_vertices[i]);
                }
                painter.setPen(Qt::black);
                for (int i = 0; i < shape->m_count - 1; ++i) {
                    painter.drawLine((int)vertices[i].x*20, (int)vertices[i].y*20, (int)vertices[i+1].x*20, (int)vertices[i+1].y*20);
                }
                painter.drawLine((int)vertices[shape->m_count - 1].x*20, (int)vertices[shape->m_count - 1].y*20, (int)vertices[0].x*20, (int)vertices[0].y*20);
            }
        }
    }

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
        //qDebug() << "draw";
       b2Vec2 position = body->GetPosition();
       //qDebug()<< "body"<<&position;
       std::string ingredientName = static_cast<const char*>(body->GetUserData());
       if(ingredientName.compare("pieces") == 0){
            //qDebug() << "pieces";
            QImage pieces(":/sprites/icons/tomato_pieces.png");
//            QImage resizedImage = pieces.scaled(32, 32);
            painter.drawImage((int)(position.x*20), (int)(position.y*20), pieces);
//              painter.drawImage((int)(position.x*20), (int)(position.y*20), imageGrass);
        }else{
            painter.drawImage((int)(position.x*20), (int)(position.y*20), imageGrass);
       }

    }

    painter.end();


}

void s3Cooking::updateWorld()
{

    world.Step(1.0/60.0, 6, 2);
    //detect collide
    if(isCut){
        cut();
        //world.DestroyBody(body);
    }
//    if(body != nullptr){
//        for (b2ContactEdge* ce = body->GetContactList(); ce; ce = ce->next)
//        {
//            cut();
//            // process c
//            world.DestroyBody(body);
//        }
//    }

    update();
}

void s3Cooking::createGroundBody()
{
    // Define the ground body.
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(20.0f, 20.0f); // y is where the floor


    // The body is also added to the world.
    groundBody = world.CreateBody(&groundBodyDef);

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

void s3Cooking::createWokBody()
{
    // Define the ground body.
    b2BodyDef wokBodyDef;
    wokBodyDef.position.Set(20.0f, 20.0f); // y is where the floor

    // The body is also added to the world.
    wokBody = world.CreateBody(&wokBodyDef);

    // Define the ground box shape.
    b2PolygonShape groundBox;

    // The extents are the half-widths of the box.
    groundBox.SetAsBox(6.0f, 3.0f);

    // Add the ground fixture to the ground body.
    wokBody->CreateFixture(&groundBox, 0.0f);


}

//Ruini
void s3Cooking::mousePressEvent(QMouseEvent *event)
{
    qDebug() <<event->pos();
    if (event->button() == Qt::LeftButton) {
        Box tomato;
        tomato.init(&world, event->pos(), drawBodies);

        //tomato.init
        body = tomato.getBody();
        drawBodies.push_back(body);
        //bodies.push_back(&tomato);
        boxes.insert("tomato",&tomato);
        //tomato.setName("tomato");
//        if(boxes.contains("tomato")){
//            qDebug() << "tomato";
//            //tomato.getName();
//        }

        //Box* myBox = new Box(&world, event->pos(), drawBodies);
//        if (tomato.worldBox == &world) {
//            qDebug() << "Error: worldBox is null";
//        }
        //qDebug() <<event->pos();
    }
}

void s3Cooking::mouseMoveEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        for (auto& body : bodies) {
            body->updatePosition(event->pos());
        }
    }
    //qDebug() <<"move";
}

void s3Cooking::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug() <<event->pos();
}

//void MyContactListener::BeginContact(b2Contact* contact){
//    b2Body* bodyA = contact->GetFixtureA()->GetBody();
//    b2Body* bodyB = contact->GetFixtureB()->GetBody();



//}


void s3Cooking::createBoxes()
{
    const int numBoxes = 10;

    for(int i =0; i<numBoxes; i++){
        Box b;
        float xrand = 10.0f + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/20.0f));
        float yrand = 20.0f + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/25.0f));
        //b.init(&world, b2Vec2(xrand,-yrand ));
        //boxes.push_back(b);
    }
}

void s3Cooking::handleCut(std::string name){
    isCut = true;
}

void s3Cooking::cut() {

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
    //destroyParticles();
}

void s3Cooking::destroyParticles(){
    // Create a new timer object
    QTimer* timer = new QTimer(this);

    // Set the interval for the timer in milliseconds
    timer->setInterval(1000); // Timer fires every second

    // Connect the timeout() signal of the timer to a slot or lambda function that handles the event
    connect(timer, &QTimer::timeout, this, [this](){
        //destroy the particles
        for (int i = 0; i < particles.size(); i++) {
            b2Body* particle =particles.back();
            particles.pop_back();
            world.DestroyBody(particle);
        }
    });

    // Start the timer
    timer->start();
}
