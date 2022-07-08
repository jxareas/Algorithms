/*
 * Calculating the computational cost in the worst case.
 * Ordering an array in ascending order via the Bubble Sort Algorithm
 * */


#include <iostream>
#include <cstdlib>

using namespace std;

#define SIZE 10

int main() {
    int a[SIZE] = {2, 6, 4, 8, 10, 12, 89, 68, 45, 37};
    int i, j, aux;

    cout << "\nArray elements in their original order:\n";        // 1 step

    for (i = 0; i < SIZE; i++) // 1 + n+1 + n+1
        cout << a[i] << ' '; // 2n									// 4n+3 steps

    for (j = 1; j < SIZE; j++) // 1 + n + n
        for (i = 0; i < SIZE - 1; i++) // 1 + n + n						// 4n2+4n+2 steps
            if (a[i] > a[i + 1]) // 4									// 13n2 steps
            {
                aux = a[i]; // 2
                a[i] = a[i + 1]; // 4
                a[i + 1] = aux; // 3
            }

    cout << "\n\nArray Elements in ascending order:\n";    // 1 step

    for (i = 0; i < SIZE; i++) // 1 + n+1 + n+1
        cout << a[i] << ' '; // 2(n)								// 4n2+3 steps

    cout << "\n\n"; // 1
    system("PAUSE"); // 1
    return 0; // 1												// 3 steps
}

// Final Analysis: 1 + 4n+3 + 4n2+4n+2 + 13n2 + 1 + 4n2+3 + 3
//   = 21n2 + 8n + 13 = T(n) = O(n2)
