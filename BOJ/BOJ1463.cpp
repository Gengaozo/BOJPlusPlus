#include<iostream>

int dp[1000001];

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	dp[1] = 0;
	for (int i = 2; i <= n; ++i) dp[i] = 0x7fffffff;

	for (int i = 1; i <= n; ++i)
	{
		if (i * 3 <= n && dp[i * 3] > dp[i] + 1)
			dp[i * 3] = dp[i] + 1;
		if (i * 2 <= n && dp[i * 2] > dp[i] + 1)
			dp[i * 2] = dp[i] + 1;
		if (i + 1 <= n && dp[i + 1] > dp[i] + 1)
			dp[i + 1] = dp[i] + 1;
	}

	cout << dp[n];
	return 0;
}