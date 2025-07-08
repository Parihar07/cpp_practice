//
//  main.cpp
//  raii_uniqueptr
//
//  Created by CodeBreaker on 18/06/25.
//

#include <iostream>
#include <string>
using namespace std;

void processData(){
    unique_ptr<int[]> data(new int[10]);
    for(int i=0;i<10;i++)
    {
        data[i]=i+10;
    }
    for(int i=0;i<10;i++)
    {
        cout<<data[i]<<endl;
    }
    return;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, wrting uniqueptr!\n";
    processData();
    
    return 0;
}
