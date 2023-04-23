#ifndef KITCHENCONTACTLISTENER_H
#define KITCHENCONTACTLISTENER_H

#include <Box2D/Box2D.h>

class KitchenContactListener : public b2ContactListener
{
public:
    virtual void BeginContact(b2Contact* contact);
};

#endif // KITCHENCONTACTLISTENER_H
