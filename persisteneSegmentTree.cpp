#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

constexpr int MAXN = 2e5+5;

int read()
{
    int x=0, t=1;
    char c = getchar();

    while(c<'0'||c>'9')
    {
        if(c == '-')
            t = -1;
        c = getchar();
    }

    while(c >='0' && c<='9')
    {
        x = x*10 + c - '0';
        c = getchar();
    }

    return x*t;
}

struct Num
{
    int v, idx;
    void init(int v_, int idx_)
    {
        this->v = v_;
        this->idx = idx_;
    }

    bool operator < (const Num& a) const
    {
        return v < a.v;
    }
}a[MAXN];

struct Node
{
    int l,r;
    int sum;
}Tree[MAXN*40];
int root[MAXN];
int cnt;
int n;
int N,M;

int  Insert(int l, int r, int pre, int pos)
{
    int root = ++cnt;
    Tree[root] = Tree[pre];
    Tree[root].sum++;
    if(l != r)
    {
        int mid = (l+r) >> 1;
        if(pos <= mid)
            Tree[root].l = Insert(l, mid, Tree[pre].l, pos);
        else
            Tree[root].r = Insert(mid+1, r, Tree[pre].r, pos);
    }
    return root;
}

int Query(int l, int r, int L, int R, int k)
{
    if(l == r)
        return l;
    int mid = (l+r) >> 1;

    int tmp = Tree[Tree[R].l].sum - Tree[Tree[L].l].sum;
    if(k <= tmp)
        return Query(l, mid, Tree[L].l, Tree[R].l, k);
    else
        return Query(mid+1, r, Tree[L].r, Tree[R].r, k-tmp);
}

int idx[MAXN];

void lsh()
{
    idx[a[1].idx] = ++n;
    int t = 1;
    for(int i=2; i<=N; ++i)
        if(a[i].v == a[i-1].v)
            idx[a[i].idx] = n;
        else
            idx[a[i].idx] = ++n, a[++t] = a[i];
}

void init()
{
    N = read();
    M = read();
    for(int i=1; i<=N; ++i)
    {
        a[i].v = read();
        a[i].idx = i;
    }
    sort(a+1, a+N+1);
    lsh();

    for(int i=1; i<=N; ++i)
        root[i] = Insert(1, n, root[i-1], idx[i]);
}

void process()
{
    int l,r,k;
    while(M--)
    {
        l = read();r = read();k = read();
        printf("%d\n", a[Query(1, n,root[l-1], root[r], k)].v);
    }
}

int main()
{
    init();
    process();
}
