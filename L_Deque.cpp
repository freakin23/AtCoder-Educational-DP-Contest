#include <bits/stdc++.h>
#define int long long

int32_t main() {
	int n;
	std::cin >> n;
	std::vector<int> arr(n);
	for (auto &x : arr) {
		std::cin >> x;
	}
	std::vector<std::vector<int>> dp(n + 1, std::vector<int> (n + 1, 0));
	for (int i = 0; i < n; i++) {
		dp[i][i] = arr[i];
	}

	for (int i = n - 1; i >= 0; i--) {
		for (int j = i + 1; j < n; ++j) {
			dp[i][j] = std::max(arr[i] - dp[i + 1][j], arr[j] - dp[i][j - 1]);
		}
	}
	std::cout << dp[0][n - 1] << '\n';
	return 0;
}