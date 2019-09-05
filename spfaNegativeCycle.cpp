#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

#define MAXN 2002
#define MAXM 13003

const int INF = 0x3f3f3f3f;

int dis[MAXN];
int vis[MAXN];
int cnt[MAXN];

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
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    memset(cnt,0,sizeof(cnt));
    memset(head,-1,sizeof(head));
    nEdge = 0;
    cin >> N >> M;

    int x,y,z;
    for(int i=0; i<M; ++i)
    {
        cin >> x >> y >> z;
        addEdge(x,y,z);
        if(z>=0 && x!=y)
            addEdge(y,x,z);
    }
}

bool spfa(int s)
{
    queue<int> q;
    q.push(s);
    dis[s] = 0;
    vis[s] = 1;
    ++cnt[s];

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
                ++cnt[v];
                if(cnt[v]>=N)
                    return 1;
                if(!vis[v])
                {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    int t;

    if(spfa(1))
        cout << "YES";
    else
        cout << "NO";
    cout << endl;


}