//
//  main.cpp
//  abs_car
//
//  Created by CodeBreaker on 03/06/25.
//

#include <iostream>
using namespace std;

//basic car class to understand abstraction
class Car {
private:
    string name;
    string color;
    string dataOfManu;
    int checkElectronic;
    bool startEngine()
    {
        cout<<"starting Engine\n";
        return true;
    }
    bool checkTransmission(){
        cout<<"Chceking transmission\n";
        return true;
    }
    bool checkElectronics(){
        cout<<"chceking electronics\n";
        return true;
    }
    
    
public:
    Car(){
        checkTransmission();
        checkElectronics();
    }
    ~Car(){
        cout<<"Car is shutting down, Bye\n";
    }
    void makeCar(string strname, string strClr, string strDOM){
        name=strname; color=strClr; dataOfManu=strDOM;
    }
    void startCar();
    void honk();
    void lightOn();
};

void Car::startCar(){
    if(startEngine()){
        cout<<"Car started\n";
    } else {
        cout<<"some failure, check fuel..! \n";
    }
}

void Car::honk(){
    cout<<"Honking......!!\n";
}

void Car::lightOn(){
    cout<<"LIghts are on..!\n";
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Creating car class!\n";
    
    Car BMWi3;
    BMWi3.makeCar("BMW", "BLACK", "2025");
    
    BMWi3.startCar();
    BMWi3.lightOn();
    
    return 0;
}
