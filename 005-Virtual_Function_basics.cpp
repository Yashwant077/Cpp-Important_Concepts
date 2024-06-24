#include <bits/stdc++.h>
using namespace std;

class Base {
    int var_base;
    public:
        void setData(int var_base){
            this->var_base = var_base;
        }
        
        // virtual void getData(){
        void getData(){
            cout<<"Value of var_base is "<<var_base<<endl;
        }
};

class Derived: public Base {
    int var_derived;
    public:
        void setData(int var_derived){
            this->var_derived = var_derived;
        }
    
        void getData(){
            // cout<<"Value of var_base is "<<var_base<<endl;
            cout<<"Value of var_derived is "<<var_derived<<endl;
        }
};

int main()
{
    /*
    
    In general, if a pointer to a base class is declared and assigned a reference of derived 
    a base class object. Then, by default only derived class function and member variables 
    can be accessed from it. It is because of the early binding or compile time binding. 
    In this method call the base class pointer will ne binded or mapped to it's base class 
    data members and member variables.
    
    But, when we use a virtual function in a class then that function will not be bind 
    to that class even if the pointer to class is calling that method. It will call same 
    names' Derived class method as it will be binded to that. This is known as late binding 
    or run-time binding.
    
    */
    
    Base* basePtr;
    Derived objDerived;
    
    basePtr = &objDerived;
    // basePtr->var_derived=32;    // it will throw an error
    basePtr->setData(21);
    basePtr->getData();
    
    Derived* derivedPtr;
    derivedPtr = &objDerived;
    derivedPtr->setData(101);
    derivedPtr->getData();
    
    return 0;
}


/*Output:
Value of var_base is 21
Value of var_derived is 101
*/
