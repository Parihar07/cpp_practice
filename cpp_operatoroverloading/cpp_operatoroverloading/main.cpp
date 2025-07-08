//
//  main.cpp
//  cpp_operatoroverloading
//
//  Created by CodeBreaker on 05/07/25.
//

#include <iostream>
using namespace std;

class Complex{
private:
    int real, imag;
public:
    Complex(int a, int b):real(a),imag(b){}
    Complex() =default;
    //addition operator
    Complex operator +(Complex &c){
        real+=c.real;
        imag+=c.imag;
        return *this;
    }
    //CopyConstructor
    Complex(Complex &c){
        real=c.real;
        imag=c.imag;
    }
    //Extraction operator
    friend ostream& operator <<(ostream &x, Complex c);
    //Addiotn of primitive or other type to cmplex
    
    Complex operator +(int a){
        real=real+a;
        imag=imag+a;
        return *this;
    }
};

ostream& operator<<(ostream &x, Complex c){
    x<<"Real : Imag "<< c.real << ":" <<c.imag<<endl;
    return x;
}



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Understanding operator overlaoding!\n";
    
    Complex C1(3,5), C2(5,6);
    cout<<C1<<C2;
    C1 = C1+C2;
    Complex c3(Complex(5, 8));
    cout<<c3<<endl;
    
    Complex c4(11,12);
    c4=c4+5;
    cout<<c4<<endl;
    return 0;
}
