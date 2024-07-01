#include <bits/stdc++.h>

const int md = 1'000'000'007;
int main() {
    int h, w;
    std::cin >> h >> w;
    std::vector<std::vector<int>> grid(h + 1, std::vector<int> (w + 1));
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            char x;
            std::cin >> x;
            grid[i][j] = (x == '.' ? 1 : 0);
        }
    }

    std::vector<std::vector<int>> dp(h + 1, std::vector<int> (w + 1, 0));
    dp[1][1] = 1;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (i == 1 and j == 1) {
                continue;
            }
            if (grid[i][j] == 1) {
                (dp[i][j] += dp[i - 1][j] + dp[i][j - 1]) %= md;
            }   
        }
    }
    std::cout << dp[h][w] << '\n';
    return 0;
}