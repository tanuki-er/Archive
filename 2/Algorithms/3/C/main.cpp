#include <vector>
#include <fstream>

using namespace std;

bool heap(vector<int> &array)
{
	for (int i = 2; i < array.size(); i++)
    {
        if (array[i] < array[i / 2])
        {
            return false;
        }
    }

	return true;
}

int main()
{
	ifstream input("isheap.in");
	ofstream output("isheap.out");
	int n;

	input >> n;

	vector<int> array(n + 1);

	for(int i = 1; i < (n + 1); i++)
    {
        input >> array[i];
    }

	if (heap(array))
    {
        output << "YES";
    }
	else
    {
        output << "NO";
    }

	return 0;
}
