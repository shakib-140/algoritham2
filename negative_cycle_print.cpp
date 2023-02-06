
/*



4 5
1 2 1
2 4 1
3 1 1
4 1 -3
4 3 -2


*/
#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
const long long INF=1e18;
long long d[N];
vector<pair<int,int>>adj_list[N];
int parent[N];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        d[n]=INF;
    }
    for(int i=1; i<=m; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        adj_list[a].push_back({b,c});
    }
    bool negative_cycle=false;
    int lastupdate_node=-1;
    for(int i=1; i<=n; i++)
    {
        for(int node=1; node<=n; node++)
        {
            for(pair<int,int>adj_node:adj_list[node])
            {
                int u=node;
                int v=adj_node.first;
                int w=adj_node.second;
                if(d[u]+w<d[v])
                {
                    d[v]=d[u]+w;
                    parent[v]=u;
                    if(n==i)
                    {
                        lastupdate_node=v;
                        negative_cycle=true;
                    }
                }
            }
        }
    }
    if(negative_cycle==true)
    {
        cout<<"yes"<<endl;
        int selected_node=lastupdate_node;
        for(int i=1; i<=n-1; i++)
        {
            selected_node=parent[selected_node];
        }
        int first_node=selected_node;
        vector<int>cycle;
        cycle.push_back(selected_node);
        while(true)
        {
            selected_node=parent[selected_node];
            cycle.push_back(selected_node);
            if(selected_node==first_node)
            {
                break;
            }

        }
        reverse(cycle.begin(),cycle.end());
        for(int node:cycle)
        {
            cout<<node<<" ";
        }
        cout<<endl;

    }
    else
        cout<<"no"<<endl;
    return 0;
}

