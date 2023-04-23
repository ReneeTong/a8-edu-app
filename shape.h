#ifndef SHAPE_H
#define SHAPE_H

#include <QObject>
#include <map>
#include <Box2D/Box2D.h>

using std::map;
using std::unique_ptr;


class Shape : public QObject
{
    Q_OBJECT
public:
    explicit Shape(b2World *world, const b2Vec2& position, const b2Vec2& size, float32 density = 1.0f, float32 friction = 0.3f, QObject *parent = nullptr);
    ~Shape();


    b2Body* getBody() const { return m_body; }
    void* getData() { return m_data; }
    b2Vec2 getSize() const { return m_size; }

    void setStatic(bool value);
    void setData(void* data) { m_data = data; }

private:
    b2Body* m_body;
    b2Vec2 m_size;

    void* m_data;

signals:
    void onContact(Shape*);

};


#endif // SHAPE_H
