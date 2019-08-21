#include <iostream>
using namespace std;
#define N 10000

int notPrime[N] = {0};
int nprime = 0, prime[N] = {0};

void sieve()
{
    notPrime[0] = 1;notPrime[1] = 1;
    for(int i=2; i<N; ++i)
    {
        if(!notPrime[i])
            prime[nprime++] = i;
        for(int j=0; j<nprime; ++j)
        {
            if(i * prime[j] >=N)
                break;
            notPrime[i * prime[j]] = 1;
            if(i % prime[j] == 0)
                break;
        }
    }
}

int main()
{
    sieve();
    for(int i=0; i<nprime; ++i)
        cout << prime[i] << endl;
}