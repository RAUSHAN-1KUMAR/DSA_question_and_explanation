// inside .h file, ham bas declaration dalte h


#ifndef MYSTRING_H
#define MYSTRING_H

#include<iostream>
using namespace std;

class MyString
{
private:
    char *data;// pointer to char array data
    int length;// size of my string

public:
    // default ctor
    MyString();

    // param. ctor
    MyString(const char* str);

    // copy ctor
    MyString(const MyString& other);

    // dtor
    ~MyString();

    // functions of our string class 
    int size() const; 

    bool empty() const;

    const char *c_str() const;
    
    int find(const MyString& substr) const;

    //operator overloading for cout
    friend std::ostream& operator<<(std::ostream& os, const MyString&str);

    //operator overloading for []
    char operator[](int index);
};


#endif