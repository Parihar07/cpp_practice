//
//  main.cpp
//  polymorphism_concept
//
//  Created by CodeBreaker on 08/06/25.
//

/*
 All is about the concept about understanding the polymorphism, below code is an example how we have derived the polymosrphism appraoch over tradtional apprach which will break the design principle od open/close
-open -> open for adding new features which is also called as extinsible
-Close -> it should need of existing code to be not changed
   to start with lets go with tradtion approach for below requirment
 
 - need to draw various shape
 - drawAllshapes which will take all list of shapes available
 - for now you have circle, triangle and later add square
 
 */
#include <iostream>
#include <vector>

using namespace std;


//Traditiona procedural approach
//enum ShapeType { CIRCLE, TRIANGLE};
//
//struct Shape {
//    ShapeType type;
//};
//
//struct Circle {
//    ShapeType type = CIRCLE;
//};
//
//struct Triangle {
//    ShapeType type = TRIANGLE;
//};
//
//void drawAllShapes(vector<Shape *> shapes){
//    for(auto shape : shapes)
//    {
//        if(shape->type==CIRCLE){
//            cout<<"drawing circle\n";
//        } else if(shape->type==TRIANGLE){
//            cout<<"drawing traingle\n";
//        }
//    }
//}

//OOP's way of implementation

class Shape{
public:
    virtual void draw()=0;
    virtual ~Shape(){cout<<"Base class Shape is destroyed\n";}
};

class Circle : public Shape{
    int radius;
public:
    Circle(int r):radius(r){}
    ~Circle(){cout<<"Circle is destroyed\n";}
    void draw() override {
        cout<<"Drawing Circle with the diametere : "<<radius*2<<endl;
    }
};

class Square : public Shape{
    int len, bre;
public:
    Square(int l, int b):len(l), bre(b){}
    ~Square(){cout<<"Square is destroyed\n";}
    void draw() override {
        cout<<"Drawing Square with the area : "<<len*bre<<endl;
    }
};

void drawAllShapes(const vector< unique_ptr<Shape>> &shapes){
    for(auto &s : shapes )
    {
        s->draw();
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Drawing several shapes!\n";
    
    auto circle = make_unique<Circle>(2);
    auto square = make_unique<Square>(2,4);
    
    
    vector<unique_ptr<Shape>> vs;
    vs.push_back(move(circle));
    vs.push_back(move(square));
    drawAllShapes(vs);

    return 0;
}
