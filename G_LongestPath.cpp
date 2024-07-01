#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
std::vector<int> adj[N];
int dp[N];

int dfs(int j) {
    if (dp[j] != -1) {
        return dp[j];
    }
    int res = 0;
    for (auto u : adj[j]) {
        res = std::max(res, dfs(u) + 1);
    }
    dp[j] = res;
    return dp[j];
}

int main() {
    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
    }
    memset(dp, -1, sizeof(dp));
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res = std::max(res, dfs(i));
    }

    std::cout << res << '\n'; 
    return 0;  
}
