#include <iostream>
using namespace std;

void insertionSort(int *array, int size)
{
    int x, j;
    for (int i = 1; i < size; i++)
    {
        x = array[i];
        j = i;
        while (j > 0 && array[j - 1] > x)
        {
            array[j] = array[j - 1];
            j--;
        }
        array[j] = x;
    }
}

void display(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }

    cout << endl;
}

int main()
{
    int n;
    cout << "Enter total number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter each element:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "The Unsorted Array: ";
    display(arr, n);
    insertionSort(arr, n);
    cout << "The Sorted Array: ";
    display(arr, n);
}