#include<iostream>
#include<queue>
#include<map>

using namespace std;

int costs[1000];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--)
	{
		queue<int> q;
		multimap<int, int> rule;
		int buildingCount, ruleCount, goal, cost;
		cin >> buildingCount >> ruleCount;
		for (int i = 0; i < buildingCount; ++i)
		{
			cin >> cost;
			costs[i] = cost;
		}
		for (int i = 0; i < ruleCount; ++i)
		{
			int req, num;
			cin >> req >> num;
			rule.insert(make_pair(num - 1, req - 1));
		}

		cin >> goal;
		for (int i = 0; i < buildingCount; ++i)
		{
			
		}

	}

	return 0;
}