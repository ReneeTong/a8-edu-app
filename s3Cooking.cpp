#include "s3Cooking.h"
#include "mycontactlistener.h"
#include "ui_s3Cooking.h"
#include <QPainter>
#include <QDebug>

s3Cooking::s3Cooking(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::s3Cooking),
    world(b2Vec2(0.0f, 10.0f)),
    timer(this),
    image(":/sprites/brick.png"),
    imageGrass(":/sprites/grass.png"),
    imageWok(":/sprites/wok.png")
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
    QPixmap image(":/sprites/Kitchen.PNG");
    QLabel* background = ui->backgoundImage;
    background->setPixmap(image);
    background->setScaledContents(true); // Scale the image to fit the label
    background->setGeometry(QRect(0, 0, background->width(), background->height()));
    background->lower();
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
    for(Box b : boxes){
         b2Vec2 position = b.getBody()->GetPosition();
        //float angle1 = b.getBody()->GetAngle();
        //painter.rotate(angle1);
        painter.drawImage((int)(position.x*20), (int)(position.y*20), imageGrass);
    }

    //Draw the imageWok at the position of the groundBody: TODO - Need to change to the pot
       b2Vec2 groundPos = wokBody->GetPosition();
       painter.drawImage((int)((groundPos.x*13)), (int)(groundPos.y*16), imageWok);


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
    groundBodyDef.position.Set(20.0f, 20.0f); // y is where the floor

    // The body is also added to the world.
    groundBody = world.CreateBody(&groundBodyDef);

    // Define the ground box shape.
    b2PolygonShape groundBox;

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


void s3Cooking::createBoxes()
{
    const int numBoxes = 10;

    for(int i =0; i<numBoxes; i++){
        Box b;
        float xrand = 10.0f + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/20.0f));
        float yrand = 20.0f + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/25.0f));
        b.init(&world, b2Vec2(xrand,-yrand ));
        boxes.push_back(b);
    }
}
