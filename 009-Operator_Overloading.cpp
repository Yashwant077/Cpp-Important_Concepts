/*
Operator Overloading

*/

#include <iostream>
using namespace std;

class Integer {
    int *m_pInt;
    
    public:
    // Default constructor
    Integer(){
        // cout<<"Integer()"<<endl;
        m_pInt = new int(0);
    }
    
    // Parameterized constructor
    Integer(int value){
        // cout<<"Integer(int)"<<endl;
        m_pInt = new int(value);
    }
    
    // Deep copy constructor
    Integer(const Integer &obj){
        // cout<<"Integer(const Integer &)"<<endl;
        m_pInt = new int(*obj.m_pInt);
    }
    
    // Move constructor
    Integer(Integer &&obj){
        // cout<<"Integer(Integer &&)"<<endl;
        m_pInt = obj.m_pInt;
        obj.m_pInt = nullptr;
    }
    
    int GetValue() const{
        return *m_pInt;
    }
    
    void SetValue(int value){
        if(m_pInt==nullptr){
            m_pInt = new int{};
        }
        *m_pInt = value;
    }
    
    // Operator Overloading
    Integer operator +(const Integer &obj) const {
        Integer temp;
        *temp.m_pInt = *m_pInt + *obj.m_pInt;
        return temp;
    }
    
    // pre-increment Overloading
    Integer & operator ++() {
        (*m_pInt)++;
        return *this;
    }
    
    // post-increment Overloading
    Integer operator ++(int){
        Integer temp(*this);
        ++(*m_pInt);
        return temp;
    }
    
    // comparison operator Overloading
    bool operator ==(const Integer &obj) const {
        return *m_pInt == *obj.m_pInt;
    }
    
    // assignment operator Overloading
    Integer & operator =(const Integer &a){
        if(this!=&a){
            delete m_pInt;
            m_pInt = new int(*a.m_pInt);
        }
        return *this;
    }
    
    // move assignment operator
    Integer operator =(Integer &&a){
        if(this!=&a){
            delete m_pInt;
            m_pInt = a.m_pInt;
            a.m_pInt = nullptr;
        }
        return *this;
    }
    
    // Destructor
    ~Integer(){
        // cout<<"~Integer()"<<endl;
    }
    
};

Integer Add(const Integer &a, const Integer &b){
    Integer temp;
    temp.SetValue(a.GetValue() + b.GetValue());
    return temp;
}

// Global operator Overloading for 
Integer operator +(int x, const Integer &y){
    Integer temp;
    temp.SetValue(x + y.GetValue());
    return temp;
}

// insertion operator Overloading
std::ostream & operator <<(std::ostream & out, const Integer &a){
    out<<a.GetValue();
    return out;
}

// extraction operator Overloading
std::istream & operator >>(std::istream &input, Integer &a){
    int x;
    input>>x;
    a.SetValue(x);
    return input;
}

int main()
{
    Integer a(1), b(2);
    Integer sum = a + b;
    cout<<"sum: "<<sum.GetValue()<<endl;
    cout<<"sum++: "<<(++sum).GetValue()<<endl;
    cout<<"++sum: "<<(sum++).GetValue()<<endl;
    cout<<"sum: "<<sum.GetValue()<<endl;
    
    if(a==b){
        cout<<"a and b are equal"<<endl;
    }
    else{
        cout<<"a and b are not equal"<<endl;
    }
    
    Integer c;
    c=a;
    cout<<"value in c: "<<c.GetValue()<<endl;
    
    Integer d = c+5;
    Integer e = 4+d;
    
    cout<<"d: "<<d<<endl;
    cout<<"e: "<<e<<endl;
    
    std::cin>>a;
    std::cout<<"a: "<<a<<std::endl;
    
    return 0;
}


/*
Output:

sum: 3
sum++: 4
++sum: 4
sum: 5
a and b are not equal
value in c: 1
d: 6
e: 10
423
a: 423

*/
