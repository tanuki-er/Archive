#include <fstream>
#include <string>
#include <vector>

using namespace std;
class Stack

{
private:
	vector<int> array;
public:
	void add(int num)
	{
		array.push_back(num);
	}

	int del()
	{
		int num = array.back();
		array.pop_back();
		return num;
	}
};

int main()
{
	ifstream input("stack.in");
	ofstream output("stack.out");
	int n, number;
	string command;

	input >> n;

	Stack arr;

	for(int i = 0; i < n; i++)
	{
		input >> command;

		if (command == "+")
		{
			input >> number;
			arr.add(number);
		}
		else
		{
			output << arr.del() << endl;
		}
	}

	return 0;
}
