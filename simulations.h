#ifndef SIMULATIONS_H
#define SIMULATIONS_H

#include <QWidget>
#include <Box2D/Box2D.h>
#include <QTimer>
#include<Qlist>
#include<vector>
#include<random>
#include "mycontactlistener.h"

class simulations : public QWidget
{
    Q_OBJECT
public:
    explicit simulations(QWidget *parent = nullptr);

    //Tzhou: play around
    void paintEvent(QPaintEvent *);

    //Ruini
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

    MyContactListener* listener;

    //Tzhou
    void updateWorld();

public slots:

    //Ruini
    void handleCut(std::string name);
    void testTrue();

signals:

private:
    //Tzhou
    b2World world;
    //vector<Box> boxes; Ruini edited
    //QMap<string, Box*> boxes;
    QTimer timer;
    QImage image;
    QImage imageTomato;

    void createWokBody();
    //void createBoxes();

    //AndyTran
    void createGroundBody();
    QImage imageWok;
    b2Body* wokBody;
    b2Body* groundBody;

    //Ruini
    std::vector<b2Body*> drawBodies;
    std::vector<b2Body*> particles;
    QMap<std::string, b2Body*> boxes;
    b2Body* body=nullptr;
    bool isCut = false;// check if there's currently something need to be cut
    void destroyParticles();
    bool test = false;
    bool isSelected = false;
    b2Body* selectedObject;
    void cut();
    void createBox(QPoint pos,std::string name);

};

#endif // SIMULATIONS_H
