#include<bits/stdc++.h>

using namespace std;

int findParent(int u,vector<int>&parent)
{
    if(u==parent[u]) return u;

    return parent[u]=findParent(parent[u],parent);
}

void union_find(int u,int v,vector<int>&parent,vector<int>&rank)
{
    int pu=findParent(u,parent);
    int pv=findParent(v,parent);

    int ru=rank[pu];
    int rv=rank[pv];

    if(ru==rv) return;

    if(ru==rv) 
    {
        parent[pu]=pv;
        rank[pv]++;
    }

    else if(ru<rv)
    {
        parent[pu]=pv;
    }

    else parent[pv]=pu;

}



int main()
{
    int n;
    cin>>n;

    vector<int>p(n),r(n,0);

    for(int i=0;i<n;i++)
    {
        p[i]=i;
    }

    union_find(1,2,p,r);
    union_find(2,3,p,r);
    
    union_find(4,5,p,r);

    union_find(6,7,p,r);
    union_find(4,7,p,r);
    union_find(7,8,p,r);
    union_find(5,8,p,r);

    for(int i=0;i<n;i++)
    {
        cout<<i<<" -> "<<p[i]<<" -> "<<r[i]<<endl;
    }   


    return 0;
}