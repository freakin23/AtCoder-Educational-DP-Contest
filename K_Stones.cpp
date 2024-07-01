#include <bits/stdc++.h>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> stones(n);
    for (auto &x : stones) {
        std::cin >> x;
    }
    std::vector<int> dp(k + 1, 0);
    for (int i = 1; i <= k; i++) {
        for (auto stone : stones) {
            if (i - stone >= 0 and !dp[i - stone]) {
                dp[i] = 1;
                break;
            }
        }
    }

    std::cout << (dp[k] ? "First" : "Second") << '\n';
    return 0;
}