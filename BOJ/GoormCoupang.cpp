#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

int main() {
	int n;
	string line;
	getline(cin, line);
	line.erase(remove(line.begin(), line.end(), '['), line.end());
	cout << line << '\n';

	int iter = 0, next = 0;
	string tmp;
	for (; line[iter] != ']'; ++iter);
	for (int i = 0; i < line.substr(0, iter).length(); ++i)
	{

	}


	system("pause");
	return 0;
}