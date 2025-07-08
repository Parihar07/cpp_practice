//
//  main.cpp
//  solid_srp
//
//  Created by CodeBreaker on 18/06/25.
//

#include <iostream>
#include<string>
#include <fstream>
using namespace std;

//Problamatic code
// Single class havinf multiple responsibilities 1) User details and 2) it is also saving the data into DB
// Its breaking SRP single responsibility principle
class User{
private:
    string mName;
    string mEmail;
public:
    User(const string &name, const string &email): mName(name), mEmail(email){}
    void saveData(){
        fstream myDB("UserDb.db", ios::app);
        if(myDB.is_open()){
            myDB
            <<"Name:"<<mName
            <<"Email:"<<mEmail<<endl;
        }
    }
};

//Code adhering to SRP

class User2{
private:
    string mName;
    string mEmail;
public:
    User2(const string &name, const string &email): mName(name), mEmail(email){}
    string getName()const{return mName;}
    string getEmail()const{return mEmail;}
};

class UserDB{
public:
    void saveUser(const User2 &usr){
        fstream userDB("userDb.db",ios::app);
        if(userDB.is_open()){
            userDB<<"Name : "<<usr.getName()<<"; "<<usr.getEmail()<<endl;
        }
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Understanding SRP!\n";
    User2 parihar("parihar", "parihar@bullshit.com");
    User2 singh("singh","singh@lolwa.com");
    
    UserDB saveData;
    saveData.saveUser(parihar);
    saveData.saveUser(singh);
    
    return 0;
}
