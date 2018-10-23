#include<iostream>
#include<string>

using namespace std;

#define error return -1

struct Node
{
	int _value = 0;
	Node* _prev = nullptr;
	Node* _next = nullptr;
	//ctor
	Node(int value) { _value = value; }
};

struct Deque
{
	//fields
	Node* _front = nullptr;
	Node* _back = nullptr;
	size_t _size = 0;
	bool isEmpty = true;
	//methods
	void PushFront(int value)
	{
		if (isEmpty)
		{
			_front = _back = new Node(value);
			isEmpty = false;
		}
		else
		{
			_front->_prev = new Node(value);
			_front->_prev->_next = _front;
			_front = _front->_prev;
		}
		++_size;
	}
	void PushBack(int value)
	{
		if (isEmpty)
		{
			_front = _back = new Node(value);
			isEmpty = false;
		}
		else
		{
			_back->_next = new Node(value);
			_back->_next->_prev = _back;
			_back = _back->_next;
		}
		++_size;
	}
	int PopFront()
	{
		if (isEmpty) error;
		int ret = _front->_value;
		if (_size == 1)
		{
			delete _front;
			_front = _back = nullptr;
			isEmpty = true;
		}
		else
		{
			_front = _front->_next;
			delete _front->_prev;
		}
		--_size;
		return ret;
	}
	int PopBack()
	{
		if (isEmpty) error;
		int ret = _back->_value;
		if (_size == 1)
		{
			delete _back;
			_front = _back = nullptr;
			isEmpty = true;
		}
		else
		{
			_back = _back->_prev;
			delete _back->_next;
		}
		--_size;
		return ret;
	}
	int Front()
	{
		if (!_front) error;
		return _front->_value;
	}
	int Back()
	{
		if (!_back) error;
		return _back->_value;
	}
	bool Empty()
	{
		return isEmpty;
	}
	size_t Size()
	{
		return _size;
	}
	~Deque()
	{
		for (size_t i = 0; i < _size; ++i)
		{
			PopFront();
		}
	}
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int instCount;
	cin >> instCount;
	string command;
	Deque deque;
	for (int i = 0; i < instCount; ++i)
	{
		cin >> command;
		if (command.compare("push_front") == 0)
		{
			int value;
			cin >> value;
			deque.PushFront(value);
		}
		else if (command.compare("push_back") == 0)
		{
			int value;
			cin >> value;
			deque.PushBack(value);
		}
		else if (command.compare("pop_front") == 0)
		{
			cout << deque.PopFront() << '\n';
		}
		else if (command.compare("pop_back") == 0)
		{
			cout << deque.PopBack() << '\n';
		}
		else if (command.compare("size") == 0)
		{
			cout << deque.Size() << '\n';
		}
		else if (command.compare("empty") == 0)
		{
			cout << deque.Empty() << '\n';
		}
		else if (command.compare("front") == 0)
		{
			cout << deque.Front() << '\n';
		}
		else if (command.compare("back") == 0)
		{
			cout << deque.Back() << '\n';
		}
	}

	return 0;
}