#include <iostream>
using namespace std;

// Bubble Sort
void bubbleSort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Partition function for Quick Sort
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quick Sort
void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

// Display Array
void display(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int n, choice;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\nChoose Sorting Algorithm\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Quick Sort\n";
    cout << "Enter choice: ";
    cin >> choice;

    if(choice == 1)
    {
        bubbleSort(arr, n);
        cout << "\nSorted Array using Bubble Sort:\n";
    }
    else if(choice == 2)
    {
        quickSort(arr, 0, n - 1);
        cout << "\nSorted Array using Quick Sort:\n";
    }
    else
    {
        cout << "Invalid Choice!";
        return 0;
    }

    display(arr, n);

    return 0;
}
