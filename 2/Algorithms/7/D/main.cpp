#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <set>
#include <fstream>

typedef long long num;

using namespace std;

const int N = 2100, M = 5100;
const num INF = 8000000000000000000LL;

struct E
{
    int from, to;
    num wght;
    E(){}
    E(int f, int t, num w): from(f), to(t), wght(w){}
};

int n, m, s;
num d[N];
E g[M];

enum STATUS
{
    OK,
    UNREACHED,
    NEG_CYCLE
} st[N];

void F()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if (st[g[j].from] == UNREACHED)
            {
                continue;
            }

            if (st[g[j].from] == NEG_CYCLE)
            {
                st[g[j].to] = NEG_CYCLE;

                continue;
            }

            if (st[g[j].to] == UNREACHED || d[g[j].to] > d[g[j].from] + g[j].wght)
            {
                d[g[j].to] = d[g[j].from] + g[j].wght;

                st[g[j].to] = OK;
            }

            if (d[g[j].to] < -INF)
            {
                st[g[j].to] = NEG_CYCLE;
            }
        }
    }

    for(int i = 0; i < n + 1; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if (st[g[j].from] == UNREACHED)
            {
                continue;
            }

            if (st[g[j].from] == NEG_CYCLE || d[g[j].to] > d[g[j].from] + g[j].wght)
            {
                st[g[j].to] = NEG_CYCLE;
            }
        }
    }
}

int main(){
    fstream input("path.in"), output("path.out");

    input >> n >> m >> s;

    for(int i = 0; i < n; i++)
    {
        st[i] = UNREACHED;
    }

    for(int i = 0; i < m; i++)
    {
        int a, b;
        num w;

        input >> a >> b >> w;

        g[i] = E(a - 1, b - 1, w);
    }

    st[s - 1] = OK;

    F();

    for(int i = 0; i < n; i++)
    {
        if (st[i] == UNREACHED)
        {
            output << "*\n";
        }
        else
            if (st[i] == NEG_CYCLE)
            {
                output << "-\n";
            }
            else
            {
                output << d[i] << "\n";
            }
    }

    return 0;
}
