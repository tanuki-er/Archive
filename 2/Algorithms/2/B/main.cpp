#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct person
{
	string country, man;
	int where;
};

void quick_sort(vector<person> &copy, int left, int right)
{
	int i, j, k;
	string m;

	k = copy[(left + right) / 2].where;
	i = left;
	j = right;
	m = copy[(left + right) / 2].country;

	while (i <= j)
	{
		while ((copy[i].country < m) || ((copy[i].country == m) && (copy[i].where < k)))
        {
            i++;
        }
		while ((copy[j].country > m) || ((copy[j].country == m) && (copy[j].where > k)))
        {
            j--;
        }
		if (i <= j)
        {
			swap(copy[i++], copy[j--]);
        }
	}

	if (left < j)
    {
        quick_sort(copy, left, j);
    }
	if (i < right)
    {
        quick_sort(copy, i, right);
    }
}

int main()
{
	ifstream input("race.in", ios::in);
	ofstream output("race.out", ios::out);
	int n;

	input >> n;

	vector<person> copy;
	copy.resize(n);

	for(int i = 0; i < n; i++)
	{
		input >> copy[i].country >> copy[i].man;
		copy[i].where = i + 1;
	}

	quick_sort(copy, 0, (n - 1));

	for(int i = 0; i < n; i++)
	{
		if (copy[i].country != copy[i - 1].country)
		{
			output << "=== " << copy[i].country << " ===" << endl;
		}
		output << copy[i].man << endl;
	}

	return 0;
}
