#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>

#define R 0
#define G 1
#define B 2

using namespace std;

struct House
{
	int r;
	int g;
	int b;
	void Set(int _r, int _g, int _b)
	{
		r = _r;
		g = _g;
		b = _b;
	}
};
House* houses;
int dp[3][1001];

int Draw(int idx, int color)
{
	if (color == R)
	{
		if (idx == 0)
		{
			if (dp[R][0] == 0)
				dp[R][0] = houses[0].r;
			return dp[R][0];
		}

		if (dp[R][idx] == 0)
		{
			int g = Draw(idx - 1, G) + houses[idx].r;
			int b = Draw(idx - 1, B) + houses[idx].r;
			dp[R][idx] = (g < b) ? g : b;
		}
		return dp[R][idx];
	}
	else if (color == G)
	{
		if (idx == 0)
		{
			if (dp[G][0] == 0)
				dp[G][0] = houses[0].g;
			return dp[G][0];
		}

		if (dp[G][idx] == 0)
		{
			int r = Draw(idx - 1, R) + houses[idx].g;
			int b = Draw(idx - 1, B) + houses[idx].g;
			dp[G][idx] = (r < b) ? r : b;
		}
		return dp[G][idx];
	}
	else
	{
		if(idx == 0)
		{
			if (dp[B][0] == 0)
				dp[B][0] = houses[0].b;
			return dp[B][0];
		}

		if (dp[B][idx] == 0)
		{
			int r = Draw(idx - 1, R) + houses[idx].b;
			int g = Draw(idx - 1, G) + houses[idx].b;
			dp[B][idx] = (r < g) ? r : g;
		}
		return dp[B][idx];
	}
}

int main(void)
{
	int houseCount;
	scanf("%d", &houseCount);
	houses = new House[houseCount];
	for (int i = 0; i < 3; ++i)
	{
		memset(dp[i], 0, sizeof(dp[i]));
	}

	for (int i = 0; i < houseCount; ++i)
	{
		int r, g, b;
		scanf("%d %d %d", &r, &g, &b);
		houses[i].Set(r, g, b);
	}

	int min = 0x7fffffff;	//2147483647

	for (int i = 0; i < 3; ++i)
	{
		int cost = Draw(houseCount - 1, i);
		if (min > cost) min = cost;
	}

	printf("%d\n", min);
	delete[] houses;
	return 0;
}