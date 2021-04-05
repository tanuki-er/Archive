#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

struct edge
{
    int a, b;
    long long cost;

    edge(int a_, int b_, long long cost_) : a(a_), b(b_), cost(cost_) {}
};

const int nMax = 2001;
int n, m;
long long weight;
vector<edge> e;
long long INF = 1000000000000001;
int x;

vector<long> d(nMax, INF);
vector<int> p(nMax, -1);

void F()
{
    for(int i = 0; i < n; i++)
    {
        x = -1;

        for(int j = 0; j < m; j++)
        {
            if (d[e[j].b] > d[e[j].a] + e[j].cost)
            {
                d[e[j].b] = max(-INF, d[e[j].a] + e[j].cost);
                p[e[j].b] = e[j].a;
                x = e[j].b;
            }
        }
    }

    if (x == -1)
    {
        cout << "NO";
    }
    else
    {
        int y = x;

        for(int i = 0; i < n; i++)
        {
            y = p[y];
        }

        vector<int> path;

        for(int cur = y;; cur = p[cur])
        {
            path.push_back(cur);

            if (cur == y && path.size() > 1)
            {
                break;
            }
        }

        reverse(path.begin(), path.end());

        cout << "YES\n";
        cout << path.size() << '\n';

        for(size_t i = 0; i < path.size(); i++)
        {
            cout << path[i] + 1 << ' ';
        }
    }
}

int main()
{
    ifstream cin("negcycle.in");
    ofstream cout("negcycle.out");

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> weight;

            edge curE(i, j, weight);

            if (weight != 1e9)
            {
                e.push_back(curE);
            }
        }
    }

    m = (int)e.size();

    F();

    return 0;
}
