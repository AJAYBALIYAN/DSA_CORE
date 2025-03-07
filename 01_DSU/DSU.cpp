#include<bits/stdc++.h>

using namespace std;

class DSU{

    vector<int>rank,parent;

public: 

        DSU(int n)
        {
            rank.resize(n,0);
            parent.resize(n);

            for(int i=0 ; i<n ; i++)
            {
                parent[i]=i;
            }
        }


        int findParent(int u)
        {
            if(u==parent[u]) return u;

            return parent[u]=findParent(parent[u]);
        }


        void union_find(int u,int v)
        {
            int pu=findParent(u);
            int pv=findParent(v);

            int ru=rank[pu];
            int rv=rank[pv];

            if(pu==pv) return; // dont increase the rank if they have same parent

            if(ru==rv) 
            {
                parent[pv]=pu;
                rank[pu]++;
            }

            else if(ru<rv)
            {
                parent[pu]=pv;
            }

            else parent[pv]=pu;

        }

        void check(int u, int v)
        {
            int pu=findParent(u);
            int pv=findParent(v);

            if(pu==pv) cout<<u<<" and "<<v<<" are in same set"<<endl;
            else cout<<u<<" and "<<v<<" are in different set"<<endl;
        }

        void printSets() {
            cout << "Element -> Parent -> Rank" << endl;
            for (size_t i = 0; i < parent.size(); i++) {
                cout << i << " -> " << parent[i] << " -> " << rank[i] << endl;
            }
        }
};


int main()
{
    int n;
    // cin>>n;
    n=9;

    DSU dsu(n);

    dsu.union_find(1,2);
    dsu.union_find(2,3);
    
    dsu.union_find(4,5);

    dsu.check(2,5);

    dsu.union_find(6,7);
    dsu.union_find(4,7);

    dsu.check(2,5);

    dsu.union_find(7,8);
    dsu.union_find(5,8);

    dsu.printSets();

    return 0;
}