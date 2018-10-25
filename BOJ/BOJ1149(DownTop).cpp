#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#define R 0
#define G 1
#define B 2

using namespace std;

int dp[3][1000];

#define min(a,b) ((a < b) ? a : b)

int main(void)
{
	int houseCount, r, g, b;
	scanf("%d", &houseCount);

	scanf("%d %d %d", &r, &g, &b);
	dp[R][0] = r;
	dp[G][0] = g;
	dp[B][0] = b;

	for (int i = 1; i < houseCount; ++i)
	{
		scanf("%d %d %d", &r, &g, &b);
		dp[R][i] = min(dp[G][i - 1], dp[B][i - 1]) + r;
		dp[G][i] = min(dp[R][i - 1], dp[B][i - 1]) + g;
		dp[B][i] = min(dp[G][i - 1], dp[R][i - 1]) + b;
	}

	printf("%d\n", min(dp[R][houseCount - 1], min(dp[G][houseCount - 1], dp[B][houseCount - 1])));
	return 0;
}