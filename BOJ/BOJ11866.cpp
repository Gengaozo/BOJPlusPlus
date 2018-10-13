#include<iostream>
#include<queue>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	queue<int> queue;
	int	n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		queue.push(i + 1);
	}

	cout << '<';

	int* pushes = new int[m - 1];
	while (queue.size() > 1)
	{
		int repeatCount = (m - 1) % queue.size();
		for (int i = 0; i < repeatCount; ++i)
		{
			pushes[i] = queue.front();
			queue.pop();
		}
		cout << queue.front() << ", ";
		queue.pop();
		for (int i = 0; i < repeatCount; ++i)
		{
			queue.push(pushes[i]);
		}
	}

	cout << queue.front();
	cout << '>';
	return 0;
}