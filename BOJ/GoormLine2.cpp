#include <iostream>
#include <sstream>
#include <string>
// include <cstdio>
// cin,cout 대신 scanf,printf를 사용하려면 iostream 대신 cstdio 를 사용하세요 .

using namespace std;

class Frame
{
public:
	int width;
	int height;
	int alpha;
	int duration;
	void PrintInfo()
	{
		cout << width << 'x' << height << ", " << duration << ", " << alpha << '\n';
	}
};

int main() {
	int width, height;
	string line;
	getline(cin, line);
	line.erase(0, 13);	//Canvas size
	int offset = line.find(" x ");
	width = stoul(line.substr(0, offset), nullptr);
	cout << width << '\n';		//horizonal size
	height = stoul(line.erase(0, offset + 3), nullptr);
	cout << height << '\n';	//vertical size
	getline(cin, line);
	line.erase(0, 18);
	offset = stoul(line, nullptr, 16);	//convert string to hex
	cout << offset << '\n';
	getline(cin, line);
	line.erase(0, 18);
	offset = stoul(line, nullptr);	//convert string to dec, amount of frame
	getline(cin, line);
	line.erase(0, 5);	//delete No. 

	stringstream ss(line);
	string tmp;

	int indexes[4], i = 1;
	while (ss >> tmp)
	{
		if (tmp.compare("width") == 0)
		{
			indexes[0] = i++;
		}
		else if (tmp.compare("height") == 0)
		{
			indexes[1] = i++;
		}
		else if (tmp.compare("duration") == 0)
		{
			indexes[2] = i++;
		}
		else
		{
			indexes[3] = i++;
		}
	}
	cout << offset << '\n';
	Frame* frames = new Frame[offset];
	for (int i = 0; i < offset; ++i)
	{
		getline(cin, line);
		stringstream ss(line);
		ss >> tmp;
		int index = stoi(tmp.erase(tmp.length() - 1, 1), nullptr) - 1;
		
		for (int j = 0; ss >> tmp; ++j)
		{
			switch (indexes[j])
			{
			case 1:
				frames[index].width = stoi(tmp, nullptr);
				break;
			case 2:
				frames[index].height = stoi(tmp, nullptr);
				break;
			case 3:
				frames[index].duration = stoi(tmp, nullptr);
				break;
			case 4:
				frames[index].alpha = (tmp.compare("yes") == 0) ? 1 : 0;
			}
		}
	}

	for (int i = 0; i < offset; i++)
	{
		frames[i].PrintInfo();
	}

	delete[] frames;
	return 0;
}