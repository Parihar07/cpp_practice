//
//  main.cpp
//  dp_facade
//
//  Created by CodeBreaker on 03/07/25.
//

#include <iostream>
using namespace std;

class ICpu{
public:
    virtual ~ICpu(){cout<<"icpu destroyed..!\n";}
    virtual void intialize()=0;
    virtual void execute()=0;
};

class IMemory{
public:
    virtual ~IMemory(){cout<<"imem destroyed..!\n";}
    virtual void load()=0;
};

class IHardisk{
public:
    virtual ~IHardisk(){cout<<"Iharddisk destroyed..\n";}
    virtual void readBootsector()=0;
};

class CPU : public ICpu{
    void intialize() override {
        cout <<"CPU intialized ..\n";
    }
    void execute() override {
        cout<<"executing ....\n";
    }
};

class Memory : public IMemory{
    void load() override{
        cout<<"Memory loaded \n";
    }
};

class HDD : public IHardisk{
    void readBootsector() override{
        cout<<"reading bootsector..\n";
    }
};

class ComputerFacade{
    ICpu *cpu;
    IMemory *mem;
    IHardisk *hdd;
public:
    ComputerFacade(ICpu *cp, IMemory* me, IHardisk* hd):
    cpu(cp), mem(me), hdd(hd){}
    void start(){
        cpu->intialize();
        cpu->execute();
        
        mem->load();
        
        hdd->readBootsector();
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Understanding Facade!\n";
    CPU cpu;
    HDD hdd;
    Memory mem;
    
    ComputerFacade cf(&cpu, &mem, &hdd);
    cf.start();
    
    return 0;
}
