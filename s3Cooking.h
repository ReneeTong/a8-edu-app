#ifndef S3COOKING_H
#define S3COOKING_H

#include <QWidget>
#include <Box2D/Box2D.h>
#include <QTimer>
#include<Qlist>
#include<vector>
#include<random>
#include"box.h"
using namespace std;

namespace Ui {
class s3Cooking;
}

class s3Cooking : public QWidget
{
    Q_OBJECT

public:
    explicit s3Cooking(QWidget *parent = nullptr);
    ~s3Cooking();

    //Tzhou: play around
    void paintEvent(QPaintEvent *);

    //Ruini
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

public slots:
    void nextPage();

    //Tzhou
    void updateWorld();

signals:
    void goToPage4();

private:
    Ui::s3Cooking *ui;


    //Tzhou
    b2World world;
    vector<Box> boxes;
    QTimer timer;
    QImage image;
    QImage imageGrass;

    void createWokBody();
    void createBoxes();

    //AndyTran
    void createGroundBody();
    QImage imageWok;
    b2Body* wokBody;
    b2Body* groundBody;

    //Ruini
    std::vector<b2Body*> drawBodies;
    std::vector<Box*> bodies;
    b2Body* body=nullptr;
};

#endif // S3COOKING_H
