
#ifndef INGREDIENT_H
#define INGREDIENT_H


#include <QObject>


class ingredient : public QObject
{
    Q_OBJECT
public:
    explicit ingredient(QObject *parent = nullptr);

signals:

};

#endif // INGREDIENT_H
