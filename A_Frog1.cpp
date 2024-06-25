#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> Arr(n);
    for (auto &x : Arr) {
        std::cin >> x;
    }
    std::vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    dp[1] = abs(Arr[1] - Arr[0]);

    for (int i = 2; i < n; i++) {
        dp[i] = std::min(dp[i - 1] + abs(Arr[i - 1] - Arr[i]), dp[i - 2] + abs(Arr[i] - Arr[i - 2]));
    }
    std::cout << dp[n - 1] << '\n';
    return 0;
}