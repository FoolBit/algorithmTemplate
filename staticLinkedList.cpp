#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

#define N 5002
#define M 200002

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

int main()
{
    memset(head,-1,sizeof(head));

    cin >> n >> m;
    for(int i=0; i<m; ++i)
    {
        int x,y,z;
        cin >> x >> y >> z;
        addEdge(x,y,z);
    }
}