#include <iostream>
#include <cstring>

using namespace std;

int T,M;
int f[1002];

void zeroOnePack(int weight,int value)
{
    for(int i=T; i>=weight; --i)
        f[i] = max(f[i], f[i-weight]+value);
}

void completePack(int weight,int value)
{
    for(int i=weight; i<=T; ++i)
        f[i] = max(f[i], f[i-weight]+value);
}

void multiplePack(int weight,int value,int amount)
{
    if(weight*amount>=T)
    {
        completePack(weight, value);
        return;
    }

    int k=1;
    while(k<amount)
    {
        zeroOnePack(weight*k,value*k);
        amount-=k;
        k*=2;
    }
    zeroOnePack(weight*amount, value*amount);

}