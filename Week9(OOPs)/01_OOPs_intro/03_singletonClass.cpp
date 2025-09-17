#include<bits/stdc++.h>
using namespace std;

class singleton{
    private:
        static singleton* instance;
        singleton(){} // default constructor

    public:
        static singleton* getInstance(){
            if(instance == NULL){
                instance = new singleton();
            }
            return instance;
        }
};

int main()
{


    return 0;
}