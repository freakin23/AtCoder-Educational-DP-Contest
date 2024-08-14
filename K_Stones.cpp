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

/*
Recursive Approach

#include <bits/stdc++.h>

const int N = 1e5 + 1;
int dp[N];
int f(int x, std::vector<int> &stones) {
    if (x == 0) {
        return 0;
    }
    if (x < 0) {
        return 1;
    }

    if (dp[x] != -1) {
        return dp[x];
    }

    bool ok = false;
    for (auto stone : stones) {
        if (!f(x - stone, stones)) {
            ok = true;
        }
    }
    return dp[x] = ok;
}

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> stones(n);
    for (auto &x : stones) {
        std::cin >> x;
    }
    memset(dp, -1, sizeof(dp));
    std::cout << (f(k, stones) ? "First" : "Second") << '\n';
    return 0;
}
*/