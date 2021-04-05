#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void quick_sort(vector<int> &ar, int left, int right, int k)
{
	int i, j, copy;

	i = left;
	j = right;
	copy = ar[(left + right) / 2];

	while (i <= j)
	{
		while (ar[i] < copy)
        {
            ++i;
        }
		while (ar[j] > copy)
        {
            --j;
        }

		if (i <= j)
        {
			swap(ar[i++], ar[j--]);
        }
	}

	if ((left < j) && (k <= j))
    {
        quick_sort(ar, left, j, k);
    }
	if ((i < right) && (k >= i))
    {
        quick_sort(ar, i, right, k);
    }
}

int main()
{
	ifstream input("kth.in");
	ofstream output("kth.out");
	int n, k, A, B, C;

	input >> n >> k;

	vector<int> array(n);

	input >> A >> B >> C >> array[0] >> array[1];

	for (int i = 2; i < n; i++)
    {
        array[i] = A * array[i - 2] + B * array[i - 1] + C;
    }

	quick_sort(array, 0, array.size() - 1, k - 1);

	output << array[k - 1] << endl;

	return 0;
}
