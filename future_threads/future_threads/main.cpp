//
//  main.cpp
//  future_threads
//
//  Created by CodeBreaker on 10/06/25.
//

#include <iostream>
#include <future>
#include <chrono>
using namespace std;

int calculateSum(int a, int b)
{
    this_thread::sleep_for(chrono::seconds(2)); // simulating some work
    return a+b;
}

int riskyFunc()
{
    throw runtime_error("something went bad..!");
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Understanding future and async calls and results of same!\n";
    cout<<"launching some asynchronous task\n";
    future<int> resultFuture = async(launch::async, calculateSum, 3,4);
    
    cout<<"doing some other work\n";
    this_thread::sleep_for(chrono::seconds(1));
    
    cout<<"getting result from future..\n";
    int sum = resultFuture.get();
    cout<<"sum is : "<<sum<<endl;
    
    resultFuture = async(launch::async, riskyFunc);
    try{
        int riskyResult = resultFuture.get();
        cout<<"result : "<<riskyResult<<endl;
    } catch (const runtime_error &e){
        cerr<<"cought exception :"<<e.what()<<endl;
    }
    
    return 0;
}
