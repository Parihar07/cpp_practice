//
//  main.cpp
//  sync_locks_mutex_parking
//
//  Created by CodeBreaker on 12/06/25.
//

#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>
using namespace std;

class Parking{
private:
    mutex mtx;
    condition_variable cv;
    int counter;
public:
    Parking(int count):counter(count){};
    void acquire(){
        unique_lock<mutex> acq_uni_lock(mtx);
        while(counter == 0)
        {
            cout<<"Parking slots full,  waiting to be freed..!: "<<counter<<endl;
            cv.wait(acq_uni_lock);
        }
        counter--;
    }
    
    void release(){
        unique_lock<mutex> rel_uni_lock(mtx);
        counter--;
        cv.notify_one();
    }
};

Parking parking_slots(3);

void carParkingWorker(int carId){
    cout<<"car parking : "<<carId<<endl;
    parking_slots.acquire();
    cout<<"car parked : "<<carId<<endl;
    this_thread::sleep_for(chrono::seconds(3));
    cout<<"cark leaving : "<<carId<<endl;
    parking_slots.release();
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Understanding locks mutex etx!\n";
    
    thread cars[5];
    for(int i =0;i<5;i++)
    {
        cars[i] = thread(carParkingWorker, 1000+i);
    }
    for(int i=0;i<5;i++){
        cars[i].join();
    }
    return 0;
}
