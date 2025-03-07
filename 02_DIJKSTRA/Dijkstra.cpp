#include<bits/stdc++.h>

using namespace std;

void add_edge(int u,int v, int w , vector<vector<pair<int,int>>>&adj)
{
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
}

void print_adj(vector<vector<pair<int,int>>>&adj)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Node " << i << ": ";
        for (auto j : adj[i])
        {
            cout << "{ "<<j.first<<" , "<<j.second <<" }"<<" ";
        }
        cout << endl;
    }

}

vector<int>dijk(int s,int n,vector<vector<pair<int,int>>>&adj)
{
    vector<int>dist(n,INT_MAX);
    dist[s]=0;

    priority_queue<pair<int,int>,vector<pair<int,int>> , greater<pair<int,int>>>pq; //{dist,node}

    pq.push({0,s});

    while(!pq.empty())
    {
        int c_n=pq.top().second;
        int c_d=pq.top().first;

        pq.pop();

        for(auto i:adj[c_n])
        {
            int i_n=i.first;
            int i_d=i.second;

            if(dist[i_n]>c_d+i_d)
            {
                dist[i_n]=c_d+i_d;
                pq.push({dist[i_n],i_n});
            }
        }
    }

    return dist;
}

int main()
{
    int n=7;

    vector<vector<pair<int,int>>>adj(n);

    add_edge(0,2,1,adj);
    add_edge(1,2,1,adj);
    add_edge(2,3,1,adj);
    add_edge(3,4,1,adj);
    add_edge(4,5,1,adj);
    add_edge(5,6,1,adj);
    add_edge(1,6,1,adj);
    add_edge(4,6,1,adj);

    vector<int>di=dijk(0,n,adj);

    for(int i=0 ; i<n ; i++)
    {
        cout << "Distance from node 0 to " << i << ": " << di[i] << endl;
    }

}