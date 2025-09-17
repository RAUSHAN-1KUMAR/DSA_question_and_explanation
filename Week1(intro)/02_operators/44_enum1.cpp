
#include<iostream>
using namespace std;

enum dept {CS=1, ECE, IT, CIVIL};//->if we mention some starting number then the remaining will take the next number.
    
int main(){
    dept d = CS;//-> we can now declare a variable d by our user defined data type which is dept.
    cout << d << endl;

    enum day {mon=1, tue, wed=5, thur, fri, sat = 9, sun};
    day r = fri;
    day o = sun;
    cout << r << " " << o << endl;

    return 0;
}


