#include <bits/stdc++.h>

const int MOD = 1'000'000'007;

int Add(int x, int y) {
    if ((x += y) >= MOD) {
        x -= MOD;
    }
    return x;
}

void solve() {
    std::string st; int d;
    std::cin >> st >> d;
    std::vector<std::vector<int>> dp (10001, std::vector<int> (101, 0));
    int n = (int)st.size();
    dp[n][0] = 1;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < d; j++) {
            for (int k = 0; k < 10; k++) {
                dp[i][j] = Add(dp[i][j], dp[i + 1][(j + k) % d]);
            }
        }
    }

    int res = 0, carry = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (st[i] - '0'); j++) {
            res = Add(res, dp[i + 1][(carry + j) % d]);
        }
        carry = (carry + (st[i] - '0')) % d;
    }
    if (carry == 0) {
        res += 1;
    }

    if (res - 1 < 0) {
        res += MOD;
    }
    
    std::cout << res - 1 << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin.exceptions(std::ios::badbit|std::ios::failbit);
    int test = 1;
    // cin >> test;
    while (test-- > 0) {
        solve();
    }
    return 0;
}