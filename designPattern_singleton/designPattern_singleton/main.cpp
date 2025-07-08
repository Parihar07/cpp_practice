//
//  main.cpp
//  designPattern_singleton
//
//  Created by CodeBreaker on 24/06/25.
//

#include <iostream>
using namespace std;

class Singleton {
private:
    //make constructor private
    Singleton(){
        cout<<"Instance created..\n";
    }
    // removing copy and move constructors
    Singleton(Singleton &) = delete;
    Singleton& operator=(Singleton &) = delete;
    
    //Move
    Singleton(Singleton &&) = delete;
    Singleton& operator=(Singleton &&) = delete;
    
    //Static member variable to hold instance
    static Singleton *instance;
public:
    
    static Singleton *getInstance(){
        if(instance==nullptr){
            instance = new Singleton();
        }
        return instance;
    }
    
    void doSomething(){
        cout<<"Just some task execution\n";
    }
};


//Inherently thread safe as object for this singletonis creatoed before hand mean before main is called
class ESingleton {
private:
    //make constructor private
    ESingleton(){
        cout<<"Eager Instance created..\n";
    }
    // removing copy and move constructors
    ESingleton(ESingleton &) = delete;
    ESingleton& operator=(ESingleton &) = delete;
    
    //Move
    ESingleton(ESingleton &&) = delete;
    ESingleton& operator=(ESingleton &&) = delete;
    
    //Static member variable to hold instance
    static ESingleton eInstance;  // Eager instantiation not using pointer here hence object is created here
public:
    
    static ESingleton &getInstance(){
        return eInstance;
    }
    
    void doSomething(){
        cout<<"Just some task execution\n";
    }
};


//ThreadSafe(TS) Single ton
class TS_Singleton {
private:
    TS_Singleton(){
        cout<<"thread safe single ton is created \n";
    }
    static TS_Singleton *ts_instance;
    static once_flag of;
    static void createInstance(){
        ts_instance = new TS_Singleton();
    }
public:
    static TS_Singleton *getInstance(){
        call_once(of, createInstance);
        return ts_instance;
    }
    void doSomething(){
        cout<<"Iam thread safe and doing something\n";
    }
};

ESingleton ESingleton::eInstance;
Singleton* Singleton::instance = nullptr;
//Once flag
once_flag TS_Singleton::of;
TS_Singleton* TS_Singleton::ts_instance = nullptr;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Understanding Singleton !\n";
    
//    //Singleton *sObj = new Singleton();
//    Singleton *sObj = Singleton::getInstance();
//    
//    sObj->doSomething();
//    
//    Singleton *obj2 = Singleton::getInstance();
//    obj2->doSomething();
    
//    ESingleton::getInstance().doSomething();
    
    TS_Singleton *instance = TS_Singleton::getInstance();
    instance->doSomething();
    return 0;
}
