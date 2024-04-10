#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010, INF = 0x3f3f3f3f;

int n, m;

typedef struct
{
    int Head;
    int Tail;
    int lowcost;
}EdgeM;

EdgeM Edge[2 * N];

int p[N];
int find(int x)
{
    if (p[x] == x) return x;
    return p[x] = find(p[x]);
}

bool operator < (const EdgeM& p1, const EdgeM& p2)
{
    return p1.lowcost < p2.lowcost;
}

int MiniSpanTree()
{
    sort(Edge + 1, Edge + m + 1);
    int res = 0, cnt = 0;
    for (int i = 1; i <= n; ++i)  p[i] = i;//初始时，每个点为一个单独的连通分量                                                 
    for (int i = 1; i <= m && cnt != n - 1; ++i) {
        int v1 = Edge[i].Head, v2 = Edge[i].Tail;
        int vs1 = find(v1), vs2 = find(v2);
        if (vs1 != vs2)
        {
            res += Edge[i].lowcost; ++cnt;
            p[vs1] = find(vs2);
        }
    }
    if (cnt == n - 1) return res;
    return INF;
}

int main()
{
    cin >> n >> m;//n个点，m个边
    int x, y, w;
    for (int i = 1; i <= m; ++i) {
        cin >> x >> y >> w;
        Edge[i] = { x, y, w };
    }
    int t = MiniSpanTree();
    if (t < INF)  cout << t << '\n';
    else cout << "impossible" << '\n';

    return 0;
}

