#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <set>

using namespace std;

const int N = 250;
const int INF = 4 * int(1e6);

int n, m, g[N][N];

int main()
{
    freopen("pathsg.in", "r", stdin);
    freopen("pathsg.out", "w", stdout);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            g[i][j] = (i != j) * INF;
        }
    }

    for(int i = 0; i < m; i++)
    {
        int a, b, w;

        scanf("%d %d %d", &a, &b, &w);

        g[a - 1][b - 1] = w;
    }

    for(int i = 0; i < n; i++)
    {
        for(int u = 0; u < n; u++)
        {
            for(int v = 0; v < n; v++)
            {
                g[u][v] = min(g[u][v], g[u][i] + g[i][v]);
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d ", g[i][j]);
        }

        printf("\n");
    }

    return 0;
}
