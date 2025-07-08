//
//  main.cpp
//  dp_builder
//
//  Created by CodeBreaker on 26/06/25.
//

#include <iostream>
#include <string>
using namespace std;

// Requirement create Computer, and provide provision of creating gaming PC, Work pc or custom pC
//class Computer{
//private:
//    string mOs;
//    string mGraphics;
//    string mRam;
//    string mStorage;
//    string mCpu;
//public:
//    //gaming PC
//    Computer(string graphics, string ram, string storage, string cpu)
//    : mGraphics(graphics),mRam(ram),mStorage(storage),mCpu(cpu){}
//    //WorkPc
//    Computer(string cpu, string ram, string storage)
//    : mCpu(cpu), mRam(ram),mStorage(storage){}
//    //customePC
//    Computer(string graphics, string ram, string storage, string cpu, string os)
//    : mGraphics(graphics),mRam(ram),mStorage(storage),mCpu(cpu), mOs(os){}
//};

/*
 Problem with above code:
 1) Too many constructors
 2) if we want to validate the input then too many if condition inside the cstor
 3) Hard to maintain
 */

//Class with builder class

class Computer{
private:
    string mOs;
    string mGraphics;
    string mRam;
    string mStorage;
    string mCpu;
    Computer(string Os, string Graphics, string Ram, string Storage, string Cpu)
    :mOs(Os),mGraphics(Graphics),mRam(Ram),mStorage(Storage),mCpu(Cpu){};
public:
    void showConfig() {
        if (!mOs.empty()) cout << "Operating System: " << mOs << endl;
        if (!mGraphics.empty()) cout << "Graphics: " << mGraphics << endl;
        cout << "Primary Memory (RAM): " << mRam << endl;
        cout << "Secondary Storage (HDD): " << mStorage << endl;
        cout << "Processor (CPU): " << mCpu << endl;
    }
    class Builder{
        string mOs;
        string mGraphics;
        string mRam;
        string mStorage;
        string mCpu;
    public:
        //Gaming PC
        Builder(string cpu, string ram, string storage)
        :mCpu(cpu), mRam(ram), mStorage(storage){}
        
        //Working PC add graphics by using this interface,, Method chaining 
        Builder& addGpu(string gpu){
            mGraphics=gpu;
            return *this;
        }
        
        //FOr working pc add os using this interface
        Builder& addOs(string os){
            mOs=os;
            return *this;
        }
        
        //Build the computer based on data received
        Computer *buildPC(){
            return new Computer(mOs, mGraphics, mRam, mStorage, mCpu);
        }
    };
    
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Lets understand builder pattern!\n";
    
    Computer* gamingPc = Computer::Builder("Intel i9", "32GB", "1TB").addGpu("Nvidia GTX 1123").buildPC();
    gamingPc->showConfig();
    cout<<endl;
    
    return 0;
}
