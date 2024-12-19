/*
Move Semantics implementations

*/

#include <iostream>
using namespace std;

class Integer {
    int *m_pInt;
    
    public:
    // Default constructor
    Integer(){
        cout<<"Integer()"<<endl;
        m_pInt = new int(0);
    }
    
    // Parameterized constructor
    Integer(int value){
        cout<<"Integer(int)"<<endl;
        m_pInt = new int(value);
    }
    
    // Deep copy constructor
    Integer(const Integer &obj){
        cout<<"Integer(const Integer &)"<<endl;
        m_pInt = new int(*obj.m_pInt);
    }
    
    // Move constructor
    Integer(Integer &&obj){
        cout<<"Integer(Integer &&)"<<endl;
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
    
    // Destructor
    ~Integer(){
        cout<<"~Integer()"<<endl;
    }
    
};

Integer Add(const Integer &a, const Integer &b){
    Integer temp;
    temp.SetValue(a.GetValue() + b.GetValue());
    return temp;
}

int main()
{
    // Integer a(1), b(3);
    // a.SetValue(Add(a,b).GetValue());
    
    Integer a(1);
    auto b{std::move(a)};
    auto c{a};
    a.SetValue(5);
    cout<<"a: "<<a.GetValue()<<endl;
    
    return 0;
}
