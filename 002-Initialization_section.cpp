#include <bits/stdc++.h>
using namespace std;

/*
Initialization section/list syntax:

class Test {
    int data;
    public:
        Test(int i): Initialization section {
            data member assignment + some code;
        }
}

*/

class Test {
    int a;
    int b;
    public:
        // Test(int i, int j) : a(i), b(j)
        // Test(int i, int j) : a(i), b(i+j)
        // Test(int i, int j) : a(i), b(2*a)
        // Test(int i, int j) : b(j), a(i)
        // Test(int i, int j) : b(j), a(i+b) -> a=4, b=5 as a will be initialized first and at the time of Initialization of a b is having it's default value which is 0.
        // Test(int i, int j) : b(j+a), a(i) -> a=4, b=9(4+5), a will be initialized first as it is declared first or before b.
        Test(int i, int j)
        {
            a = i;
            b = j;
            cout<<"Constructor executed"<<endl;
            cout<<"Value of a is "<<a<<endl;
            cout<<"Value of b is "<<b<<endl;
        }
    
};


int main()
{
    Test t(4,5);
    
    return 0;
}

/*Output:
Constructor executed
Value of a is 4
Value of b is 9
*/
