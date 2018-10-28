#include<iostream>

using namespace std;


#define max(a, b) ((a > b) ? a : b)

int stairs[301];
int dp[301];
	
int main(void)
{
	ios::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int count;
	cin >> count;
	for (int i = 1; i <= count; ++i)
	{
		int value;
		cin >> value;
		stairs[i] = value;
	}

	dp[1] = stairs[1];

	for (int i = 2; i <= count; ++i)
	{
		dp[i] = max(dp[i - 2], ((i > 2) ? dp[i - 3] : 0) + stairs[i - 1]) + stairs[i];
	}

	cout << dp[count];
	return 0;
}