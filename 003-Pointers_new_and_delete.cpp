#include <bits/stdc++.h>
using namespace std;


int main()
{
    // Basic pointer example
    int a = 7;
    int* ptr = &a;
    cout<<"Value of a is "<<*(ptr)<<endl;
    
    // new operator
    // it is use to dynamically allocate memory
    // Case 1: To allocate a single variable memory
    int *p = new int(75);
    cout<<"Value of *p is "<<*(p)<<endl;
    
    // Case 2: to allocate contigous memory
    int *arr = new int[3];
    arr[0] = 32;
    *(arr+1) = 98;
    arr[2] = 47;
    cout<<"Value of arr[0] is "<<arr[0]<<endl;
    cout<<"Value of arr[1] is "<<arr[1]<<endl;
    cout<<"Value of arr[2] is "<<arr[2]<<endl;
    
    // delete operator
    // delete operator is used to delete or free the dynamically allocated memory
    delete p;
    cout<<"Value of *p is "<<*(p)<<endl;
    
    delete[] arr;
    cout<<"Value of arr[0] is "<<arr[0]<<endl;
    cout<<"Value of arr[1] is "<<arr[1]<<endl;
    cout<<"Value of arr[2] is "<<arr[2]<<endl;
    
    return 0;
}

/*Output:
Value of a is 7
Value of *p is 75
Value of arr[0] is 32
Value of arr[1] is 98
Value of arr[2] is 47
Value of *p is 1456813798
Value of arr[0] is 96161830
Value of arr[1] is 21864
Value of arr[2] is 1572826296
*/
