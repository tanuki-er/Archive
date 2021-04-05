#include <fstream>
#include <vector>
#include <queue>

using namespace std;

enum Color {white, gray, black};

struct top
{
	vector<int> near;
	int distance = 0;

	Color color = white;
};

void BFS(vector<top> &t, int start)
{
	t[start].color = gray;
	queue<int> q;

	q.push(start);

	while (!q.empty())
	{
		int U = q.front();
		q.pop();

		for(int i = 0; i < t[U].near.size(); i++)
        {
            if (t[t[U].near[i]].color == white)
			{
				t[t[U].near[i]].color = gray;
				t[t[U].near[i]].distance = t[U].distance + 1;

				q.push(t[U].near[i]);
			}
        }

		t[U].color = black;
	}
}

int main()
{
	ifstream input("pathbge1.in");
	ofstream output("pathbge1.out");
	int n, m, num1, num2;

	input >> n >> m;

	vector<top> t(n);

	for(int i = 0; i < m; i++)
	{
		input >> num1 >> num2;

		t[num1 - 1].near.push_back(num2 - 1);
		t[num2 - 1].near.push_back(num1 - 1);
	}

	BFS(t, 0);

	for(int i = 0; i < n; i++)
    {
        output << t[i].distance << " ";
    }

	return 0;
}
