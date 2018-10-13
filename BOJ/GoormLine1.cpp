
#include <iostream>
#include <sstream>
#include <string>
#include <stack>

using namespace std;

//Implement this class
//Please use stack only
class Queue {
public:
	bool isPoped = false;
	stack<int> stack1;
	stack<int> stack2;
	/*
	* Description:Enqueue v in this queue.
	* Time complexity:
	* Space complexity:
	*/
	void enqueue(int v) {
		stack1.push(v);
	}

	/*
	* Description:Dequeue value of the rear of this queue.
	* Time complexity:
	* Space complexity:
	*/
	int dequeue() {
		int retVal;
		if (stack2.empty())
		{
			while (!stack1.empty())
			{
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		retVal = stack2.top();
		stack2.pop();

		return retVal;
	}
};

int main(int argc, const char *argv[]) {
	Queue queue;
	string line;
	getline(cin, line);
	int count = stoi(line);
	for (int i = 0; i < count; ++i) {
		getline(cin, line);
		stringstream ss(line);
		string token;
		getline(ss, token, ' ');
		if (token == "ENQUEUE") {
			getline(ss, token, ' ');
			queue.enqueue(stoi(token));
		}
		else if (token == "DEQUEUE") {
			cout << queue.dequeue() << endl;
		}
	}

	return 0;
}
