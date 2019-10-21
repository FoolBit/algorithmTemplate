#include <cstdio>
#include <cstring>

using namespace std;

int read()
{
    int x=0, t=1;
    char c = getchar();
    while(c<'0' || c>'9')
    {
        if(c == '-')
            t = -1;
        c = getchar();
    }
    while(c>='0' && c<='9')
    {
        x = x*10 + c-'0';
        c = getchar();
    }
    return x*t;
}

constexpr int MAXN = 1e6+5;

struct Node
{
    int ls, rs;
    int val;
}Tree[MAXN*40];

int rt[MAXN];
int cnt;
int N,M;

int buildTree(int l, int r)
{
   int root = ++cnt;
   if(l == r)
   {
       Tree[root].val = read();
   }
   else
   {
       int mid = (l+r)>>1;
       Tree[root].ls = buildTree(l, mid);
       Tree[root].rs = buildTree(mid+1, r);
   }
   return root;
}

int modify(int l, int r, int pre, int pos, int val)
{
    int root = ++cnt;
    Tree[root] = Tree[pre];
    if(l == r)
    {
        Tree[root].val = val;
    }
    else
    {
        int mid = (l+r)>>1;
        if(pos <= mid)
            Tree[root].ls = modify(l, mid, Tree[pre].ls, pos, val);
        else
            Tree[root].rs = modify(mid+1, r, Tree[pre].rs, pos, val);
    }
    return root;
}

int query(int l, int r, int root, int pos)
{
    if(l == r)
    {
        return Tree[root].val;
    }
    int mid = (l+r)>>1;
    if(pos<=mid)
        return query(l, mid, Tree[root].ls, pos);
    else
        return query(mid+1, r, Tree[root].rs, pos);
}

void init()
{
    N = read();
    M = read();
    rt[0] = buildTree(1, N);
}

void work()
{
    int v,op,loc,val;
    for(int i=1; i<=M; ++i)
    {
        v = read();op = read();loc = read();
        if(op == 1)
        {
            val = read();
            rt[i] = modify(1, N, rt[v], loc, val);
        }
        else
        {
            rt[i] = rt[v];
            printf("%d\n", query(1, N, rt[i], loc));
        }
    }
}

int main()
{
    init();
    work();
}
