#include <iostream>
using namespace std;

int f[10002];
int N,M;

void init(int n)
{
    for(int i=1;i<=N;++i)
        f[i]=i;
}

int find(int x)
{
    if(f[x]==x)
        return x;
    f[x] = find(f[x]);
    return f[x];
}

void merge(int x,int y)
{
    int fx=find(x);
    int fy=find(y);

    f[fx] = fy;
}

void query(int x,int y)
{
    if(find(x)==find(y))
        cout << 'Y' << endl;
    else
        cout << 'N' << endl;
}