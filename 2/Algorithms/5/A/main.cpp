#include <fstream>
#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
const bool DEBUG = false;

struct Node
{ 
	int Value;
	Node *Next;
};
class List
{
private:
	Node *Start;

public:
	List()
    {
        Start = new Node();
        Start->Value = LONG_MAX;
        Start->Next;
    }
    void Insert(int x)
    {
        Node *NewNode = new Node;
        NewNode->Value = x;
        NewNode->Next = Start->Next;
        Start->Next = NewNode;

        if (DEBUG)
        {
            cout << "Insert " << x << "\n";
        }
    }

    void Delete(int x)
    {
        Node *CurNode = Start;

        while (CurNode->Next != NULL)
        {
            if (CurNode->Next->Value == x)
            {
                Node *NodeToDel = CurNode->Next;
                CurNode->Next = CurNode->Next->Next;

                delete NodeToDel;

                if (DEBUG)
                {
                    cout << "Delete " << x << "\n";
                }

                return;
            }
            else
            {
                CurNode = CurNode->Next;
            }
        }

        if (DEBUG)
        {
            cout << "Delete (unsuccessful) " << x << "\n";
        }
    }

    bool Search(int x)
    {
        Node *CurNode = Start;

        while (CurNode->Next != NULL)
        {
            if (CurNode->Next->Value == x)
            {
                if (DEBUG)
                {
                    cout << "Search " << x << "\n";
                }

                return true;
            }
            else
            {
                CurNode = CurNode->Next;
            }
        }

        if (DEBUG)
        {
            cout << "Search (unsuccessful) " << x << "\n";
        }

        return false;
    }

    void Print()
    {
        Node *CurNode = Start->Next;

        do
        {
            cout << CurNode->Value << " ";
            CurNode = CurNode->Next;
        } while (CurNode != Start);

        cout << "\n";
    }
};

class Set
{
private:
    vector<List> Src;

public:
	Set()
    {
        Src.resize(100000);
    }

    int H(int x)
    {
        int res;

        res = x % (int)Src.size();

        if (res < 0)
        {
            res += Src.size();
        }

        return res;
    }

    void Insert(int x)
    {
        if (!Search(x))
        {
            Src[H(x)].Insert(x);
        }
    }

    bool Search(int x)
    {
        return Src[H(x)].Search(x);
    }

    void Delete(int x)
    {
        Src[H(x)].Delete(x);
    }
};

int main()
{
	ifstream input("set.in");
	ofstream output("set.out");
	Set S;
	string Command;

	while (input >> Command)
	{
		int x;

		if (Command == "insert")
		{
			input >> x;

			S.Insert(x);
		}

		if (Command == "delete")
		{
			input >> x;

			S.Delete(x);
		}

		if (Command == "exists")
		{
			input >> x;

			if (S.Search(x))
            {
                output << "true\n";
            }
			else
            {
                output << "false\n";
            }
		}
	}
	return 0;
}
