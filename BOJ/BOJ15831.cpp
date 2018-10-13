#include<iostream>

using namespace std;

char* road;

int Track(int, int, int, int);

int main(void)
{
	int n, b, w;
	/*
	n : amount of stones
	b : less or equal than b
	w : more or equal than w
	*/
	cin >> n >> b >> w;
	road = new char[n];
	for (int i = 0; i < n; i++)
		cin >> road[i];

	int max = 0;
	for (int i = 0; i < n; i++)
	{
		int tmp = Track(i, n, b, w);
		if (tmp > max)
		{
			max = tmp;
		}
	}
	cout << max;

	delete[] road;
	return 0;
}

int Track(int index, int size, int b, int w)
{
	int res = 0, bcnt = 0, wcnt = 0;
	bool flag = false;
	for (int i = index; i < size; ++i, ++res)
	{
		if (road[i] == 'B' && bcnt < b)
		{
			++bcnt;
		}	
		else if (road[i] == 'W')
		{
			++wcnt;
		}
		else
		{
			break;
		}
	}

	if (bcnt > b || wcnt < w)
	{
		return 0;
	}
	return res;
}