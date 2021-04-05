#include <fstream>
#include <vector>

using namespace std;

enum Color {white, gray, black};

bool flag = false;

struct top
{
	vector<int> near;
	Color color = white;
};

void DFS_Visit(vector<top> &t, int num, vector<int> &res)
{
	if (t[num].color == black)
    {
        return;
    }

	if (t[num].color == gray)
    {
        flag = true;
    }

	if (flag)
    {
        return;
    }

	t[num].color = gray;

	for(int i = 0; i < t[num].near.size(); i++)
	{
		DFS_Visit(t, t[num].near[i], res);
	}

	t[num].color = black;

	res.push_back(num);
}

void DFS(vector<top> &t, vector<int> &res)
{
	for(int i = 0; i < t.size(); i++)
    {
        if (t[i].color == white)
        {
            DFS_Visit(t, i, res);
        }
    }
}

int main()
{
	ifstream input("topsort.in");
	ofstream output("topsort.out");
	int n, m, num1, num2;

	input >> n >> m;

	vector<top> t(n);
	vector<int> res;

	for(int i = 0; i < m; i++)
	{
		input >> num1 >> num2;

		t[num1 - 1].near.push_back(num2 - 1);
	}

	DFS(t, res);

	if (flag)
    {
        output << "-1";
    }
	else
    {
        for(int i = res.size() - 1; i >= 0; i--)
        {
            output << res[i] + 1 << " ";
        }
    }

	return 0;
}
