#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Stack
{
private:
    vector<char> array;
public:
	void add(char symbol)
	{
		array.push_back(symbol);
	}

	void del()
	{
		if (!check())
        {
            array.pop_back();
        }
	}

	char height()
	{
		if (check())
        {
            return 0;
        }

		return array.back();
	}

	bool check()
	{
		return (array.size() == 0);
	}
};

bool test(string str)
{
	Stack stack;

	for(int i = 0; i < (str.length()); i++)
    {
        if ((str[i] == '(') || (str[i] == '['))
        {
            stack.add(str[i]);
        }
		else
        {
            if (!(((str[i] == ')') && (stack.height() == '(')) || ((str[i] == ']') && (stack.height() == '['))))
            {
                return false;
            }
            else
			{
			    stack.del();
			}
        }
    }

	if (stack.check())
    {
        return true;
    }
	else
    {
        return false;
    }
}

int main()
{
	ifstream input("brackets.in");
	ofstream output("brackets.out");
	string line;

	while (input >> line)
	{
		if (test(line))
        {
            output << "YES" << endl;
        }
		else
        {
            output << "NO" << endl;
        }
	}

	return 0;
}
