#include<iostream>
#include<queue>
#include<utility>

using namespace std;

typedef pair<int, int> Vector2; // {y,x}

int storage[1000][1000];
int day = 0;
int currentCounter = 0;
int nextCounter = 0;
int zero = 0;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int m, n;
	queue<Vector2> q;	//bfs queue
	cin >> m >> n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> storage[i][j];
			if (storage[i][j] == 1)
			{
				q.push(make_pair(i, j));
				++currentCounter;
			}
			else if (storage[i][j] == 0)
				++zero;
		}
	}

	while (!q.empty())
	{
		Vector2 pos = q.front();
		q.pop();
		--currentCounter;

		if (pos.first < n - 1 && storage[pos.first + 1][pos.second] == 0)	//unvisited && boundary check
		{
			--zero;
			++nextCounter;
			storage[pos.first + 1][pos.second] = 1;
			q.push(make_pair(pos.first + 1, pos.second));
		}
		if (pos.first && storage[pos.first - 1][pos.second] == 0)
		{
			--zero;
			++nextCounter;
			storage[pos.first - 1][pos.second] = 1;
			q.push(make_pair(pos.first - 1, pos.second));
		}
		if (pos.second < m - 1 && storage[pos.first][pos.second + 1] == 0)
		{
			--zero;
			++nextCounter;
			storage[pos.first][pos.second + 1] = 1;
			q.push(make_pair(pos.first, pos.second + 1));
		}
		if (pos.second && storage[pos.first][pos.second - 1] == 0)
		{
			--zero;
			++nextCounter;
			storage[pos.first][pos.second - 1] = 1;
			q.push(make_pair(pos.first, pos.second - 1));
		}

		if (currentCounter == 0 && nextCounter)
		{
			currentCounter = nextCounter;
			nextCounter = 0;
			++day;
		}
	}

	cout << (zero ? -1 : day);
	return 0;
}