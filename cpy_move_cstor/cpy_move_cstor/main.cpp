//
//  main.cpp
//  cpy_move_cstor
//
//  Created by CodeBreaker on 27/06/25.
//

/*
 Key Takeaways:
 1) Understanding the copy and move semantics:
    - Copy semantics involve creating a new object as a copy of an existing one.
    - Move semantics allow transferring ownership of resources from one object to another, avoiding deep copies.

 2) Rule of 3 and Rule of 5:
    - Rule of 3: If a class defines a destructor, copy constructor, or copy assignment operator, it should define all three.
    - Rule of 5 (C++11 and later): If a class defines any of the above three, it should also define the move constructor and move assignment operator for efficient resource management.

 3) RVO (Return Value Optimization):
    - A compiler optimization technique that eliminates the creation of temporary objects by directly constructing the return value in the caller's context.

 4) Copy Elision:
    - Guaranteed in C++17 for returning local objects by value, reducing the need for move constructors and improving performance.

 5) Self-assignment check:
    - Always ensure that an object is not assigned to itself in copy or move assignment operators to prevent resource leaks or undefined behavior.
 */
#include <iostream>
#include <string.h>
using namespace std;

class Buffer {
private:
    char *pData;
    size_t size;
public:
    //Default constructor
    Buffer() = default;
    //Parametric Constructor
    Buffer(const char *str){
        cout<<"Buffer Parametric Constructor\n";
        size = strlen(str) + 1;
        pData = new char[size];
        memcpy(pData,str,size);
    }
    //Destructor
    ~Buffer(){
        cout<<"Buffer Destructor : \"";
        if(pData){
            cout<<pData<<"\""<<endl;
        } else {
            cout<<"[ EMPTY ]"<<endl;
        }
        delete [] pData;
    }
    //copy constructor
    Buffer(const Buffer &oth){
        cout<<"Copy constructor is invoked\n";
        size = oth.size;
        pData = new char[size];
        memcpy(pData, oth.pData, size);
    }
    //Copy Assignment opearator
    Buffer &operator=(const Buffer &oth){
        cout<<"Copy assignemnt operator is invoked\n";
        if(this != &oth)
        {
            delete [] pData;
            size = oth.size;
            pData = new char[size];
            memcpy(pData, oth.pData, size);
        }
        return *this;
    }
    //Move Constructor
    Buffer(Buffer &&oth) noexcept{
        cout<<"Move constructor is invoked\n";
        //get the stuff
        pData = oth.pData;
        size = oth.size;
        
        //neutralize source
        oth.pData = nullptr;
        oth.size = 0;
    }
    
    //Move assignment operator
    Buffer &operator=(Buffer &&oth) noexcept{
        cout<<"Move assignment is invoked\n";
        //get the stuff
        pData = oth.pData;
        size = oth.size;
        
        //neutralize source
        oth.pData = nullptr;
        oth.size = 0;
        
        return *this;
    }
    //printing the stuff to check
    void printInfo(){
        cout<<pData<<endl;
    }
    
    Buffer createlargebuffer() {
        return Buffer("this is very i mean very very very very large buffer so your copy will resiurce extensive");
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Understanding move and copy semantics!\n";
    
    cout<<"-----------------\n";
    Buffer buffer("something nonsense");
    buffer.printInfo();
    cout<<"-----------------\n";
    Buffer buff(buffer);
    buff.printInfo();
    cout<<"-----------------\n";
    Buffer test1("hello");
    Buffer test2("world");
    test1=test2;
    cout<<"-----------------\n";
    Buffer largeBuffer = Buffer().createlargebuffer();
    //Buffer buff2 = std::move(largeBuffer);
    largeBuffer.printInfo();
    cout<<"-----------------\n";
    
    return 0;
}
