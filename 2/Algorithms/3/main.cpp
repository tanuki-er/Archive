#include <fstream>
#include <vector>
#include <string>

using namespace std;

void sorting_by_counting(vector<string> &array, int stage)
{
    int scope;

	scope = 'z' - 'A' + 1;

	vector<int> copy(scope);

	vector<string> ar(array.size());

	for(int i = 0; i < scope; i++)
    {
        copy[i] = 0;
    }

	for(int i = 0; i < array.size(); i++)
    {
        copy[array[i][stage] - 'A']++;
    }
	for(int i = 1; i < scope; i++)
    {
        copy[i] = copy[i] + copy[i - 1];
    }
	for(int i = (array.size() - 1); i >= 0; i--)
    {
        ar[--copy[array[i][stage] - 'A']] = array[i];
    }
	array = ar;
}

void radix_sort(vector<string> &array, int m, int k)
{
	for(int i = (m - 1); i >= (m - k); i--)
    {
        sorting_by_counting(array, i);
    }
}

int main()
{
	ifstream input("radixsort.in");
	ofstream output("radixsort.out");

	int n, m, k;

	input >> n >> m >> k;

	vector<string> array(n);

	for(int i = 0; i < n; i++)
    {
        input >> array[i];
    }

	radix_sort(array, m, k);

	for(int i = 0; i < n; i++)
    {
        output << array[i] << endl;
    }

	return 0;
}
