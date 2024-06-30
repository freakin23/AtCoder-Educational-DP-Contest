#include <bits/stdc++.h>
#define int long long

int32_t main() {
    int n, W;
    std::cin >> n >> W;
    std::vector<int> w(n), v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> w[i] >> v[i];
    }

    std::vector<std::vector<int>> dp(n + 1, std::vector<int> (100001, 0x3f3f3f3f3f3f3f3fLL));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 100001; j++) {
            if (j - v[i] >= 0) {
                dp[i + 1][j] = std::min(dp[i][j], dp[i][j - v[i]] + w[i]); 
            } else {
                dp[i + 1][j] = dp[i][j];
            }
        }
    }

    int res = 0;
    for (int i = 0; i <= 100000; i++) {
        if (dp[n][i] <= W) {
            res = i;
        }
    } 

    std::cout << res << '\n';
    return 0;
}