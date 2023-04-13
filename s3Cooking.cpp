#include "s3Cooking.h"
#include "ui_s3Cooking.h"
#include <QPainter>
#include <QDebug>

s3Cooking::s3Cooking(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::s3Cooking),
    world(b2Vec2(0.0f, 10.0f)),
    timer(this),
    image(":/sprites/brick.png"),
    imageGrass(":/sprites/grass.png")
{
    ui->setupUi(this);
    //connect(ui->nextBtn, &QPushButton::clicked, this, &s3Cooking::nextPage);

    //Tzhou: box2d
    createGroundBody();
    createBoxes();
    connect(&timer, &QTimer::timeout, this, &s3Cooking::updateWorld);
    timer.start(10);
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
void s3Cooking::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    for(int i=0; i<10; i++)
    {
        int x =60;
        int y = 400;
        painter.drawImage(x*i, y, image);
    }

    for(Box b : boxes){
         b2Vec2 position = b.getBody()->GetPosition();
        //float angle1 = b.getBody()->GetAngle();
        //painter.rotate(angle1);
        painter.drawImage((int)(position.x*20), (int)(position.y*20), imageGrass);
    }

    painter.end();
}

void s3Cooking::updateWorld()
{
    world.Step(1.0/60.0, 6, 2);
    update();
}
void s3Cooking::createGroundBody()
{
    // Define the ground body.
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f, 28.0f); // y is where the floor

    // The body is also added to the world.
    b2Body* groundBody = world.CreateBody(&groundBodyDef);

    // Define the ground box shape.
    b2PolygonShape groundBox;

    // The extents are the half-widths of the box.
    groundBox.SetAsBox(50.0f, 10.0f);

    // Add the ground fixture to the ground body.
    groundBody->CreateFixture(&groundBox, 0.0f);
}

void s3Cooking::createBoxes()
{
    const int numBoxes = 10;

    for(int i =0; i<numBoxes; i++){
        Box b;
        float xrand = 0.0f + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/20.0f));
        float yrand = 15.0f + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/25.0f));
        b.init(&world, b2Vec2(xrand,-yrand ));
        boxes.push_back(b);
    }
}
