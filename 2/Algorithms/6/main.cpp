#include <fstream>
#include <string>
#include <vector>

using namespace std;

const bool DEBUG = false;

struct Node
{
	int key;
	Node *p, *l, *r;
};

class BST
{
private:
    Node *root = nullptr;

public:
	void insert(int x)
    {
        if (exists(x))
        {
            return;
        }

        Node *newNode = new Node;

        newNode->key = x;
        newNode->p = newNode->l = newNode->r = nullptr;
        Node *curPos = root;

        while (curPos != nullptr)
        {
            newNode->p = curPos;
            if (newNode->key < curPos->key)
            {
                curPos = curPos->l;
            }
            else
            {
                curPos = curPos->r;
            }
        }

        if (newNode->p == nullptr)
        {
            root = newNode;
        }
        else
        {
            if (newNode->key < newNode->p->key)
            {
                newNode->p->l = newNode;
            }
            else
            {
                newNode->p->r = newNode;
            }
        }
    }

    void remove(int x)
    {
        Node *delNode = search(x);

        if (delNode == nullptr)
        {
            return;
        }

        Node *y, *u;

        if (delNode->l == nullptr || delNode->r == nullptr)
        {
            y = delNode;
        }
        else
        {
            y = next(x);
        }

        if (y->l != nullptr)
        {
            u = y->l;
        }
        else
        {
            u = y->r;
        }

        if (u != nullptr)
        {
            u->p = y->p;
        }

        if (y->p == nullptr)
        {
            root = u;
        }
        else
        {
            if (y == y->p->l)
            {
                y->p->l = u;
            }
            else
            {
                y->p->r = u;
            }
        }

        if (y != delNode)
        {
            delNode->key = y->key;
        }

        delete y;
    }

    Node* search(int x)
    {
        Node *curNode = root;

        while (curNode != nullptr && x != curNode->key)
        {
            if (x < curNode->key)
            {
                curNode = curNode->l;
            }
            else
            {
                curNode = curNode->r;
            }
        }

        return curNode;
    }

    bool exists(int x)
    {
        return search(x) != nullptr;
    }

    Node* next(int x)
    {
        Node *curNode = root, *sucNode = nullptr;

        while (curNode != nullptr)
        {
            if (curNode->key > x)
            {
                sucNode = curNode;
                curNode = curNode->l;
            }
            else
            {
                curNode = curNode->r;
            }
        }

        return sucNode;
    }

    Node* prev(int x)
    {
        Node *curNode = root, *prevNode = nullptr;

        while (curNode != nullptr)
        {
            if (curNode->key < x)
            {
                prevNode = curNode;
                curNode = curNode->r;
            }
            else
            {
                curNode = curNode->l;
            }
        }

        return prevNode;
    }

    void InorderWalk(Node* r, vector<int> &Keys)
    {
        if (r != nullptr)
        {
            InorderWalk(r->l, Keys);

            Keys.push_back(r->key);

            InorderWalk(r->r, Keys);
        }
    }

    bool isCorrect()
    {
        vector<int> keys;

        InorderWalk(root, keys);

        for(int i = 1; i < keys.size(); i++)
        {
            if (keys[i - 1] >= keys[i])
            {
                return false;
            }
        }

        return true;
    }

    Node* min(Node* r)
    {
        while (r->l != nullptr)
        {
            r = r->l;
        }

        return r;
    }

    Node* max(Node* r)
    {
        while (r->r != nullptr)
        {
            r = r->r;
        }

        return r;
    }
};

int main()
{
	ifstream input("bstsimple.in");
	ofstream output("bstsimple.out");
	BST tree;
	string command;
	int value;

	while (input >> command >> value)
	{
		if (command == "insert")
		{
			tree.insert(value);

			if (DEBUG) output << (tree.isCorrect() ? "correct" : "incorrect") << endl;
		}

		if (command == "delete")
		{
			tree.remove(value);

			if (DEBUG) output << (tree.isCorrect() ? "correct" : "incorrect") << endl;
		}

		if (command == "exists")
        {
            if (tree.search(value))
            {
                output << "true\n";
            }
			else
            {
                output << "false\n";
            }
        }

		if (command == "next")
		{
			Node *res = tree.next(value);

			if (res == nullptr)
            {
                output << "none\n";
            }
			else
            {
                output << res->key << "\n";
            }
		}

		if (command == "prev")
		{
			Node *res = tree.prev(value);

			if (res == nullptr)
            {
                output << "none\n";
            }
			else
            {
                output << res->key << "\n";
            }
		}
	}

	return 0;
}
