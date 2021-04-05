#include <vector>
#include <fstream>
#include <string>

using namespace std;
class heap
{
private:
    vector<int> array;
	int size;
public:
    heap(vector<int> copy)
    {
        array.push_back(0);
        for(int i = 0; i < copy.size(); i++)
        {
            array.push_back(copy[i]);
        }
        size = array.size();
        building();
    }
    void building()
    {
        for(int i = (size - 1) / 2; i >= 1; i--)
        {
            maximum(i);
        }
    }
    void maximum(int cursor)
    {
        int left, right;
        if (2 * cursor > size - 1)
        {
            left = 0;
        }
        else
        {
            left = 2 * cursor;
        }
        if (2 * cursor + 1 > size - 1)
        {
            right = 0;
        }
        else
        {
            right =  2 * cursor + 1;
        }
        int largest = cursor;
        if (left && array[left] > array[cursor])
        {
            largest = left;
        }
        if (right && array[right] > array[largest])
        {
            largest = right;
        }
        if (largest != cursor)
        {
            swap(array[cursor], array[largest]);
            maximum(largest);
        }
    }
    vector<int> sort()
    {
        for(int i = array.size() - 1; i > 1; i--)
        {
            swap(array[i], array[1]);
            size--;
            maximum(1);
        }
        vector<int> res(array);
        size = array.size();
        building();
        return res;
    }
};
int main()
{
	ifstream input("sort.in");
	ofstream output("sort.out");
	int n;
	input >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++)
    {
        input >> arr[i];
    }
	heap H(arr);
	vector<int> arr_res = H.sort();
	for(int i = 1; i < arr_res.size(); i++)
    {
        output << arr_res[i] << " ";
    }
}

