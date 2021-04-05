#include <vector>
#include <string>
#include <map>
#include <fstream>

using namespace std;

struct Node
{
	int value, line;
};

class heap
{
private:
    vector<Node> source;
	int size;

public:
	heap()
    {
        source.resize(1000000);

        size = 0;
    }

    void insert(int value, int line)
    {
        size++;

        source[size].value = LONG_MAX;
        source[size].line = line;

        decreaseKey(line, value);
    }

    void decreaseKey(int line, int value)
    {
        int pos = 0;

        for(int i = 1; i <= size; i++)
        {
            if (source[i].line == line)
            {
                pos = i;

                break;
            }
        }

        if (pos == 0)
        {
            return;
        }

        if (source[pos].value < value)
        {
            return;
        }

        source[pos].value = value;

        while (pos > 1 && source[parent(pos)].value > source[pos].value)
        {
            swap(source[pos], source[parent(pos)]);

            pos = parent(pos);
        }
    }

    int extractMin()
    {
        if (size < 1)
        {
            return LONG_MAX;
        }

        int min;

        min = source[1].value;

        source[1] = source[size];
        size--;

        minHeapify(1);

        return min;
    }

	void minHeapify(int index)
    {
        int left, right;

        if (2 * index > size)
        {
            left = 0;
        }
        else
        {
            left = 2 * index;
        }

        if (2 * index + 1 > size)
        {
            right = 0;
        }
        else
        {
            right = 2 * index + 1;
        }

        int smallest = index;

        if (left && source[left].value < source[smallest].value)
        {
            smallest = left;
        }
        if (right && source[right].value < source[smallest].value)
        {
            smallest = right;
        }

        if (smallest != index)
        {
            swap(source[index], source[smallest]);

            minHeapify(smallest);
        }
    }

    int parent(int index)
    {
        return index / 2;
    }
};

int main()
{
	ifstream input("priorityqueue.in");
	ofstream output("priorityqueue.out");
	heap PQ;
	string command;

	int i = 1;

	while (input >> command)
	{
		if (command == "push")
		{
			int x;

			input >> x;

			PQ.insert(x, i);
		}

		if (command == "extract-min")
		{
			int x;

			x = PQ.extractMin();

			if (x == LONG_MAX)
            {
                output << "*" << "\n";
            }
			else
            {
                output << x << "\n";
            }
		}

		if (command == "decrease-key")
		{
			int x, y;

			input >> x >> y;

			PQ.decreaseKey(x, y);
		}

		i++;
	}

	return 0;
}
