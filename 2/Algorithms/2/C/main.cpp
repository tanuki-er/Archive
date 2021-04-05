#include <fstream>
#include <vector>

using namespace std;

long long amount;

void merge_sort_2(vector<int> &array, int left, int middle, int right)
{
	vector<int> copy;
	copy.resize(right - left);
	int i, j;

	i = 0;
	j = 0;

	while(((left + i) < middle) && ((middle + j) < right))
    {
        if (array[left + i] <= array[middle + j])
		{
			copy[i + j] = array[left + i];
			i++;
		}
		else
		{
			copy[i + j] = array[middle + j];
			amount += middle - (left + i);
			j++;
		}
    }

	while((left + i) < middle)
	{
		copy[i + j] = array[left + i];
		i++;
	}
	while((middle + j) < right)
	{
		copy[i + j] = array[middle + j];
		j++;
	}

	for(int k = 0; k < (i + j); k++)
	{
		array[left + k] = copy[k];
	}
}

void merge_sort_1(vector<int> &array, int left, int right)
{
	if ((left + 1) >= right)
    {
        return;
    }

	int middle;

	middle = (left + right) / 2;

	merge_sort_1(array, left, middle);
	merge_sort_1(array, middle, right);

	merge_sort_2(array, left, middle, right);
}

int main()
{
	ifstream input("inversions.in");
	ofstream output("inversions.out");
	int n;

	input >> n;

	vector<int> array;
	array.resize(n);

	for(int i = 0; i < n; i++)
    {
        input >> array[i];
    }

	merge_sort_1(array, 0, n);

	output << amount;

	return 0;
}
