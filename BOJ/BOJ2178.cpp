#include<cstdio>

using namespace std;

char maze[100][100];
char buf[1 << 14];
int idx = 0;

char ReadChar()
{
	if (idx == 0)
	{
		fread(buf, 1, 1 << 14, stdin);
	}

	return buf[idx++];
}

char GetChar()
{
	return 0;
}

int GetInt()
{

}

int main(void)
{
	int n, m;

	n = GetChar();
	m = GetInt();

	printf("%d\n", m);
}