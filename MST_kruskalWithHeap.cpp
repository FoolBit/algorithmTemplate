#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

#define N 5002
#define M 200002

struct Node
{
    int u,v,w;
    Node(){};
    Node(int u_,int v_, int w_):u(u_),v(v_),w(w_){};

    bool operator < (const Node& a) const
    {
        return w > a.w;
    }
};

priority_queue<Node> q;

int f[N];
int find(int x)
{
    if(x == f[x])
        return x;
    f[x] = find(f[x]);
    return f[x];
}

int n,m;

int kruskal()
{
    for(int i=1; i<=n; ++i)
        f[i] = i;

    Node tmp;

    int ans=0;
    for(int i=1; i<n; ++i)
    {
        int flag=1;
        while(q.size())
        {
            tmp = q.top();
            q.pop();

            int u = tmp.u;
            int v = tmp.v;
            int fx = find(u);
            int fy = find(v);
            if(fx == fy)
                continue;
            f[fx] = fy;
            flag = 0;
            break;
        }
        if(flag)
            return -1;

        ans += tmp.w;
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(0);

    //freopen("testdata.in","r",stdin);

    cin >> n >> m;
    for(int i=0; i<m; ++i)
    {
        int x,y,z;
        cin >> x >> y >> z;
        q.push(Node(x,y,z));
    }

    int ans = kruskal();
    if(ans == -1)
        cout << "orz";
    else
        cout << ans;
}
