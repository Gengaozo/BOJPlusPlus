#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<string>
#include<deque>
#include<algorithm>

using namespace std;

int main(void)
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		deque<int> deq;
		char buffer[100001];
		int size;
		bool isReversed = false;

		scanf("%s", buffer);
		string func = buffer;
		scanf(" %d\n[", &size);	//개행, 괄호 무시
		
		for (int i = 0; i < size; ++i)
		{
			int push;
			scanf("%d,", &push);
			deq.push_back(push);
		}
		getchar();	//괄호
		getchar();	//개행 문자

		bool isError = false;
		for (int i = 0; i < func.length(); ++i)
		{
			if (func[i] == 'R') isReversed = !isReversed;
			else
			{
				if (deq.empty())
				{
					isError = true;
					break;
				}
				if (isReversed) deq.pop_back();
				else deq.pop_front();
			}
		}

		if (isError) puts("error");
		else
		{
			if(isReversed) reverse(deq.begin(), deq.end());
			printf("[");

			if (deq.size() > 0)
			{
				while (deq.size() > 1)
				{
					printf("%d,", deq.front());
					deq.pop_front();
				}
				printf("%d", deq.front());
			}

			puts("]");
		}
	}

	return 0;
}