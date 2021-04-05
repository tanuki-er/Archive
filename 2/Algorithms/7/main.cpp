#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <set>

using namespace std;

const int N = 30100;
const int INF = 2 * int(1e9);

set <pair<int, int> > q;
int n, m, d[N];
vector <pair<int, int> > g[N];

void F()
{
    while(!q.empty())
    {
        pair<int, int> u = *q.begin();

        q.erase(u);

        for(size_t i = 0; i < g[u.second].size(); i++)
        {
            int v, w;

            v = g[u.second][i].first;
            w = g[u.second][i].second;

            if (u.first + w < d[v])
            {
                q.erase(make_pair(d[v], v));

                d[v] = u.first + w;

                q.insert(make_pair(d[v], v));
            }
        }
    }
}

int main(){
    freopen("pathbgep.in", "r", stdin);
    freopen("pathbgep.out", "w", stdout);

    cin >> n >> m;

    for(int i = 1; i < n; i++)
    {
        d[i] = INF;
    }

    for(int i = 0; i < m; i++)
    {
        int a, b, w;

        scanf("%d %d %d", &a, &b, &w);

        g[a - 1].push_back(make_pair(b - 1, w));
        g[b - 1].push_back(make_pair(a - 1, w));
    }

    q.insert(make_pair(0, 0));

    F();

    for(int i = 0; i < n; i++)
    {
        printf("%d ", d[i]);
    }

    return 0;
}
