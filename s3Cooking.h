#ifndef S3COOKING_H
#define S3COOKING_H

#include <QWidget>
#include <Box2D/Box2D.h>
#include <QTimer>
#include<Qlist>
#include<QVector>
#include<QGraphicsView>
#include<QGraphicsScene>
#include"render.h"
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

public slots:
    void nextPage();
    void enableFinalized();

    //jeffeeeeeeee
    void recieveSelectedRecipe(RecipeNew* recipe);

signals:
    void goToPage4();

private:
    Ui::s3Cooking *ui;
    Render* render = new Render();

    //Ruini
    QMap<QString, QPixmap> xmaps;

};

#endif // S3COOKING_H
