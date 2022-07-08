#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cctype>


#define SIZE 30

using namespace std;

void bruteForce(char string[SIZE], char subString[SIZE], int lengthString, int lengthSubString);

int main() {
    int lengthString, lengthSubString;
    float start, end, time;
    char string[SIZE], subString[SIZE];

    cout << "\nEnter the string: ";
    gets(string);

    cout << "\nEnter the substring to find: ";
    gets(subString);

    lengthString = strlen(string);
    lengthSubString = strlen(subString);
    cout << "\n" << lengthString;
    cout << "\n" << lengthSubString;

    start = clock();
    bruteForce(string, subString, lengthString, lengthSubString);
    end = clock();

    time = end - start;

    cout << "\nExecution Time is:  " << (double) time / ((double) CLOCKS_PER_SEC) << " ms";

    system("pause");
    return 0;
}


void bruteForce(char string[SIZE], char subString[SIZE], int lengthString, int lengthSubString) {
    int i, j, k, band = 0;

    for (i = 0; i <= lengthString - lengthSubString; i++) {
        k = i;
        j = 0;

        while (string[k] == subString[j] && j <= lengthSubString) {
            k++;
            j++;
        }

        if (j > lengthSubString - 1) {
            cout << "\nThe substring pattern was found at position: " << i;
            band = 1;
        } else
            band = 0;
    }
    if (band == 0)
        cout << "\nThe substring pattern was not found.";
    return;
}

