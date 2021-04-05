#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

const bool DEBUG = false;

struct Node
{
	string Key, Value;
	Node *NextInChain;
	Node *NextElem, *PrevElem;
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
        Start->NextInChain = nullptr;
    }

    void Insert(string K, string V, Node *Head)
    {
        Node *NewNode = Search(K);

        if (Search(K) == nullptr)
        {
            NewNode = new Node;
            NewNode->Key = K;
            NewNode->Value = V;
            NewNode->NextInChain = Start->NextInChain;
            Start->NextInChain = NewNode;
            Node *Tail = Head->PrevElem;
            Tail->NextElem = NewNode;
            Head->PrevElem = NewNode;
            NewNode->NextElem = Head;
            NewNode->PrevElem = Tail;

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

    void Delete(string K, Node *Head)
    {
        Node *CurNode = Start;

        while (CurNode->NextInChain != nullptr)
        {
            if (CurNode->NextInChain->Key == K)
            {
                Node *NodeToDel = CurNode->NextInChain;
                CurNode->NextInChain = CurNode->NextInChain->NextInChain;
                Node *PrevNode = NodeToDel->PrevElem, *NextNode = NodeToDel->NextElem;
                NodeToDel->PrevElem->NextElem = NextNode;
                NodeToDel->NextElem->PrevElem = PrevNode;
                delete NodeToDel;

                if (DEBUG)
                {
                    cout << "Delete " << K << "\n";
                }

                return;
            }
            else
            {
                CurNode = CurNode->NextInChain;
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

        while (CurNode->NextInChain != nullptr)
        {
            if (CurNode->NextInChain->Key == K)
            {
                if (DEBUG)
                {
                    cout << "Search " << K << "\n";
                }

                return CurNode->NextInChain;
            }
            else
            {
                CurNode = CurNode->NextInChain;
            }
        }

        if (DEBUG)
        {
            cout << "Search (unsuccessful) " << K << "\n";
        }

        return nullptr;
    }
};

class LinkedMap
{
private:
    vector<List> Src;
	Node *Head;


public:
	LinkedMap()
    {
        Src.resize(1000);
        Head = new Node;
        Head->NextElem = Head->PrevElem = Head;
        Head->Value = Head->Key = "HEAD";
    }

    int H(string K)
    {
        unsigned int res = 0, pow = 1, p = 31, s = Src.size();

        for(int i = 0; i < K.length(); i++)
        {
            res += (K[i] - 'A') * pow;
            pow *= p;
        }

        return res % s;
    }

    void Insert(string K, string V)
    {
        Src[H(K)].Insert(K, V, Head);
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
        Src[H(K)].Delete(K, Head);
    }

    string Next(string K)
    {
        Node *Res = Src[H(K)].Search(K);

        if (Res == nullptr || Res->NextElem == Head)
        {
            return "none";
        }
        else
        {
            return Res->NextElem->Value;
        }
    }

    string Prev(string K)
    {
        Node *Res = Src[H(K)].Search(K);

        if (Res == nullptr || Res->PrevElem == Head)
        {
            return "none";
        }
        else
        {
            return Res->PrevElem->Value;
        }
    }

	void Print()
	{
		Node *CurNode = Head->NextElem;

		while (CurNode != Head)
		{
			cout << "(" + CurNode->Key + ", " + CurNode->Value + ")\n";

			CurNode = CurNode->NextElem;
		}

		cout << "\n";
	}
};

int main()
{
	ifstream input("linkedmap.in");
	ofstream output("linkedmap.out");
	LinkedMap LM;
	string Command;

	while (input >> Command)
	{
		string K, V;

		if (Command == "put")
		{
			input >> K >> V;

			LM.Insert(K, V);
		}

		if (Command == "delete")
		{
			input >> K;

			LM.Delete(K);
		}

		if (Command == "get")
		{
			input >> K;

			output << LM.Search(K) << "\n";
		}

		if (Command == "next")
		{
			input >> K;

			output << LM.Next(K) << "\n";
		}

		if (Command == "prev")
		{
			input >> K;

			output << LM.Prev(K) << "\n";
		}
	}

	return 0;
}
