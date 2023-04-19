#include "mycontactlistener.h"
#include <QDebug>
/**
 * @author Andy Tran
 * @brief MyContactListener::MyContactListener
 * @param boxes
 */
MyContactListener::MyContactListener(QMap<std::string, Box*>&  boxes)
{
    this->boxes = &boxes;
    qDebug() << "Address of Boxes MyContactListener: " << &(this->boxes);
}

void MyContactListener::removeImageFromBody(b2Body* body) {
    // Find the image in the boxes vector and remove it
    for (auto it = boxes->begin(); it != boxes->end(); it++) {
//        if (it->getBody() == body) {
//            boxes->erase(it);
//            break;
//        }
    }
//    qDebug() << boxes.size();
}

void MyContactListener::BeginContact(b2Contact* contact){

    // Get the two fixtures involved in the contact
    b2Fixture* fixtureA = contact->GetFixtureA();
    b2Fixture* fixtureB = contact->GetFixtureB();

    // Get the two bodies involved in the contact
    b2Body* bodyA = fixtureA->GetBody();
    b2Body* bodyB = fixtureB->GetBody();

    // Check if either fixture is an edge shape (i.e., the curved ground)
//    bool isFixtureAEdge = (fixtureA->GetType() == b2Shape::e_edge);
//    bool isFixtureBEdge = (fixtureB->GetType() == b2Shape::e_edge);

        // Check if either body is a box
        if (bodyA->GetType() == b2_dynamicBody && bodyB->GetType() == b2_staticBody) {
            // Remove the image from the boxes vector
            qDebug() << "1";
            //removeImageFromBody(bodyA);
        } else if (bodyB->GetType() == b2_dynamicBody && bodyA->GetType() == b2_staticBody) {
            // Remove the image from the boxes vector


            std::string ingredientName = static_cast<const char*>(bodyB->GetUserData());
            if(ingredientName.compare("tomato") == 0){
                //boxes->value("tomato");
                if(boxes->contains(ingredientName)){
                    emit cut(ingredientName);
                }
            }else if(ingredientName.compare("pieces") == 0){
                //qDebug() << "pieces";
            }

            //qDebug() << "contact";
            //removeImageFromBody(bodyB);
        }
//        else if (bodyA->GetType() == b2_dynamicBody && bodyB->GetType() == b2_dynamicBody){
//            //removeImageFromBody(bodyA);
//            //removeImageFromBody(bodyB);
//             qDebug() << "3";
//        }


}
