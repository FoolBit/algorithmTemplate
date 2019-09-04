#include<string>
#include<iostream>

using namespace std;
int p[1000002];
int main()
{
    string a,b;
    cin>>a>>b;
    int n=a.length(),m=b.length();

    p[0] = -1;
    int j=-1;
    for(int i=1;i<m;++i)
    {
        while(j>=0&&b[j+1]!=b[i])
            j=p[j];

        if(b[j+1]==b[i])j++;
        p[i]=j;
    }

    j=-1;
    for(int i=0;i<n;++i)
    {
        while(j>=0&&b[j+1]!=a[i])
            j=p[j];
        if(b[j+1]==a[i])j++;
        if(j+1==m)
        {
            cout << i-m+1+1 << endl;
        }
    }

    cout << p[0]+1;
    for(int i=1; i<m; ++i)
        cout << ' ' << p[i]+1;

    return 0;
}