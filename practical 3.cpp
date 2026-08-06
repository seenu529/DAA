#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace chrono;

long long maxComparisons = 0, maxSwaps = 0;
long long minComparisons = 0, minSwaps = 0;

//---------------- MAX HEAP ----------------//
void maxHeapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n)
    {
        maxComparisons++;
        if (arr[left] > arr[largest])
            largest = left;
    }

    if (right < n)
    {
        maxComparisons++;
        if (arr[right] > arr[largest])
            largest = right;
    }

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        maxSwaps++;
        maxHeapify(arr, n, largest);
    }
}

void maxHeapSort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        maxSwaps++;
        maxHeapify(arr, i, 0);
    }
}

//---------------- MIN HEAP ----------------//
void minHeapify(vector<int> &arr, int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n)
    {
        minComparisons++;
        if (arr[left] < arr[smallest])
            smallest = left;
    }

    if (right < n)
    {
        minComparisons++;
        if (arr[right] < arr[smallest])
            smallest = right;
    }

    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        minSwaps++;
        minHeapify(arr, n, smallest);
    }
}

void minHeapSort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        minSwaps++;
        minHeapify(arr, i, 0);
    }

    reverse(arr.begin(), arr.end());
}

//---------------- DISPLAY FUNCTION ----------------//
void display(vector<int> arr)
{
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}

//---------------- MAIN ----------------//
int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> original(n);

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
        cin >> original[i];

    vector<int> maxHeapArray = original;
    vector<int> minHeapArray = original;

    cout << "\nOriginal Array:\n";
    display(original);

    //--------------- MAX HEAP SORT ----------------//
    auto startMax = high_resolution_clock::now();
    maxHeapSort(maxHeapArray);
    auto endMax = high_resolution_clock::now();

    //--------------- MIN HEAP SORT ----------------//
    auto startMin = high_resolution_clock::now();
    minHeapSort(minHeapArray);
    auto endMin = high_resolution_clock::now();

    //--------------- RESULTS ----------------//
    cout << "\n===== MAX HEAP SORT =====\n";
    cout << "Sorted Array: ";
    display(maxHeapArray);

    cout << "Comparisons : " << maxComparisons << endl;
    cout << "Swaps       : " << maxSwaps << endl;
    cout << "Execution Time: "
         << duration_cast<microseconds>(endMax - startMax).count()
         << " microseconds\n";

    cout << "\n===== MIN HEAP SORT =====\n";
    cout << "Sorted Array: ";
    display(minHeapArray);

    cout << "Comparisons : " << minComparisons << endl;
    cout << "Swaps       : " << minSwaps << endl;
    cout << "Execution Time: "
         << duration_cast<microseconds>(endMin - startMin).count()
         << " microseconds\n";

    cout << "\n----- DAA Analysis -----\n";
    cout << "Best Case   : O(n log n)\n";
    cout << "Average Case: O(n log n)\n";
    cout << "Worst Case  : O(n log n)\n";
    cout << "Space Complexity: O(1)\n";

    return 0;
}