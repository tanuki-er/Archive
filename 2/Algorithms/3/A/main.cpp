#include <fstream>
#include <vector>

using namespace std;
void bin_search(vector<int> &array, int key, int &left, int &right)//
{
	int i, j;
    i = 0;
    j = array.size();
	while (i < j)
	{
		int m;
		m = (i + j) / 2;
		if (array[m] < key)
        {
            i = m + 1;
        }
		else
        {
            j = m;
        }
	}
	left = i + 1;
	i = 0;
	j = array.size();
	while (i < j)
	{
		int m;
		m = (i + j) / 2;
		if (array[m] <= key)
        {
            i = m + 1;
        }
		else
        {
            j = m;
        }
	}
	right = i;
	if (left > right)
    {
        left = -1;
        right = -1;
    }
}
int main()
{
	ifstream input("binsearchin.txt");
	ofstream output("binsearchout.txt");
    int n, m;
	input >> n;
	vector<int> array(n);
	for(int i = 0; i < n; i++)
    {
        input >> array[i];
    }
	input >> m;
	for(int i = 0; i < m; i++)
	{
		int key, left, right;
		input >> key;
		bin_search(array, key, left, right);
		output << left << " " << right << endl;
	}
	return 0;
}
