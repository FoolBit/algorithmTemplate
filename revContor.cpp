#include <iostream>
#include <cstring>

using namespace std;

#define N 400010
int factor[N]; // 存储阶乘
int vis[N];

// 𝑋=𝑎[𝑛]∗(𝑛−1)!+𝑎[𝑛−1]∗(𝑛−2)!+...+𝑎[𝑖]∗(𝑖−1)!+...+𝑎[1]∗0!
void revContor(int *a, int X,int n)
{
    --X;
    for(int i=0; i<n; ++i)
    {
        int num=X/factor[n-i-1];
        X %= factor[n-i-1];
        for(int j=0; j<n; ++j)
        {
            if(!vis[j])
            {
                if(!num)
                {
                    a[i] = j;
                    vis[j] = 1;
                    break;
                }
                --num;
            }
        }
    }
}

