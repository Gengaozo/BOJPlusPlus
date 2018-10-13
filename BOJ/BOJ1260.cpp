#include<iostream>
#include<queue>

using namespace std;

int n, m, v;
bool** GraphMatrix;
bool* isVisited;

void init()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			GraphMatrix[i][j] = false;
		}
		isVisited[i] = false;
	}

	for (int i = 0; i < m; ++i)
	{
		int link1, link2;
		cin >> link1 >> link2;
		GraphMatrix[link1][link2] = true;
		GraphMatrix[link2][link1] = true;
	}
}

void Dfs(int location)
{
	cout << location << ' ';
	isVisited[location] = true;
	for (int i = 1; i <= n; ++i)
	{
		if (GraphMatrix[location][i] && !isVisited[i])
		{
			Dfs(i);
		}
	}
}

void Bfs(int location)
{
	int now;
	queue<int> queue;
	isVisited[location] = true;
	queue.push(location);

	while (!queue.empty())
	{
		now = queue.front();
		cout << now << ' ';
		queue.pop();
		for (int i = 1; i <= n; ++i)
		{
			if (GraphMatrix[now][i] && !isVisited[i])
			{
				isVisited[i] = true;
				queue.push(i);
			}
		}
	}
}

int main(void)
{		
	//n : amount of vertex, m : amount of edge, v : search start location
	cin >> n >> m >> v;
	GraphMatrix = new bool*[n+1];
	isVisited = new bool[n+1];
	for (int i = 1; i <= n; ++i)
	{
		GraphMatrix[i] = new bool[n+1];
	}

	init();
	Dfs(v);
	cout << '\n';
	for (int i = 1; i <= n; ++i)
	{
		isVisited[i] = false;
	}
	Bfs(v);
	return 0;
}