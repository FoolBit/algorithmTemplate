#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

#define MAXN 10002
#define MAXM 500002

const int INF = 0x3f3f3f3f;

int dis[MAXN];
int vis[MAXN];

queue<int> q;

int head[MAXN];
struct Edge
{
    int u,v,w,next;
} edge[MAXM];
int nEdge;

void addEdge(int u,int v,int w)
{
    ++nEdge;
    edge[nEdge].u = u;
    edge[nEdge].v = v;
    edge[nEdge].w = w;
    edge[nEdge].next = head[u];
    head[u] = nEdge;
}

int N,M,S;

void init()
{
    ios::sync_with_stdio(0);
    memset(dis,0x3f,sizeof(dis));
    memset(head,-1,sizeof(head));

    cin >> N >> M >> S;

    int x,y,z;
    for(int i=0; i<M; ++i)
    {
        cin >> x >> y >> z;
        addEdge(x,y,z);
    }
}

void spfa()
{
    q.push(S);
    dis[S] = 0;
    vis[S] = 1;

    int i;
    while(q.size())
    {
        int t = q.front();q.pop();
        vis[t] = 0;

        for(i=head[t]; i!=-1; i=edge[i].next)
        {
            int v = edge[i].v;
            int w = edge[i].w;

            if(dis[t]+w < dis[v])
            {
                dis[v] = dis[t] + w;
                if(!vis[v])
                {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
}

int main()
{
    init();
    spfa();

    cout << dis[1];
    for(int i=2; i<=N; ++i)
        cout << ' ' << dis[i];
}