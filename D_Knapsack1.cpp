#include <bits/stdc++.h>
#define int long long

int32_t main() {
    int N, W;
    std::cin >> N >> W;
    std::vector<int> w(N), v(N);
    for (int i = 0; i < N; i++) {
        std::cin >> w[i] >> v[i];
    }

    std::vector<std::vector<int>> dp(N + 1, std::vector<int> (W + 1, 0));
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= W; j++) {
            dp[i][j] = dp[i - 1][j];
            int left = j - w[i - 1];
            if (left >= 0) {
                dp[i][j] = std::max(dp[i][j], dp[i - 1][left] + v[i - 1]);
            }
        }
    }
    std::cout << dp[N][W] << '\n';
    return 0;
}