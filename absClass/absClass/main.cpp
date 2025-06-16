//
//  main.cpp
//  absClass
//
//  Created by CodeBreaker on 04/06/25.
//

#include <iostream>
using namespace std;

class Shape{
public:
    virtual void draw() = 0;
    virtual double area() = 0;
    virtual ~Shape(){};
};

class Circle : public Shape{
private:
    int radius;
public:
    void draw() override {
        cout<<"frawing circle"<<endl;
    }
    double area() override {
        return 3.14*radius*radius;
    }
    Circle(int rad):radius(rad){}
};

class Rectangle : public Shape{
    int len;
    int wid;
public:
    void draw() override {
        cout<<"Drawing Rectangle\n";
    }
    double area() override {
        return (double)len*wid;
    }
    Rectangle(int l, int b): len(l), wid(b){}
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Shape *rectangle = new Rectangle(4,5);
    rectangle->draw();
    
    std::cout << "Hello, understading abstract class!\n";
    
    delete rectangle;
    return 0;
}
