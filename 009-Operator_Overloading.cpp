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

int main()
{
    Integer a(1), b(2);
    Integer sum = a + b;
    cout<<"sum: "<<sum.GetValue()<<endl;
    cout<<"sum++: "<<(++sum).GetValue()<<endl;
    cout<<"++sum: "<<(sum++).GetValue()<<endl;
    cout<<"sum: "<<sum.GetValue()<<endl;
    
    return 0;
}
