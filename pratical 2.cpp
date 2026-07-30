#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

// Linear Search
int linearSearch(const vector<int> &a, int key)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == key)
            return i;
    }
    return -1;
}

// Binary Search
int binarySearch(const vector<int> &a, int key)
{
    int low = 0, high = a.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (a[mid] == key)
            return mid;
        else if (a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    int n, key;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> a(n);

    // Creating sorted array
    for (int i = 0; i < n; i++)
        a[i] = i + 1;

    cout << "Enter element to search: ";
    cin >> key;

    int pos;

    // Linear Search
    auto start = high_resolution_clock::now();
    pos = linearSearch(a, key);
    auto end = high_resolution_clock::now();

    cout << "\n----- Linear Search -----\n";
    if (pos != -1)
        cout << "Element found at index " << pos << endl;
    else
        cout << "Element not found" << endl;

    cout << "Time Taken: "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds\n";

    // Binary Search
    start = high_resolution_clock::now();
    pos = binarySearch(a, key);
    end = high_resolution_clock::now();

    cout << "\n----- Binary Search -----\n";
    if (pos != -1)
        cout << "Element found at index " << pos << endl;
    else
        cout << "Element not found" << endl;

    cout << "Time Taken: "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds\n";

    cout << "\nComplexity Analysis\n";
    cout << "Linear Search : O(n)\n";
    cout << "Binary Search : O(log n)\n";

    return 0;
}