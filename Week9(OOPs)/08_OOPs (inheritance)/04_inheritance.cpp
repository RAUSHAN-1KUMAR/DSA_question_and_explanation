/*
Mode of inheritance:
    1. public-> [class parent_class:public child_class{};]
        - public data of parent_class goes to public section of child_class.
        - protected data of parent_class goes to protected section of child_class.
        - private data of parent_class NotAcccessible(NA).

    2. protected-> [class parent_class:protected child_class{};]
        - public data of parent_class goes to protected section of child_class.
        - protected data of parent_class goes to protected section of child_class.
        - private data of parent_class NotAcccessible(NA).

    3. private-> [class parent_class:private child_class{};]
        - public data of parent_class goes to private section of child_class.
        - protected data of parent_class goes to private section of child_class.
        - private data of parent_class NotAcccessible(NA).

In C++, inheritance is resolved during compilation and object construction, not dynamically at runtime (except for virtual functions).
*/

/*
private:-> members declared private are only accessible within its class itself.

protected-> members declared protected are accessible within class itself and to its derived class only. 

public-> members declared public are accessible from anywhere inside the code.
*/


// inheritance is a: "is-a" relation

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Bird
{
public:
    int age, weight;
    int nolegs;
    string color;

    Bird(){
        cout << "non-parameterized cotr called for Bird called" << endl;
    }
    
    void eat()
    {
        cout << "Bird is eating" << endl;
    }
    
    void fly()
    {
        cout << "Bird is flying" << endl;
    }
};


// public means: bird ki saari public cheeze include ker lena at compile time
class Sparrow:public Bird
{
public:
    Sparrow(){
        cout << "non-parameterized cotr called for Sparrow called" << endl;
    }
    
    Sparrow(int age, int weight, string color, int nolegs)
    {
        this->age = age;
        this->weight = weight;
        this->color = color;
        this->nolegs = nolegs;
        cout << "parameterized cotr called for Sparrow called" << endl;
    }
    
    void grassing()
    {
        cout << "sparrow is grassing" << endl;
    }
};


// the class Pegion does not contain the data members of Bird, but when I create an object of Pegion, all data members and functions of Bird are included in that object at compile time”
class Pegion:public Bird
{
public:
    Pegion(){
        cout << "non-parameterized cotr called for Pegion called" << endl;
    }
    
    void guttering()
    {
        cout << "pegion is guttering" << endl;
    }
};



int main()
{
    Sparrow s(1, 1, "brown", 2);
    cout << s.color << endl;
    s.eat();
    s.grassing();

    cout << endl;

    Pegion p;
    p.eat();
    p.fly();
    p.guttering();

    return 0;
}
