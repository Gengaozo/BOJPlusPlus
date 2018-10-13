#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int depth = 0;

bool Check(int value)
{
	bool flag = true;
	string str = to_string(value);
	for (int i = 0; i < str.length() / 2; i++)
	{
		if (str[i] != str[str.length() - 1 - i])
		{
			flag = false;
		}
	}
	return flag;
}

int Palindrome(int value)
{
	if (++depth > 3)
	{
		return -1;
	}

	//n + R(n)
	int ans;
	string str;
	str = to_string(value);
	ans = stoi(str);
	reverse(str.begin(), str.end());
	ans += stoi(str);

	if (ans >= 10000)
	{
		return -1;
	}
	if (Check(ans))
	{
		return ans;
	}

	return Palindrome(ans);
}

int main() {
	int value;
	cin >> value;
	cout << Palindrome(value);
	return 0;
}
