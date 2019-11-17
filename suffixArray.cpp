#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
using namespace std;

#define reset(a,v) memset(a,v,sizeof(a))
#define rep(i,a,b) for(register int i=a;i<b;++i)
#define repp(i,a,b) for(register int i=a;i<=b;++i)
#define rrep(i,a,b) for(register int i=a;i>b;--i)
#define rrepp(i,a,b) for(register int i=a;i>=b;--i)

#define __ 1000010
int n,m=256,sa[__], tp[__], rk[__], a[__];
char c[__];

void init()
{
    scanf("%s", c+1);
    n = strlen(c+1);
    repp(i, 1, n)
    {
        rk[i] = c[i]-'0'+1, tp[i] = i;
    }
}

void Qsort()
{
    repp(i, 1, m)
        a[i] = 0;
    repp(i, 1, n)
        ++a[rk[i]];
    repp(i, 2, m)
        a[i] += a[i-1];
    rrepp(i, n, 1)
        sa[a[rk[tp[i]]]--] = tp[i];
}

void buildSA()
{
    for(int w=1,p=0; p<n; m=p, w<<=1)
    {
        p = 0;
        repp(i, n-w+1, n)
            tp[++p] = i;
        repp(i, 1, n)
        {
            if(sa[i]>w)
                tp[++p] = sa[i]-w;
        }
        
        Qsort();
        swap(rk, tp);
        p = rk[sa[1]] = 1;
        
        repp(i, 2, n)
        {
            rk[sa[i]] =
                (tp[sa[i]]==tp[sa[i-1]]&&tp[sa[i]+w]==tp[sa[i-1]+w])?p:++p;
        }
    }
}

void print()
{
    repp(i, 1, n)
    {
        printf("%d ",sa[i]);
    }
}

int main()
{
    init();
    Qsort();
    buildSA();
    print();
}

