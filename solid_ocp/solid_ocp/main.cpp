//
//  main.cpp
//  solid_ocp
//
//  Created by CodeBreaker on 20/06/25.
//

#include <iostream>
using namespace std;

/*
 Problamatic Code :
 Problem:
  - Its breaking the Design principle OCP i.e open for extension and closed for modification
 How:
 - Open for extension: If you want to add any new shape like triangle(new feature) yo need to do changes in enum and then have to one more if clause in drawshapes function(behaviour)
 - Close for modification : we need to changes in the existing code as OCP says you should not changes or touch existing code when you add new feature
 */
enum ShapeTypes{ CIRCLE, SQUARE };

struct Shape {
    ShapeTypes type;
};

struct Circle : Shape{
    double radius;
};

struct Square : Shape {
    int side;
};

void drawShapes(Shape &s)
{
        if(s.type==CIRCLE){
            Circle &circle = (Circle &)s;
            cout<<"Drawing the circle with radius "<<circle.radius<<endl;
        } else if(s.type==SQUARE){
            Square &sq = static_cast<Square &>(s);
            cout<<"Drawing the square with side "<<sq.side<<endl;
        }
}

/*
 Code adhereing the OCP principle
 */

class Shapes {
public:
    virtual void plotShape()=0;
    virtual ~Shapes(){};
};

class Circles : public Shapes{
    double radius;
public:
    Circles(double r):radius(r){}
    void plotShape() override{
        cout<<"drawing Circles with radius "<<radius<<endl;
    }
};

class Squares : public Shapes{
    int side;
public:
    Squares(int r):side(r){}
    void plotShape() override{
        cout<<"drawing Circles with radius "<<side<<endl;
    }
};

void drawShapes2(Circles *s)
{
    s->plotShape();
}

void drawShapes3(Shapes &s)
{
    s.plotShape();
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Understanding OCP(Open Close Principle)!\n";
    vector<Shape *> shapes;
    shapes.push_back(new Circle{CIRCLE,5.0});
    shapes.push_back(new Square{SQUARE, 3});
    
    
    vector<Shapes *> shapes2;
    shapes2.push_back(new Circles(7.0));
    shapes2.push_back(new Squares(9));
    
    for(auto i:shapes2){
        drawShapes3(*i);
    }
    
    return 0;
}
