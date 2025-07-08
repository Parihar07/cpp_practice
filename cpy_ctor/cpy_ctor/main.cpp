//
//  main.cpp
//  cpy_ctor
//
//  Created by CodeBreaker on 24/06/25.
//

#include <iostream>
using namespace std;
//Understanding copy constructor
class Person{
private:
    int *mAge{};
public:
    Person() : mAge(new int(0)){};
    ~Person(){
        if(mAge){
            delete mAge;
            mAge = nullptr;
        }
    }
    int getAge()const{
        return *mAge;
    }
    void setAge(int age){
        *mAge = age;
    }
};

void printInfo(const Person &p){
    cout<<"age : "<<p.getAge()<<endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Understanding copy constructor!\n";
    
    Person p1;
    p1.setAge(20);
    printInfo(p1);
    
    Person p2(p1);
    printInfo(p2);
    
    p1.setAge(40);
    printInfo(p1);
    printInfo(p2);
    return 0;
}
