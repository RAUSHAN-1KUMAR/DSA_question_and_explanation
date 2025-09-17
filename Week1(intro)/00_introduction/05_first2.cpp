#include<iostream>
using namespace std;

int main()
{
    string name;
    cout << "May I know your name: ";
    //cin >> name;
    getline(cin,name);// getline() function accept and read single and multiple line strings from the input stream. 
    cout << "Welcome Mr./Mrs. " << name << endl;
    return 0;
}

// if we use cin and write Rohit Kumar then it will only read Rohit.
// if we use getline() and write Rohit Kumar then it will read whole name.




