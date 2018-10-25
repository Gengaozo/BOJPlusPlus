#include<iostream>

using namespace std;

int dp[500][500];

int max(int a, int b)
{
	return (a > b ? a : b);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int size, ans = 0;
	cin >> size;
	int value;
	cin >> value;
	dp[0][0] = value;
	for (int i = 1; i < size; ++i)	//세로
	{
		for (int j = 0; j <= i; ++j)	//가로
		{
			cin >> value;
			if (i == 1)
				dp[i][j] = value + dp[0][0];
			else
			{
				if (j == 0) dp[i][j] = value + dp[i - 1][j];
				else if (j == i) dp[i][j] = value + dp[i - 1][j - 1];
				else dp[i][j] = value + max(dp[i - 1][j], dp[i - 1][j - 1]);
			}
		}
	}
	for (int i = 0; i < size; ++i)
		if (ans < dp[size - 1][i])
			ans = dp[size - 1][i];
	cout << ans;
	return 0;
}