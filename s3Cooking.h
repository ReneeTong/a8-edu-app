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
//#include"foodlibrary.h"
#include"ingredientbutton.h"
#include"draganddrop.h"
#include<random>
#include "Model.h"

namespace Ui {
class s3Cooking;
}

class s3Cooking : public QWidget
{
    Q_OBJECT

public:
    explicit s3Cooking(Model& model, QWidget *parent = nullptr);
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

    //Andy Tran: receiving s3 update method
    void onS3Update(int curStep, QHash<Ingredient*, int>* todoList);

    //Ruini
    void mouseRelease(QPoint pos);
signals:
    void goToPage4();

    //Ruini: moved this to contact listner
    //Andy Tran: sending s3 update method
//    void onStepCookingUpdate(Ingredient, Action);
private:
    Model& m_model;
    Ui::s3Cooking *ui;

    //tzhou drag:
    QGraphicsScene* scene = new QGraphicsScene;
    void imageEnter(QPoint mousePos, QPixmap pixmap, QGraphicsView *view);

    //AndyTran
    QHash<Ingredient*, int>* todoList;

    //Ruini
    QMap<QString, QPixmap> xmaps;
    void createLables();

};

#endif // S3COOKING_H
