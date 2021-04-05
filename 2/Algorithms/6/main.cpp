#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
struct array
{
	int K, L, R;
};
int searching(vector<array> &tree, int base)
{
	if (base == -1)
    {
        return 0;
    }
	else
    {
        return max(searching(tree, tree[base].L), searching(tree, tree[base].R)) + 1;
    }
}

int main()
{
	ifstream input("heightin.txt");
	ofstream output("heightout.txt");
    int N;
	input >> N;
	vector<array> tree(N);
	for(int i = 0; i < N; i++)
	{
		input >> tree[i].K >> tree[i].L >> tree[i].R;
		tree[i].L--;
		tree[i].R--;
	}
	if (N == 0)
    {
        output << 0;
    }
	else
    {
        output << searching(tree, 0);
    }
	return 0;
}