#ifndef S3COOKING_H
#define S3COOKING_H

#include <QWidget>
#include <Box2D/Box2D.h>
#include <QTimer>
#include<Qlist>
#include<QVector>
#include<QGraphicsView>
#include<QGraphicsScene>
#include"ingredient.h"
#include"foodlibrary.h"
#include"ingredientbutton.h"
#include"draganddrop.h"
#include<random>


namespace Ui {
class s3Cooking;
}

class s3Cooking : public QWidget
{
    Q_OBJECT

public:
    explicit s3Cooking(QWidget *parent = nullptr);
    ~s3Cooking();

//    //Tzhou: play around
//    void paintEvent(QPaintEvent *);

//    //Ruini
//    void mousePressEvent(QMouseEvent *event);
//    void mouseMoveEvent(QMouseEvent *event);
//    void mouseReleaseEvent(QMouseEvent *event);

//    //Tzhou
//    void updateWorld();

public slots:
    void nextPage();

//    //Ruini
//    void handleCut(std::string name);

signals:
    void goToPage4();

private:
    Ui::s3Cooking *ui;

    //tzhou drag:
    QGraphicsScene* scene = new QGraphicsScene;
    void imageEnter(QPixmap pixmap, QGraphicsView *view);

//    //Tzhou
//    b2World world;
//    //vector<Box> boxes; Ruini edited
//    //QMap<string, Box*> boxes;
//    QTimer timer;
//    QImage image;
//    QImage imageTomato;

//    void createWokBody();
//    //void createBoxes();

//    //AndyTran
//    void createGroundBody();
//    QImage imageWok;
//    b2Body* wokBody;
//    b2Body* groundBody;

//    //Ruini
//    vector<b2Body*> drawBodies;
//    vector<b2Body*> particles;
//    QMap<string, b2Body*> boxes;
//    b2Body* body=nullptr;
//    bool isCut = false;// check if there's currently something need to be cut
//    void destroyParticles();
//    bool test = false;
//    bool isSelected = false;
//    b2Body* selectedObject;
//    void cut();
//    void createBox(QPoint pos,string name);
};

#endif // S3COOKING_H
