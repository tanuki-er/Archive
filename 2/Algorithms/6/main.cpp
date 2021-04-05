#include <fstream>
#include <vector>

using namespace std;

struct array
{
	int K, L, R;
};

void passage(vector<array> &tree, vector<int> &key, int base)
{
	if (base != -1)
	{
		passage(tree, key, tree[base].L);

		key.push_back(tree[base].K);

		passage(tree, key, tree[base].R);
	}
}

bool ordered(vector<int> &key)
{
	for(int i = 1; i < key.size(); i++)
    {
        if (key[i - 1] >= key[i])
        {
            return false;
        }
    }

	return true;
}

bool correct(vector<array> &tree, int base)
{
	vector<int> key;

	passage(tree, key, 0);

	return ordered(key);
}

int main()
{
	ifstream fin("check.in");
	ofstream fout("check.out");
    int n;

	fin >> n;

	vector<array> tree(n);

	for(int i = 0; i < n; i++)
	{
		fin >> tree[i].K >> tree[i].L >> tree[i].R;

		tree[i].L--;
		tree[i].R--;
	}

	if ((n == 0) ||  (correct(tree, 0)))
    {
        fout << "YES";
    }
	else
    {
        fout << "NO";
    }

	return 0;
}
