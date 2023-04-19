#ifndef MYCONTACTLISTENER_H
#define MYCONTACTLISTENER_H
#include <Box2D/Box2D.h>

#include <Box2D/Box2D.h>
#include <vector>
#include "QtCore/qobject.h"
#include "box.h"

class MyContactListener :public QObject,  public b2ContactListener
{
    Q_OBJECT
public:
    MyContactListener(QMap<std::string, Box*>&  boxes);
    void BeginContact(b2Contact* contact) override;
    void removeImageFromBody(b2Body* body);

private:
    //std::vector<Box>* boxes;
    QMap<std::string, Box*>*  boxes;

signals:
    void cut(std::string);

};
#endif // MYCONTACTLISTENER_H
