#include<iostream>
#include<queue>

using namespace std;

bool QueueCheck(queue<int> queue, int value)
{
	bool isBiggerExists = false;
	while (!queue.empty())
	{
		if (queue.front() > value)
		{
			isBiggerExists = true;
			break;
		}
		queue.pop();
	}
	return isBiggerExists;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	queue<int> queue;
	int n, wanted, tcAmount, order;
	cin >> tcAmount;
	
	for (int i = 0; i < tcAmount; ++i)
	{
		while (!queue.empty()) queue.pop();
		order = 0;
		cin >> n >> wanted;

		for (int j = 0; j < n; ++j)
		{
			int push;
			cin >> push;
			queue.push(push);
		}

		while (!queue.empty())
		{
			if (QueueCheck(queue, queue.front()))
			{
				if (wanted == 0) wanted = queue.size();
				queue.push(queue.front());
				queue.pop();
			}
			else
			{
				if (wanted == 0) break;
				queue.pop();
				++order;
			}
			--wanted;
		}

		cout << (order + 1) << '\n';
	}

	return 0;
}