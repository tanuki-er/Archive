#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <set>
#include <fstream>

using namespace std;

typedef long long num;

const int N = 2100;
const num INF = num(1e15);

vector<pair<num, int> > g[N];
int n, s, t;
num d[N];
set<pair<num, int> > q;

void F(int u)
{
    d[u] = 0;

    q.insert(make_pair(0LL, u));

    while(!q.empty())
    {
        auto e = *q.begin();
        q.erase(e);

        int u = e.second;

        if(u == t)
        {
            return;
        }
        for(int i = 0; i < g[u].size(); i++)
        {
            int w, v;

            w = g[u][i].first;
            v = g[u][i].second;

            if (d[u] + w < d[v])
            {
                q.erase(make_pair(d[v], v));

                d[v] = d[u] + w;

                q.insert(make_pair(d[v], v));
            }
        }
    }
}

int main()
{
    fstream input("pathmgep.in"), output("pathmgep.out");

    input >> n >> s >> t;

    s--;
    t--;

    for(int i = 0; i < n; i++)
    {
        d[i] = INF;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            num v;

            input >> v;

            if(v != -1 && i != j)
            {
                g[i].push_back(make_pair(v, j));
            }
        }
    }

    F(s);

    if (d[t] == INF)
    {
        output << -1 << endl;
    }
    else
    {
        output << d[t] << endl;
    }

    return 0;
}
