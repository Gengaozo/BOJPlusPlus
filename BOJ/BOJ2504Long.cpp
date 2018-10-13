#include<iostream>
#include<stack>
#include<string>

using namespace std;

bool Update(stack<string>& stack, string push, const char pair);
void AddAdjInts(stack<string>& stack);

//void printStack(stack<string> stack)
//{
//	while (!stack.empty())
//	{
//		cout << stack.top();
//		stack.pop();
//	}
//	cout << '\n';
//}

int main(void)
{
	ios_base::sync_with_stdio(false);
	stack<string> stack;
	string input;
	getline(cin, input);

	if ((input.length() & 1) == 1)
	{
		cout << "0";
		return 0;
	}

	for (size_t i = 0; i < input.length(); ++i)
	{
		string push = input.substr(i, 1);

		if (push.compare("(") == 0)
		{
			stack.push("(");
		}
		else if (push.compare("[") == 0)
		{
			stack.push("[");
		}
		else if (push.compare(")") == 0)
		{
			if (stack.empty())
			{
				cout << "0";
				return 0;
			}
			if (stack.top().compare("(") == 0)
			{
				if (stack.size() == 1)
				{
					stack.pop();
					stack.push("2");
				}
				else Update(stack, "2", 'x');
			}
			else
			{
				if (!Update(stack, stack.top(), '('))
				{
					cout << "0";
					return 0;
				}
			}
		}
		else if (push.compare("]") == 0)
		{
			if (stack.empty())
			{
				cout << "0";
				return 0;
			}
			if (stack.top().compare("[") == 0)
			{
				if (stack.size() == 1)
				{
					stack.pop();
					stack.push("3");
				}
				else Update(stack, "3", 'x');
			}
			else
			{
				if (!Update(stack, stack.top(), '['))
				{
					cout << "0";
					return 0;
				}
			}
		}
		AddAdjInts(stack);
		//printStack(stack);
	}

	cout << stack.top();
	return 0;
}

bool Update(stack<string>& stack, string push, const char pair)	
{
	if (stack.empty())
		return false;

	if (pair != 'x' && (stack.top()[0] == '(' || stack.top()[0] == '['))
	{
		if (pair != stack.top()[0])
		{
			return false;
		}
	}
	stack.pop();
	if (stack.empty()) return false;
	string prev = stack.top();

	if (pair != 'x' && (prev[0] == '(' || prev[0] == '['))
	{
		if (pair != prev[0])
		{
			return false;
		}
		stack.pop();
		if (prev[0] == '(')
		{
			stack.push(to_string(2 * stoi(push)));
		}
		else
		{
			stack.push(to_string(3 * stoi(push)));
		}
		return true;
	}
	if (prev[0] != '(' && prev[0] != '[')
	{
		stack.pop();
		stack.push(to_string(stoi(prev) + stoi(push)));
	}
	else
	{
		stack.push(push);
	}
	//cout << "prev : " << prev << " push : " << push << " size : " << stack.size() << '\n';
	return true;
}

void AddAdjInts(stack<string>& stack)
{
	if (stack.size() < 2) return;

	string a = stack.top();
	stack.pop();
	string b = stack.top();
	stack.pop();
	if (a[0] == '(' || a[0] == '[' || a[0] == ')' || a[0] == ']' || b[0] == '(' || b[0] == '[' || b[0] == ')' || b[0] == ']')
	{
		stack.push(b);
		stack.push(a);
		return;
	}
	stack.push(to_string(stoi(a) + stoi(b)));
}