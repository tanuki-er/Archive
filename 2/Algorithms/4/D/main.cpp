#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

class Stack
{
private:
    vector<int> arr;
public:
	void add(int num)
	{
		arr.push_back(num);
	}

	int del()
	{
		int num = arr.back();

		arr.pop_back();

		return num;
	}
};

int main()
{
	Stack array;
	ifstream input("postfix.in");
	ofstream output("postfix.out");
	string symbol;

	while (input >> symbol)
	{
		int result;

		if ((symbol[0] >= 48) && (symbol[0] <= 57))
        {
            int number;

            number = atoi(symbol.c_str());

            array.add(number);
        }
		else
		{
			int num1, num2;

			num1 = array.del();
			num2 = array.del();

			switch (symbol[0])
			{
			case '+':
			    {
			        result = num2 + num1;
                    array.add(result);
                    break;
			    }

			case '-':
			    {
			        result = num2 - num1;
                    array.add(result);
                    break;
			    }

			case '*':
				{
				    result = num2 * num1;
                    array.add(result);
                    break;
				}

			case '/':
				{
				    result = num2 / num1;
                    array.add(result);
                    break;
				}
			}

		}
	}

	output << array.del();

	return 0;
}
