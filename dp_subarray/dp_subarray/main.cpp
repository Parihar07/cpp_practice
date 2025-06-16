//
//  main.cpp
//  dp_subarray
//
//  Created by CodeBreaker on 12/06/25.
//

#include <iostream>
#include <vector>
using namespace std;

void printSubarrayHelper(vector<int> &A, int idx)
{
    if(idx>A.size()) return;
    for(int i=idx;i<A.size();i++){
        cout<<A[i]<<" ";
    }
    cout<<"\n";
    printSubarrayHelper(A, idx+1);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> A{1,2,3};
    for(int i=0;i<A.size();i++){
        printSubarrayHelper(A, i);
        cout<<endl;
    }
    std::cout << "Hello, understanding subsequesntce or subset or powerset!\n";
    return 0;
}
