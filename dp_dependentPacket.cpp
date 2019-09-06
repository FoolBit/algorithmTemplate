#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

#define MAXM 70

struct Node
{
    int cost,value;
    Node(int cost_, int value_):cost(cost_),value(value_){};
};

struct Goods
{
    int cost,value;
    vector<Node> attach;
    int total;
    int notAttach=0;

    void set(int cost_, int value_)
    {
        cost = cost_;value=value_;
        total = 0;
        notAttach = 1;
    }

    void addAttach(int c, int v)
    {
        total += c;
        attach.push_back(Node(c,v));
    }
} goods[MAXM];

struct Group
{
    vector<Node> items;
    int minCost = 0x3f3f3f3f;

    void addItem(int cost, int value)
    {
        minCost = min(cost, minCost);
        items.push_back(Node(cost, value));
    }

} group[MAXM];
int ngroup;
int N,m;
int f[32002];

void init()
{
    cin >> N >> m;

    int v,p,q;
    for(int i=1; i<=m; ++i)
    {
        cin >> v >> p >> q;
        if(q)
        {
            goods[q].addAttach(v, p*v);
        }
        else
        {
            goods[i].set(v, p*v);
        }
    }
}

void preProcess()
{
    memset(f,-0x3f3f3f3f,sizeof(f));
    f[0] = 0;
    int cost,value;
    for(int i=1; i<=m; ++i)
    {
        if(goods[i].notAttach)
        {
            ++ngroup;
            group[ngroup].addItem(goods[i].cost, goods[i].value);


            for(auto iter = goods[i].attach.begin(); iter!=goods[i].attach.end();++iter)
            {
                cost = iter->cost;
                value = iter->value;
                for(int j=goods[i].total; j>=cost; --j)
                {
                    f[j] = max(f[j], f[j-cost] + value);
                }
            }

            for(int j=1; j<=goods[i].total; ++j)
            {
                if(f[j]>=0)
                {
                    group[ngroup].addItem(j+goods[i].cost, f[j]+goods[i].value);
                }
                f[j] = -0x3f3f3f3f;
            }

        }
    }
}

void groupPack()
{
    memset(f,0,sizeof(f));
    int cost,value;
    for(int i=1; i<=ngroup; ++i)
    {
        for(int j=N;j>=group[i].minCost; --j)
        {
            for(auto iter = group[i].items.begin();iter!=group[i].items.end();++iter)
            {
                cost = iter->cost;
                value = iter->value;
                if(cost > j)
                    continue;
                f[j] = max(f[j], f[j-cost]+value);
            }
        }
    }
    cout << f[N];
}

int main()
{
    init();
    preProcess();
    groupPack();
}