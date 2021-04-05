#include <fstream>
#include <vector>

using namespace std;

enum Color {white, gray, black};

struct top
{
	vector<int> near;

	Color color = white;
	int number = 0;
};

void DFS_Visit(vector<top> &t, int k, int component)
{
	t[k].color = gray;

	for(int i = 0; i < t[k].near.size(); i++)
	{
		if (t[t[k].near[i]].color == white)
        {
            DFS_Visit(t, t[k].near[i], component);
        }
	}

	t[k].color = black;
	t[k].number = component;
}

int DFS(vector<top> &t)
{
	int res = 0;

	for(int i = 0; i < t.size(); i++)
    {
        if (t[i].color == white)
		{
			res++;

			DFS_Visit(t, i, res);
		}
    }

	return res;
}

int main()
{
	ifstream input("components.in");
	ofstream output("components.out");
	int n, m, num1, num2;

	input >> n >> m;

	vector<top> t(n);

	for(int i = 0; i < m; i++)
	{
		input >> num1 >> num2;

		t[num1 - 1].near.push_back(num2 - 1);
		t[num2 - 1].near.push_back(num1 - 1);
	}

	output << DFS(t) << "\n";

	for(int i = 0; i < n; i++)
    {
        output << t[i].number << " ";
    }

	return 0;
}
