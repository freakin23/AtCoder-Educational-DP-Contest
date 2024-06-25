#include <bits/stdc++.h>
#define int long long

int32_t main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> h(n);
    for (auto &x : h) {
        std::cin >> x;
    }

    std::vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = std::min(n - 1, i + k); j > i; j--) {
            dp[j] = std::min(dp[j], dp[i] + abs(h[i] - h[j]));
        }
    }

    std::cout << dp[n - 1] << '\n';
    return 0;
}