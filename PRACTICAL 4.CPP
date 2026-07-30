#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Iterative Factorial
unsigned long long iterativeFactorial(int n)
{
    unsigned long long fact = 1;

    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;
    }

    return fact;
}

// Recursive Factorial
unsigned long long recursiveFactorial(int n)
{
    if (n == 0 || n == 1)
        return 1;

    return n * recursiveFactorial(n - 1);
}

int main()
{
    int n;

    cout << "Enter a number: ";
    cin >> n;

    // Iterative Time
    auto start1 = high_resolution_clock::now();
    unsigned long long ans1 = iterativeFactorial(n);
    auto stop1 = high_resolution_clock::now();

    // Recursive Time
    auto start2 = high_resolution_clock::now();
    unsigned long long ans2 = recursiveFactorial(n);
    auto stop2 = high_resolution_clock::now();

    auto time1 = duration_cast<nanoseconds>(stop1 - start1);
    auto time2 = duration_cast<nanoseconds>(stop2 - start2);

    cout << "\nFactorial using Iterative = " << ans1 << endl;
    cout << "Execution Time = " << time1.count() << " ns" << endl;

    cout << "\nFactorial using Recursive = " << ans2 << endl;
    cout << "Execution Time = " << time2.count() << " ns" << endl;

    return 0;
}