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

/*
Recursion Approach

#include <bits/stdc++.h>
#define int long long

const int N = 3001;
int dp[N][N];
int used[N][N];
int n;

int f(int lo, int hi, int taro, int jiro, std::vector<int> &arr) {
	if (used[lo][hi]) {
		return dp[lo][hi] + taro - jiro;
	}
	if (lo + hi == n) {
		return taro - jiro;
	}
	used[lo][hi] = 1;
	int res = 0;
	if ((lo + hi) % 2 == 0) {
		res = std::max(f(lo + 1, hi, taro + arr[lo], jiro, arr), f(lo, hi + 1, taro + arr[n - hi - 1], jiro, arr));
	} else {
		res = std::min(f(lo + 1, hi, taro, jiro + arr[lo], arr), f(lo, hi + 1, taro, jiro + arr[n - hi - 1], arr));
	}
	dp[lo][hi] = res - taro + jiro;
	return res;
}
int32_t main() {
	std::cin >> n;
	std::vector<int> arr(n);
	for (auto &x : arr) {
		std::cin >> x;
	}
	memset(used, 0, sizeof(used));
	std::cout << f(0, 0, 0, 0, arr) << '\n';
	return 0;
}

*/