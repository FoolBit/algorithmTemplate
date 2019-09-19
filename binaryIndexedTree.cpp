#include <iostream>
#include <cstring>
using namespace std;

#define MAX 400000
int a[MAX];
int C[MAX];
int N;

inline int lowbit(int x)
{
    return x & (-x);
}

void update(int pos, int delta)
{
    while(pos <= N)
    {
        C[pos] += delta;
        pos += lowbit(pos);
    }
}

int query(int pos)
{
    int sum = 0;
    while(pos > 0)
    {
        sum += C[pos];
        pos -= lowbit(pos);
    }
}

void init()
{
    cin >> N;
    int sum[MAX];
    memset(sum, 0, sizeof(sum));

    for(int i=1; i<=N; ++i)
    {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }

    for(int i=1; i<=N; ++i)
    {
        C[i] = sum[i] - sum[i - lowbit(i)];
    }
}
