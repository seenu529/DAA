#include <iostream>
#include <algorithm>
using namespace std;

int knapsack(int W, int wt[], int profit[], int n)
{
    int K[n + 1][W + 1];

    // Build table K[][] in bottom-up manner
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            // Base case
            if (i == 0 || w == 0)
                K[i][w] = 0;

            // If current item can fit
            else if (wt[i - 1] <= w)
            {
                K[i][w] = max(
                    profit[i - 1] + K[i - 1][w - wt[i - 1]],
                    K[i - 1][w]
                );
            }

            // If current item cannot fit
            else
            {
                K[i][w] = K[i - 1][w];
            }
        }
    }

    return K[n][W];
}

int main()
{
    int profit[] = {12, 10, 20, 15};
    int wt[] = {2, 1, 3, 2};

    int n = 4;
    int W = 5;

    int result = knapsack(W, wt, profit, n);

    cout << "Maximum Profit = " << result << endl;

    return 0;
}
