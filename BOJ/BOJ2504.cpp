#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main(void)
{
	stack<char> stack;
	int answer = 0;
	int mul = 1;
	string input;
	bool open;
	cin >> input;

	for (int i = 0; i < input.length(); ++i)
	{
		char bracket = input[i];
		if (bracket == '(')
		{
			open = true;
			mul *= 2;
			stack.push(bracket);
		}
		else if (bracket == '[')
		{
			open = true;
			mul *= 3;
			stack.push(bracket);
		}

		if (!stack.empty())
			if (bracket == ')')
			{
				if (stack.top() == '(')
				{
					if (open)
						answer += mul;
					stack.pop();
					open = false;
				}
				mul /= 2;
			}
			else if (bracket == ']')
			{
				if (stack.top() == '[')
				{
					if (open)
						answer += mul;
					stack.pop();
					open = false;
				}
				mul /= 3;
			}
	}

	if (!stack.empty())
		answer = 0;

	cout << answer;
	return 0;
}