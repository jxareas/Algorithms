#include <iostream>
#include <cstdio>

using namespace std;

int power(int base, int n);

int main() {
    int base, exp;
    float result;

    printf("\nEnter the base: ");
    scanf("%d", &base);

    printf("\nEnter the exponent: ");
    scanf("%d", &exp);

    result = power(base, exp);

    printf("\nThe result of %d to the power of %d is %f", base, exp, result);

    cout << "\n\n";
    system("pause");
    return 0;
}

int power(int base, int n) {
    int partial_result;
    int current_exponent;

    switch (n) {
        case 0:
            return 1;
            break;

        case 1:
            return base;
            break;

        case 2:
            return (base * base);
            break;

        default:
            current_exponent = n / 2; /*Divide by half */
            partial_result = power(base, current_exponent);

            if (n % 2 == 0)
                return partial_result * partial_result; /*If the exponent is an even number*/
            else
                return partial_result * partial_result * base; /*If the exponent is an odd number*/
    }
}
