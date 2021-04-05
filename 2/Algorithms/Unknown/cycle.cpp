#include <fstream>
#include <vector>

using namespace std;

enum Color {white, gray, black};

bool flag = false;
vector<int> elems;

struct top
{
	vector<int> near;
	int parent = -1;

	Color color = white;
};

void DFS_Visit(vector<top> &t, int U)
{
	if (flag)
	{
	    return;
	}

	if (t[U].color == black)
    {
        return;
    }

	if (t[U].color == gray)
    {
        flag = true;
        int CurV = U;

        do
        {
            elems.push_back(CurV);

            CurV = t[CurV].parent;
        } while (CurV != U);
    }

	t[U].color = gray;

	for(int i = 0; i < t[U].near.size(); i++)
	{
		t[t[U].near[i]].parent = U;

		DFS_Visit(t, t[U].near[i]);
	}

	t[U].color = black;
}

void DFS(vector<top> &t)
{
	for(int i = 0; i < t.size(); i++)
    {
        if (t[i].color == white)
        {
            DFS_Visit(t, i);
        }
    }
}

int main()
{
	ifstream input("cycle.in");
	ofstream output("cycle.out");
	int n, m, num1, num2;

	input >> n >> m;

	vector<top> t(n);

	for(int i = 0; i < m; i++)
	{
		input >> num1 >> num2;

		t[num1 - 1].near.push_back(num2 - 1);
	}

	DFS(t);

	if (flag)
	{
		output << "YES\n";

		for(int i = elems.size() - 1; i >= 0; i--)
        {
            output << elems[i] + 1 << " ";
        }
	}
	else
    {
        output << "NO";
    }

	return 0;
}
