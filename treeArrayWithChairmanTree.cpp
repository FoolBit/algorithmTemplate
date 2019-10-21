#include <cstdio>
#include <algorithm>

using namespace std;

inline int lowbit(int x)
{
    return x & (-x);
}

int read()
{
    int x = 0;
    char c = getchar();
    while(c < '0' || c> '9')
        c = getchar();
    while(c>='0' && c<='9')
    {
        x = x*10 + c - '0';
        c = getchar();
    }

    return x;
}

constexpr int MAXN = 1e5+5;
constexpr int LEFT = 0;
constexpr int RIGHT = 1;

int N,M;
int cnt;
int len;
int rt[MAXN*400];
int ls[MAXN*400];
int rs[MAXN*400];
int val[MAXN*400];
int idx[MAXN*2];
int a[MAXN];
int ts[2];
int tree[2][MAXN*2];

struct Num
{
    int v;
    int pos;
    bool operator < (const Num& a) const
    {
        return v < a.v;
    }
    void init(int v_, int p_)
    {
        v = v_;
        pos = p_;
    }
}b[MAXN*2];

struct Operation
{
    int q;
    int i,j,k,t;
}ops[MAXN];

void ins(int l, int r, int& now, int v, int delta)
{
    if(!now)
        now = ++cnt;
    val[now] += delta;
    if(l == r)
        return;

    int mid = (l+r)>>1;
    if(v <= mid)
    {
        ins(l, mid, ls[now], v, delta);
    }
    else
    {
        ins(mid+1, r, rs[now], v, delta);
    }
}

int add(int pos, int delta)
{
    int v = idx[a[pos]];
    int x = pos;
    while(x<=N)
    {
        ins(1, len, rt[x], v, delta);
        x += lowbit(x);
    }
    return x;
}

int query(int l, int r, int k)
{
    if(l == r)
        return l;
    int sum = 0;
    for(int i=1; i<=ts[LEFT]; ++i)
        sum -= val[ls[tree[LEFT][i]]];
    for(int i=1; i<=ts[RIGHT]; ++i)
        sum += val[ls[tree[RIGHT][i]]];
    int mid = (l+r)>>1;

    if(k<=sum)
    {
        for(int i=1; i<=ts[LEFT]; ++i)
            tree[LEFT][i] = ls[tree[LEFT][i]];
        for(int i=1; i<=ts[RIGHT]; ++i)
            tree[RIGHT][i] = ls[tree[RIGHT][i]];

        return query(l, mid, k);
    }
    else
    {
        for(int i=1; i<=ts[LEFT]; ++i)
            tree[LEFT][i] = rs[tree[LEFT][i]];
        for(int i=1; i<=ts[RIGHT]; ++i)
            tree[RIGHT][i] = rs[tree[RIGHT][i]];
        return query(mid+1, r, k-sum);
    }
}

int Q(int l, int r, int k)
{
    ts[LEFT] = ts[RIGHT] = 0;

    for(int i=l-1; i; i-=lowbit(i))
        tree[LEFT][++ts[LEFT]] = rt[i];

    for(int i=r; i; i-=lowbit(i))
        tree[RIGHT][++ts[RIGHT]] = rt[i];

    return query(1, len, k);
}

void lsh()
{
    sort(b+1, b+len+1);

    int k = len;
    len = 0;
    idx[b[1].pos] = ++len;
    for(int i=2; i<=k; ++i)
    {
        if(b[i].v == b[i-1].v)
            idx[b[i].pos] = len;
        else
            idx[b[i].pos] = ++len, b[len] = b[i];
    }
}

void init()
{
    N = read();M = read();
    for(int i=1; i<=N; ++i)
    {
        a[i] = ++len;
        b[len].init(read(), len);
    }

    char s[5];
    for(int i=1; i<=M; ++i)
    {
        scanf("%s", s);
        if(s[0]=='Q')
        {
            ops[i].q = 1;
            ops[i].i = read();
            ops[i].j = read();
            ops[i].k = read();
        }
        else
        {
            ops[i].q = 0;
            ops[i].i = read();
            ops[i].t = ++len;
            b[len].init(read(), len);
        }
    }

    lsh();

    for(int i=1; i<=N; ++i)
        add(i, 1);
}

void work()
{
    for(int i=1; i<=M; ++i)
    {
        if(ops[i].q)
        {
            int id = Q(ops[i].i, ops[i].j, ops[i].k);
            printf("%d\n", b[id].v);
        }
        else
        {
            add(ops[i].i, -1);
            a[ops[i].i] = ops[i].t;
            add(ops[i].i, 1);
        }
    }
}

int main()
{
    init();
    work();
}


