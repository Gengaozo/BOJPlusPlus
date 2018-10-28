#include<iostream>

using namespace std;

struct Point
{
	int x, y, z;
};

int box[100][100][100];
Point q[1000000];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int	m, n, h, front = 0, back = 0;
	int zero = 0, currentCount = 0, nextCount = 0, day = 0;

	cin >> m >> n >> h;

	for (int i = 0; i < h; ++i)
		for (int j = 0; j < n; ++j)
			for (int k = 0; k < m; ++k)
			{
				cin >> box[i][j][k];
				if (box[i][j][k] == 1)
				{
					++currentCount;
					q[back++] = { i, j, k };
				}
				else if (box[i][j][k] == 0) ++zero;
			}

	while (front < back)
	{
		--currentCount;

		int x = q[front].x;
		int y = q[front].y;
		int z = q[front].z;
		++front;

		if (x < h - 1 && box[x + 1][y][z] == 0)
		{
			--zero;
			++nextCount;
			q[back++] = { x + 1, y, z };
			box[x + 1][y][z] = 1;
		}
		if (x && box[x - 1][y][z] == 0)
		{
			--zero;
			++nextCount;
			q[back++] = { x - 1, y, z };
			box[x - 1][y][z] = 1;
		}
		if (y < n - 1 && box[x][y + 1][z] == 0)
		{
			--zero;
			++nextCount;
			q[back++] = { x, y + 1, z };
			box[x][y + 1][z] = 1;
		}
		if (y && box[x][y - 1][z] == 0)
		{
			--zero;
			++nextCount;
			q[back++] = { x, y - 1, z };
			box[x][y - 1][z] = 1;
		}
		if (z < m - 1 && box[x][y][z + 1] == 0)
		{
			--zero;
			++nextCount;
			q[back++] = { x, y, z + 1 };
			box[x][y][z + 1] = 1;
		}
		if (z && box[x][y][z - 1] == 0)
		{
			--zero;
			++nextCount;
			q[back++] = { x, y, z - 1 };
			box[x][y][z - 1] = 1;
		}

		if (currentCount == 0 && nextCount)
		{
			currentCount = nextCount;
			nextCount = 0;
			++day;
		}
	}

	cout << (zero ? -1 : day);
	return 0;
}