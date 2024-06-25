#include <bits/stdc++.h>
#define int long long

int32_t main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i] >> b[i] >> c[i];
    }

    std::vector<std::vector<int>> dp(n + 1, std::vector<int> (3, 0));
    for (int i = 0; i < n; i++) {
        dp[i + 1][0] = std::max(dp[i][1] + a[i], dp[i][2] + a[i]);
        dp[i + 1][1] = std::max(dp[i][0] + b[i], dp[i][2] + b[i]);
        dp[i + 1][2] = std::max(dp[i][0] + c[i], dp[i][1] + c[i]);
    }

    int res = 0;
    for (int i = 0; i < 3; i++) {
        res = std::max(res, dp[n][i]);
    }
    std::cout << res << '\n';
    return 0;
}