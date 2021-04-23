#include <iostream>
//#include "design_patterns.h"
using namespace std;
class Shape {
public:
    Shape() {
        id_ = total_++;
    }
    virtual void draw() = 0;
protected:
    int id_;
    static int total_;
};
int Shape::total_ = 0;

class Circle : public Shape {
public:
    void draw() {
        cout << "circle " << id_ << ": draw" << endl;
    }
};

class Square : public Shape {
public:
    void draw() {
        cout << "square " << id_ << ": draw" << endl;
    }
};

class Ellipse : public Shape {
public:
    void draw() {
        cout << "ellipse " << id_ << ": draw" << endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() {
        cout << "rectangle " << id_ << ": draw" << endl;
    }
};

class Factory {
public:
    virtual Shape* createCurvedInstance() = 0;
    virtual Shape* createStraightInstance() = 0;
};

class SimpleShapeFactory : public Factory {
public:
    Shape *createCurvedInstance()
    {
        return new Circle;
    }
    Shape *createStraightInstance()
    {
        return new Square;
    }
};

class RobustShapeFactory : public Factory {
public:
    Shape *createCurvedInstance()
    {
        return new Ellipse;
    }
    Shape *createStraightInstance()
    {
        return new Rectangle;
    }
};
namespace DP {
    namespace Creational{
        //#define SIMPLE 1
        #define ROBUST 1
        void abstract_factory()
        {
            cout << endl;
        #if SIMPLE
            Factory *factory = new SimpleShapeFactory;
        #elif ROBUST
            Factory *factory = new RobustShapeFactory;
        #endif
            
            Shape *shape[3];
            shape[0] = factory->createCurvedInstance();
            shape[1] = factory->createStraightInstance();
            shape[2] = factory->createCurvedInstance();

            shape[0]->draw();
            shape[1]->draw();
            shape[2]->draw();

            delete(shape[0]);
            delete(shape[1]);
            delete(shape[2]);
            delete(factory);
        }

    }
}//DP eof