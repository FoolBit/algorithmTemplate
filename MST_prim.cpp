#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

#define N 5002
#define M 400004

int head[N];
int size;
struct Edge
{
    int u,v,w,next;
}E[M];

void addEdge(int x,int y,int z)
{
    ++size;
    E[size].u = x;
    E[size].v = y;
    E[size].w = z;
    E[size].next = head[x];
    head[x] = size;
}

int n,m;
int dis[N];
int vis[N];
int prim(int s)
{
    memset(dis,0x3f,sizeof(dis));
    dis[s] = 0;

    int ans=0;
    for(int i=0; i<n; ++i)
    {
        int min=0x3f3f3f3f;
        int k=-1;
        for(int j=1;j<=n;++j)
            if(min > dis[j] && !vis[j])
            {
                min = dis[j];
                k = j;
            }
        if(k==-1)
            return k;

        vis[k] = 1;
        ans+=dis[k];
        for(int j=head[k];j!=-1;j=E[j].next)
        {
            int v=E[j].v;
            int w=E[j].w;
            if(!vis[v] && dis[v]>w)
                dis[v] = w;
        }
    }

    return ans;
}


int main()
{
    ios::sync_with_stdio(0);
    freopen("testdata.in","r",stdin);
    memset(head,-1,sizeof(head));

    cin >> n >> m;
    for(int i=0; i<m; ++i)
    {
        int x,y,z;
        cin >> x >> y >> z;
        addEdge(x,y,z);
        addEdge(y,x,z);
    }

    int ans = prim(1);
    if(ans == -1)
        cout << "orz";
    else
        cout << ans;

}