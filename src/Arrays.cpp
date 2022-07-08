#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{

    char name[15];
    float grades[3];
    float average;

    cout << "\nIntroduce your name: ";
    cin >> name;
    cout << "\nIntroduce your first grade: ";
    cin >> grades[0];
    cout << "\nIntroduce your second grade:";
    cin >> grades[1];
    cout << "\nIntroduce your third grade:";
    cin >> grades[2];

    average = (grades[0] + grades[1] + grades[2]) / 3;

    cout << "\nName: " << name;
    cout << "\nAverage Grade: " << average;

    return 0;
}