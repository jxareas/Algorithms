//Recursive program to calculate the sum of 1^2 + 2^2 + 3^2 + ... + N^2
#include<iostream>
#include<cmath>
using namespace std;

float squared_sum(int n)
{
    float sum = 0;

    if(n == 1)
        sum = 1; // Base
    else
        sum = pow(n, 2) + squared_sum(n - 1);  // General case

    return sum;
}

int  main()
{
    int n;
    do
    {
        cout << "Enter an integer: ";
        cin >> n;

        if(n <= 0)
            cout<<"Number must be greater than 0" << endl;
    }while(n <= 0);

    cout << "The sum of 1^2 + 2^2 + 3^2 + ... + N^2 when N is equal to "
         << n << " is: " << squared_sum(n);

    cout <<"\n\n";
    system("cmd /C pause");
    return 0;
}
