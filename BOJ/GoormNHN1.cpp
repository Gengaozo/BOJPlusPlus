#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

bool AscendingCompare(const int& a, const int& b)
{
	int A = a, B = b;
	if (A / 10 % 10 == 0)
	{
		A += A * 10;
	}
	if (B / 10 % 10 == 0)
	{
		B += B * 10;
	}

	return A > B;
}

bool DescendingCompare(const int& a, const int& b)
{
	int A = a, B = b;
	if (A / 10 % 10 == 0)
	{
		A += A * 10;
	}
	if (B / 10 % 10 == 0)
	{
		B += B * 10;
	}

	return A < B;
}

int main(void)
{
	int amount;
	cin >> amount;
	int* arr = new int[amount];
	long long ans = 0;

	for (int i = 0; i < amount; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + amount, AscendingCompare);
	string tmp;
	for (int i = 0; i < amount; i++)
	{
		tmp.append(to_string(arr[i]));
	}
	ans += stoll(tmp);
	sort(arr, arr + amount, DescendingCompare);
	tmp.clear();
	for (int i = 0; i < amount; i++)
	{
		tmp.append(to_string(arr[i]));
	}
	ans += stoll(tmp);
	cout << ans;
	return 0;
}