#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> coinChange(vector<int>& coins, int amount) {
    // dp[i] = minimum number of coins needed to make amount i
    vector<int> dp(amount + 1, amount + 1);

    // selectedCoin[i] = coin used to get the optimal solution for i
    vector<int> selectedCoin(amount + 1, -1);

    dp[0] = 0;

    // Build DP table
    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (coin <= i && dp[i - coin] + 1 < dp[i]) {
                dp[i] = dp[i - coin] + 1;
                selectedCoin[i] = coin;
            }
        }
    }

    // No solution
    if (dp[amount] == amount + 1) {
        return {};
    }

    // Reconstruct the coins
    vector<int> result;
    int current = amount;

    while (current > 0) {
        int coin = selectedCoin[current];
        result.push_back(coin);
        current -= coin;
    }

    return result;
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    vector<int> result = coinChange(coins, amount);

    if (result.empty()) {
        cout << "No solution exists." << endl;
    } else {
        cout << "Minimum number of coins: "
             << result.size() << endl;

        cout << "Coins used: ";

        for (int coin : result) {
            cout << coin << " ";
        }

        cout << endl;
    }

    return 0;
}
