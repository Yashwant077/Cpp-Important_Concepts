#include <bits/stdc++.h>
using namespace std;

class Person {
    protected:
        string name;
        int age;
    public:
        Person(string name, int age){
            this->name = name;
            this->age = age;
            cout<<"Person constructor is called."<<endl;
        }
        
        virtual void display(){}
};

class Student: public Person {
    int standard;
    public:
        Student(string name, int age, int standard) : Person(name, age){
            this->standard = standard;
            cout<<"Student constructor is called."<<endl;
        }
        
        void display(){
            cout<<"Student name is "<<name<<", age is "<<age<<", and class is "<<standard<<endl;
        }
};

class Employee: public Person {
    string company;
    public:
        Employee(string name, int age, string company) : Person(name, age){
            this->company=company;
            cout<<"Employee constructor is called."<<endl;
        }
        
        void display(){
            cout<<"Employee name is "<<name<<", age is "<<age<<", and company is "<<company<<endl;
        }
};

int main()
{
    // string name, company;
    // int age, standard;
    
    // name = "Yashwant";
    // company = "CG";
    // age = 8;
    // standard = 5;
    
    Student student("Atharv", 5, 1);
    student.display();
    
    Employee employee("Yashwant", 26, "Capgemini");
    employee.display();
    
    
    cout<<endl;
    cout<<"============Using pointer of base class==============="<<endl;
    cout<<endl;
    
    Person* p[2];
    p[0] = &student;
    p[1] = &employee;
    
    p[0]->display();
    p[1]->display();
    
    return 0;
}














/*Output:
Person constructor is called.
Student constructor is called.
Student name is Atharv, age is 5, and class is 1
Person constructor is called.
Employee constructor is called.
Employee name is Yashwant, age is 26, and company is Capgemini

============Using pointer of base class===============

Student name is Atharv, age is 5, and class is 1
Employee name is Yashwant, age is 26, and company is Capgemini
*/
