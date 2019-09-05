#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

#define MAXN 100002
#define MAXM 1000002
#define INF 0x3f3f3f3f

int head[MAXN];
int size;
struct Edge
{
    int v,w,next;
}E[MAXM];

void addEdge(int u, int v, int w)
{
    ++size;
    E[size].v = v;
    E[size].w = w;
    E[size].next = head[u];
    head[u] = size;
}

int d[MAXN];
int vis[MAXN];
int N,M,S;
struct Node
{
    int v,d;
    Node(){};
    Node(int v_, int d_):v(v_),d(d_){};

    bool operator < (const Node & a) const
    {
        return d > a.d;
    }
};
priority_queue<Node> q;

void dijkstra(int s)
{
    memset(d, INF, sizeof(d));

    d[s] = 0;
    q.push(Node(s, 0));

    Node node;
    for(int i=1; i<N; ++i)
    {
        int k;
        while(q.size())
        {
            node = q.top();
            q.pop();
            k = node.v;
            if(!vis[k])
                break;
        }
        if(vis[k])
            break;

        vis[k] = 1;
        for(int j=head[k]; j!=-1; j=E[j].next)
        {
            int v = E[j].v;
            int w = E[j].w;
            if(!vis[v] && d[k]+w < d[v])
            {
                d[v] = d[k]+w;
                q.push(Node(v, d[v]));
            }
        }
    }

}
int main() {
    ios::sync_with_stdio(0);
    memset(head, -1, sizeof(head));
    cin >> N >> M >> S;

    for (int i = 0; i < M; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        addEdge(x, y, z);
    }

    dijkstra(S);

    cout << d[1];
    for (int i = 2; i <= N; ++i)
        cout << ' ' << d[i];
}