#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<utility>

using namespace std;

pair<int, int> countPair[41] = { { 1, 0 }, { 0, 1 }, { 0, 0 }, };

//왜 항상 파라미터에 레퍼런스를 붙일까? 그 이유는 값 복제가 아닌 참조로 들어가기 때문.
pair<int, int> operator+ (const pair<int, int>& left, const pair<int, int>& right)
{
	return { left.first + right.first, left.second + right.second };
}

pair<int, int> fibonacci(int num)
{	
	if (num == 0) return countPair[0];
	if (num == 1) return countPair[1];

	if ((countPair[num].first | countPair[num].second) == 0)	//둘 다 0일 시
		countPair[num] = fibonacci(num - 1) + fibonacci(num - 2);
	return countPair[num];
}

int main(void)
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		countPair[n] = fibonacci(n);
		printf("%d %d\n", countPair[n].first, countPair[n].second);
	}

	return 0;
}