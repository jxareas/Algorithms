#include <iostream>
#include <cstdlib>
#include <cstdio>

#define N 100

int table[N];

using namespace std;

void prime_numbers(int n, int tabla[]);

int main() {
    int n;

    cout << "\nEnter the quantity of numbers to evaluate: ";
    cin >> n;

    prime_numbers(n, table);

    cout << "\nPrime Numbers from 1 to N" << endl;
    for (int i = 1; i < n; i++)
        cout << table[i] << "\t";
    cout << endl;

    cout << endl;
    system("pause");
    return 0;
}

void prime_numbers(int n, int tabla[]) {
    int i, j; // i: This is the number to evaluate
    int total_prime_numbers = 1;

    for (i = 2; i <= n; i++) {
        j = 1;

        while ((j < total_prime_numbers) && (i % tabla[j] != 0)) // Divide by each last number starting from 1
            j++;
        if (j == total_prime_numbers) {
            tabla[total_prime_numbers] = i;
            total_prime_numbers++;
        }
    }
}
