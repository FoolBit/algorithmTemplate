#include <iostream>
#include <cstring>

using namespace std;

#define N 400010
int factor[N]; // 存储阶乘

// 𝑋=𝑎[𝑛]∗(𝑛−1)!+𝑎[𝑛−1]∗(𝑛−2)!+...+𝑎[𝑖]∗(𝑖−1)!+...+𝑎[1]∗0!
int contor(int *a,int n)
{
    int num = 0;
    for(int i=0; i<n; ++i)
    {
        int cnt = 0;
        for(int j=i+1;j<n;++j)
            if(a[i]>a[j])
                ++cnt;

        num += cnt*factor[n-i-1];
    }

    return num+1;
}

