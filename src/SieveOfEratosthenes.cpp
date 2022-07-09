#include <iostream>
#include <cmath> // For the function 'sqrt()'
using namespace std;

int main() {
    // In mathematics, the sieve of Eratosthenes is an ancient algorithm for finding all prime numbers up to any given limit.
    // Widely used to get an array of primes up to a integer.

    int num;
    cout << "\nType a number: ";
    cin >> num;
    
    if (num < 0) {
        cout << "Please type a positive number!";
        return 0;
    }
    
    // Firstly, we create an array which indicates if a number is prime
    bool num_array[num]; 
    for (int i = 0; i < num; i++) {
        num_array[i] = true;
    }
    num_array[0] = false;
    num_array[1] = false;

    // Secondly, we will filter through the array and make all the integers which are a multiplication of a prime false 
    for (int i = 2; i < sqrt(num); i++) {
        if (num_array[i] == true) {
            for (int j = pow(i, 2); j < num; j+=i) {
                num_array[j] = false;
            }
        }
    } 
    
    // Finally, output the prime prime numbers
    string output = "All prime numbers:";
    for (int i = 0; i < num; i++) {
        if (num_array[i]) output += " "+to_string(i);
    }

    cout << output;

    return 0;
}

// More info: https://www.geeksforgeeks.org/sieve-of-eratosthenes/
