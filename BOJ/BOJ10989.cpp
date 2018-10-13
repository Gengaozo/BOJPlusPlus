#include<iostream>

using namespace std;

int arr[10001];

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < 10001; ++i)
	{
		arr[i] = 0;
	}

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int tmp;
		cin >> tmp;
		++arr[tmp];
	}

	for (int i = 0; i < 10001; ++i)
	{
		for (int j = 0; j < arr[i]; ++j)
		{
			cout << i << '\n';
		}
	}

	return 0;
}