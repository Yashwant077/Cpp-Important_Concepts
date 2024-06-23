#include <bits/stdc++.h>
using namespace std;

class Complex {
    int real;
    int img;
    
    public:
        void setData(int real, int img){
            this->real = real;
            this->img = img;
        }
        
        void getData(){
            cout<<"The real value is "<<real<<endl;
            cout<<"The img value is "<<img<<endl;
        }
};

int main()
{
    // Pointers to class
    Complex c1;
    // Complex* ptr = &c1;     // or 
    Complex* ptr = new Complex;
    (*ptr).setData(17,32);      // we can access object members from pointers using arrow operators
    ptr->getData();
    
    // Array of Objects
    Complex* ptr1 = new Complex[2];
    
    (*ptr1).setData(10,87);
    ptr1->getData();
    
    ptr1++;
    
    ptr1->setData(23,45);
    ptr1->getData();
    
    cout<<"========================="<<endl;
    
    // Dynamic array of Objects
    // i.e. taking size of array objects from user
    
    int size;
    cout<<"How many complex numbers you want to create: ";
    cin>>size;
    
    Complex* cPtr = new Complex[size];
    Complex* tempPtr = cPtr;
    int p,q;
    
    for(int i=0; i<size; i++){
        cout<<"Enter real part value: ";
        cin>>p;
        cout<<"Enter img part value: ";
        cin>>q;
        
        cPtr->setData(p,q);
        cPtr++;
    }
    
    cPtr = tempPtr;
    
    for(int i=0; i<size; i++){
        cPtr->getData();
        cPtr++;
    }
    
    return 0;
}

/*Output:
The real value is 17
The img value is 32
The real value is 10
The img value is 87
The real value is 23
The img value is 45
=========================
How many complex numbers you want to create: 3
Enter real part value: 1
Enter img part value: 2
Enter real part value: 3
Enter img part value: 4
Enter real part value: 5
Enter img part value: 6
The real value is 1
The img value is 2
The real value is 3
The img value is 4
The real value is 5
The img value is 6
*/
