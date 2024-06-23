#include <bits/stdc++.h>
using namespace std;

/*
Order fo calling of constructors

Case 1:
class B: public A{
    // Order of calling of constructors -> first A(), then B().
    // first base class constructors is called and then derived class constructor is called.
}

case 2:
class C: public A, public B{
    // Order of calling of constructors -> A(), B(), C()
    // when multiple class is derived in a class then order of constructors
    // is same as their inheriting order.
}

case 3:
Class C: public A, virtual public B{
    // Order of calling of constructors -> B(), A(), C()
    // virtual inheritance has the highest priority.
}

*/

class Base1 {
    int data1;
    public:
        Base1(int a){
            data1 = a;
            cout<<"Base1 constructor called"<<endl;
        }
        void printDataBase1(){
            cout<<"Value of data 1 is "<<data1<<endl;
        }
};

class Base2 {
    int data2;
    public:
        Base2(int a){
            data2 = a;
            cout<<"Base2 constructor called"<<endl;
        }
        void printDataBase2(){
            cout<<"Value of data 2 is "<<data2<<endl;
        }
};

class Derived: public Base1, public Base2 {
    int derived1;
    int derived2;
    public:
        Derived(int a, int b, int c, int d): Base1(a), Base2(b){
            derived1 = c;
            derived2 = d;
            cout<<"Derived class constructor called"<<endl;
        }
        void printDerivedData(){
            cout<<"Value of derived1 is "<<derived1<<endl;
            cout<<"Value of derived2 is "<<derived2<<endl;
        }
};


int main()
{
    Derived d(1,2,3,4);
    d.printDataBase1();
    d.printDataBase2();
    d.printDerivedData();
    
    return 0;
}











/* Output:
Base1 constructor called
Base2 constructor called
Derived class constructor called
Value of data 1 is 1
Value of data 2 is 2
Value of derived1 is 3
Value of derived2 is 4
*/
