#include <iostream>

using namespace std;

// Printing names and ages using a struct

struct info
{
    char names[5][30]={"Mark", "Joseph", "Anna", "Pedro", "Michelle"};
    int age[5]={21, 22, 23, 24, 25};
}data;

int main()
{
    char space[3] = ", ";

    cout << "\nStudent's Information";
    cout << "\nNames & Ages";
    cout << "\n-----------------------------";
    cout << endl << data.names[0] << space << data.age[0];
    cout << endl << data.names[1] << space << data.age[1];
    cout << endl << data.names[2] << space << data.age[2];
    cout << endl << data.names[3] << space << data.age[3];
    cout << endl << data.names[4] << space << data.age[4];
    return 0;
}