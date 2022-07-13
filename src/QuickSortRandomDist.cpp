#include <iostream>
#include <random>
#include <chrono>

using namespace std;

void generate_random_numbers(int * V, int n);

void print_vector(int * V, int n);

int partition(int * V, int lower, int upper);

void quicksort(int * V, int lower, int upper);

void swap(int * V, int i, int j);

bool is_ordered(const int * V, int n);

using namespace std;

int main()
{
    const int n = 20;
    int V[n];

    generate_random_numbers(V, n); // Generating Random Numbers using a Discrete Uniform Distribution

    print_vector(V, n); // Printing the Initial Previously Generated Array

    // --- The Quicksort Algorithm --- //
    clock_t start_time = clock(); //Starts Tracking Time
    quicksort(V, 0, n); // QuickSort!!
    clock_t end_time = clock(); // Finished Tracking Time
    clock_t total_time = end_time - start_time; // Computing the Total Time
    double time_in_seconds = total_time / (double) CLOCKS_PER_SEC; // Converting Total Time to Seconds
    cout << "\nTotal of numbers ordered: " << n << endl;
    cout << "Time in Seconds: " << time_in_seconds << endl;
    cout << "Is it ordered? : " <<  is_ordered(V, n) << endl;

    print_vector(V, n); // Printing the Ordered Array

    return 0;


}

void generate_random_numbers(int *V, int n) {
    unsigned t = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine f(t);
    // Generates a Random Probability Distribution. Feel free with two bounds, the lower limit and upper limit.
    // Feel free to change the parameters
    uniform_int_distribution<int> uniformDistribution(-20, 20);

    for (int i = 0; i < n; i++)
        V[i] = uniformDistribution(f);

}

void print_vector(int *V, int n) {
    if(is_ordered(V, n))
        cout << "\nOrdered Array: " << endl;
    else cout << "\nInitial Array: " << endl;

    for (int i = 0; i < n; i++)
        cout << V[i] << " ";

    cout << endl;
}

int partition(int * V, int lower, int upper)
{
    int pivot = V[lower];
    int i = lower;

    for (int j = lower + 1; j < upper; j++)
    {
        if (V[j] < pivot)
        {
            i++;
            swap(V, i, j);
        }
    }
    swap(V, lower, i);

    return i;
}

void quicksort(int * V, int lower, int upper)
{
    if (lower < upper)
    {
        int pivot_position = partition(V, lower, upper);

        quicksort(V, lower, pivot_position);
        quicksort(V, pivot_position + 1, upper);
    }
}

void swap(int * V, int i, int j)
{
    int aux = V[i];
    V[i] = V[j];
    V[j] = aux;
}

bool is_ordered(const int * V, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (V[i] > V[i + 1])
            return false;
    }
    return true;
}