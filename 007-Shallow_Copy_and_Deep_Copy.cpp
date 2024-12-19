/*
Shallow Copy: 
Only copies the address of an object i.e. two objects will point to the same memory address.
It is very dangerous when using pointers as one pointer can manipulate the value.
It can be used for the simple data types like int, float, char, etc.


Deep Copy: 
Allocate new memory and then copy the value.
It is used for the object pointers in a class.

*/

#include <iostream>

int main()
{
    std::cout<<"Hello World"<<std::endl;
    
    int *p1 = new int(10);
    
    // Shallow copy
    int *p2 = p1;
    
    // Deep copy
    int *p3 = new int(*p1);
    
    std::cout<<"p1: "<<p1<<"\t"<<"*p1: "<<*p1<<std::endl;
    *p1 = 4;
    std::cout<<"p2: "<<p2<<"\t"<<"*p2: "<<*p2<<std::endl;
    std::cout<<"p3: "<<p3<<"\t"<<"*p3: "<<*p3<<std::endl;

    return 0;
}

/*
Output:

Hello World
p1: 0x6111745cb6c0      *p1: 10
p2: 0x6111745cb6c0      *p2: 4
p3: 0x6111745cb6e0      *p3: 10

*/
