#include <fstream>
#include <vector>

using namespace std;

int main()
{
	ifstream input("antiqs.in");
	ofstream output("antiqs.out");
	int n;

	input >> n;

	vector<int> array;

	array.resize(n);

	for (int i = 0; i < n; i++)
	{
		array[i] = i + 1;
	}
	for (int i = 0; i < n; i++)
	{
		swap(array[i], array[i / 2]);
	}
	for (int i = 0; i < n; i++)
	{
		output << array[i] << " ";
	}

	return 0;
}
