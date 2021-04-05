#include <fstream>
#include <stack>
#include <algorithm>

using namespace std;

class stack_min
{
private:
    stack<pair<int, int> > Src;

public:
	void push(int x)
	{
		int minimum = empty() ? x : min(x, Src.top().second);

		Src.push(make_pair(x, minimum));
	}

	int pop()
	{
		int x = Src.top().first;

		Src.pop();

		return x;
	}

	bool empty()
	{
		return Src.size() == 0;
	}

	int getMin()
	{
		return Src.top().second;
	}
};

class queue_min
{
private:
    stack_min st1, st2;

public:
	void enqueue(int x)
	{
		st1.push(x);
	}

	int dequeue()
	{
		if (st2.empty())
        {
            while (!st1.empty())
            {
                st2.push(st1.pop());
            }
        }

		return st2.pop();
	}

	int getMin()
	{
		if (st1.empty() || st2.empty())
        {
            return st1.empty() ? st2.getMin() : st1.getMin();
        }
		else
        {
            return min(st1.getMin(), st2.getMin());
        }
	}
};

int main()
{
	ifstream input("queuemin.in");
	ofstream output("queuemin.out");
	int M;
	queue_min QM;

	input >> M;

	for(int i = 0; i < M; i++)
	{
		char c;
		int x;

		input >> c;

		if (c == '+')
		{
			input >> x;

			QM.enqueue(x);
		}
		else
        {
            if (c == '-')
			{
			    QM.dequeue();
			}
            else
			{
			    output << QM.getMin() << endl;
			}
        }
	}

	return 0;
}
