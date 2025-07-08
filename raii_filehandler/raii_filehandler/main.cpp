//
//  main.cpp
//  raii_filehandler
//
//  Created by CodeBreaker on 18/06/25.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class FileHandler{
private:
    string fname;
    ofstream filestream;
public:
    FileHandler(const string& fname): fname(fname), filestream(fname){
        if(!filestream.is_open()){
            throw runtime_error("File not opened : " + fname);
        }
        cout<<"File opened : "<<fname<<endl;
    }
    ~FileHandler(){
        if(filestream.is_open()){
            filestream.close();
            cout<<"file closed : "<<fname<<endl;
        }
    }
    
    //Avoid copying hence as per RAII delete the default copy constructors and assignment operators
    FileHandler(const FileHandler &) = delete;
    FileHandler& operator=(FileHandler &) = delete;
    
    //Allow moving (Move semantics)
    FileHandler(FileHandler &&) noexcept = default;
    FileHandler &operator=(FileHandler &&) noexcept = default;
    
    //Write line in file stream
    void writeMsg(const string &msg)
    {
        filestream<<msg;
    }
};

void writeLog(const string &logmsg){
//    throw runtime_error("some bull shit happeneed\n");
    FileHandler LogFileXYZ("LogFileXYZ.txt");
    LogFileXYZ.writeMsg(logmsg);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, RAII Filehandler!\n";
    try{
        writeLog("hello world chcek first line\n");
    }catch(runtime_error &e){
        cerr<<e.what()<<endl;
    }
    return 0;
}
