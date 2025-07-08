//
//  main.cpp
//  dp_adapter
//
//  Created by CodeBreaker on 03/07/25.
//

#include <iostream>
using namespace std;
class Rectangle{
public:
    virtual ~Rectangle(){cout<<"Rectangle destroyed \n";};
    virtual void draw()=0;
};

class UnsupportedLine {
public:
    ~UnsupportedLine(){cout<<"Unsupported line destroyed!\n";}
    void unsupportedline(){
        cout<<"unsupported line drawn---------------------------------\n";
    }
};



// Multiple inheritiace hence using composition
class Adapter : public Rectangle, UnsupportedLine{
  
    void draw() override{
        unsupportedline();
    }
};


//Its new and optimized adaptor using composition

class NewAdaptor : public Rectangle{
private:
    unique_ptr<UnsupportedLine> unsupportedline;
public:
    ~NewAdaptor(){cout<<"NewAdptor destroyed!\n";}
    NewAdaptor() : unsupportedline(make_unique<UnsupportedLine>()){}
    void draw() override{
        unsupportedline->unsupportedline();
    }
};

void RenderUI(Rectangle *shape)
{
    shape->draw();
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Understanding Adptor design pattern!\n";
    Rectangle *rectangle = new NewAdaptor();
    RenderUI(rectangle);
    delete rectangle;
    return 0;
}
