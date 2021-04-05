#include <fstream>
#include <string>
#include <vector>

using namespace std;

int number;

class Queue
{
private:
    vector<int> arr;
public:
	void add(int number)
	{
		arr.push_back(number);
	}

	int del()
	{
		number = arr.front();

		arr.erase(arr.begin());

		return number;
	}
};

int main()
{
	ifstream input("queue.in");
	ofstream output("queue.out");
	int n;

	input >> n;

	Queue array;

	for(int i = 0; i < n; i++)
	{
		string command;

		input >> command;

		if (command == "+")
		{
			input >> number;

			array.add(number);
		}
		else
		{
			output << array.del() << endl;
		}
	}

	return 0;
}
