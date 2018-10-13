#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	long long n;
	cin >> n;
	long long* points = new long long[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> points[i];
	}
	sort(points, points + n);
	long long min = points[1] - points[0], index = 0;
	for (int i = 1; i < n - 1; ++i)
	{
		long long diff = points[i + 1] - points[i];
		if (diff < min)
		{
			min = diff;
			index = i;
		}
	}
	cout << points[index] << ' ' << points[index + 1];
	return 0;
}
