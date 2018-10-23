#include<iostream>
#include<deque>

using namespace std;

void RotateLeft(deque<int>& deq)
{
	int push = deq.front();
	deq.pop_front();
	deq.push_back(push);
}

void RotateRight(deque<int>& deq)
{
	int push = deq.back();
	deq.pop_back();
	deq.push_front(push);
}

int main(void)
{
	deque<int> deq;
	int size, popAmount, count = 0;
	cin >> size >> popAmount;
	
	for (int i = 1; i <= size; ++i)
	{
		deq.push_back(i);
	}

	for (int i = 0; i < popAmount; ++i)
	{
		int wanted;
		cin >> wanted;

		if (deq.front() == wanted)
			deq.pop_front();
		else
		{
			int pos;
			for (int j = 0; j < deq.size(); ++j)
			{
				if (deq.at(j) == wanted)
				{
					pos = j;
					break;
				}
			}

			if (pos <= deq.size() / 2)
			{
				while (deq.front() != wanted)
				{
					++count;
					RotateLeft(deq);
				}
				deq.pop_front();
			}
			else
			{
				while (deq.front() != wanted)
				{
					++count;
					RotateRight(deq);
				}
				deq.pop_front();
			}
		}
	}

	cout << count;
	return 0;
}
