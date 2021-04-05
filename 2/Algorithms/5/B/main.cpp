#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

const bool DEBUG = false;

struct Node
{
	string Key, Value; 
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
        Start->Value = Start->Key = "";
        Start->Next = nullptr;
    }

    void Insert(string K, string V)
    {
        Node *NewNode = Search(K);

        if (Search(K) == nullptr)
        {
            NewNode = new Node;
            NewNode->Key = K;
            NewNode->Value = V;
            NewNode->Next = Start->Next;
            Start->Next = NewNode;

            if (DEBUG)
            {
                cout << "Insert " << K << " " << V << "\n";
            }
        }
        else
        {
            NewNode->Value = V;

            if (DEBUG)
            {
                cout << "Replace " << K << " " << V << "\n";
            }
        }
    }

    void Delete(string K)
    {
        Node *CurNode = Start;

        while (CurNode->Next != nullptr)
        {
            if (CurNode->Next->Key == K)
            {
                Node *NodeToDel = CurNode->Next;
                CurNode->Next = CurNode->Next->Next;

                delete NodeToDel;

                if (DEBUG)
                {
                    cout << "Delete " << K << "\n";
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
            cout << "Delete (unsuccessful) " << K << "\n";
        }
    }

    Node* Search(string K)
    {
        Node *CurNode = Start;

        while (CurNode->Next != nullptr)
        {
            if (CurNode->Next->Key == K)
            {
                if (DEBUG)
                {
                    cout << "Search " << K << "\n";
                }

                return CurNode->Next;
            }
            else
            {
                CurNode = CurNode->Next;
            }
        }

        if (DEBUG)
        {
            cout << "Search (unsuccessful) " << K << "\n";
        }

        return nullptr;
    }
};

class Map
{
private:
    vector<List> Src;

public:
	Map()
    {
        Src.resize(1000);
    }

    int H(string K)
    {
        unsigned int res, pow, p, s;

        res = 0;
        pow = 1;
        p = 31;
        s = Src.size();

        for(int i = 0; i < K.length(); i++)
        {
            res += (K[i] - 'A') * pow;
            pow *= p;
        }

        return res % s;
    }

    void Insert(string K, string V)
    {
        Src[H(K)].Insert(K, V);
    }

    string Search(string K)
    {
        Node *Res = Src[H(K)].Search(K);

        if (Res == nullptr)
        {
            return "none";
        }
        else
        {
            return Res->Value;
        }
    }

    void Delete(string K)
    {
        Src[H(K)].Delete(K);
    }
};

int main()
{
	ifstream input("map.in");
	ofstream output("map.out");
	Map S;
	string Command;

	while (input >> Command)
	{
		string K, V;

		if (Command == "put")
		{
			input >> K >> V;

			S.Insert(K, V);
		}

        if (Command == "delete")
        {
            input >> K;

            S.Delete(K);
        }

		if (Command == "get")
		{
			input >> K;

			output << S.Search(K) << "\n";
		}
	}

	return 0;
}
