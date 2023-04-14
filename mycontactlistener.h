#ifndef MYCONTACTLISTENER_H
#define MYCONTACTLISTENER_H
#include <Box2D/Box2D.h>

#include <Box2D/Box2D.h>
#include <vector>
#include "box.h"

class MyContactListener : public b2ContactListener {
public:
    MyContactListener(std::vector<Box>& boxes);
    void BeginContact(b2Contact* contact) override;
    void removeImageFromBody(b2Body* body);

private:
    std::vector<Box>* boxes;

};
#endif // MYCONTACTLISTENER_H
