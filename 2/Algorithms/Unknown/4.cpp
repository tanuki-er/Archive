#include <fstream>
#include <vector>
#include <queue>
#include <string>
#include <iostream>

using namespace std;

enum Color {white, gray, black};

struct top
{
	vector<int> near;
	int parent = -1;
	int distance = 0;
	Color color = white;
};

void BFS(vector<top> &arr, int start)
{
	arr[start].color = gray;
	queue<int> q;

	q.push(start);

	while (!q.empty())
	{
		int num;

		num = q.front();
		q.pop();

		for(int i = 0; i < arr[num].near.size(); i++)
        {
            if (arr[arr[num].near[i]].color == white)
			{
				arr[arr[num].near[i]].color = gray;
				arr[arr[num].near[i]].distance = arr[num].distance + 1;
				arr[arr[num].near[i]].parent = num;

				q.push(arr[num].near[i]);
			}
        }

		arr[num].color = black;
	}
}

int func(int i, int j, int m)
{
	return ((i - 1) * m + (j - 1));
}

string recover(vector<top> &arr, int num1, int num2)
{
	string res;
	int Cur = num2;

	while (Cur != num1)
	{
		if (arr[Cur].parent - Cur == -1)
        {
            res = "R" + res;
        }

		if (arr[Cur].parent - Cur == 1)
        {
            res = "L" + res;
        }

		if (arr[Cur].parent - Cur < -1)
        {
            res = "D" + res;
        }

		if (arr[Cur].parent - Cur > 1)
        {
            res = "U" + res;
        }

		Cur = arr[Cur].parent;
	}

	return res;
}

int main()
{
	ifstream input("input.txt");
	ofstream output("output.txt");
	int n, m, num1, num2;

	input >> n >> m;

	vector<top> arr;
	char mas[102][102];

	for(int i = 0; i <= (n + 1); i++)
    {
        mas[i][0] = mas[i][m + 1] = '#';
    }

	for(int i = 0; i <= m + 1; i++)
    {
        mas[0][i] = mas[n + 1][i] = '#';
    }

	for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            input >> mas[i][j];
        }
    }

	for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
		{
			top Ver;

			if (mas[i][j] == '#')
            {
                Ver.color = black;
            }

			if (mas[i][j] == 'S')
            {
                num1 = func(i, j, m);
            }

			if (mas[i][j] == 'T')
            {
                num2 = func(i, j, m);
            }

			if (mas[i + 1][j] != '#')
			{
				Ver.near.push_back(func(i + 1, j, m));
			}

			if (mas[i - 1][j] != '#')
			{
				Ver.near.push_back(func(i - 1, j, m));
			}

			if (mas[i][j + 1] != '#')
			{
				Ver.near.push_back(func(i, j + 1, m));
			}

			if (mas[i][j - 1] != '#')
			{
				Ver.near.push_back(func(i, j - 1, m));
			}

			cout << "\n";

			arr.push_back(Ver);
		}
    }

	BFS(arr, num1);

	if (arr[num2].distance == 0)
    {
        output << -1;
    }
	else
    {
        output << arr[num2].distance << "\n" << recover(arr, num1, num2);
    }

	return 0;
}
