#include<bits/stdc++.h>
using namespace std;
const int N=2000;
int visited[N];
int colour[N];

vector<int>adj_list[N];
bool dfs(int node)
{
    visited[node]=1;
    for(int adj_node:adj_list[node])
    {
        if(visited[adj_node]==0)
        {
            if(colour[node]==1)
            {
                colour[adj_node]=2;
            }
            else
            {
                colour[adj_node]=1;
            }

            bool is_bicolourable= dfs(adj_node);
            if(! is_bicolourable)
            {
                return false;
            }
        }


        else
        {
            if(colour[node]==colour[adj_node]) return false;
        }
    }
    return true;
}
int main()
{
    int nodes,edges;
    cin>>nodes>>edges;
    for(int i=0; i<edges; i++)
    {
        int u,v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    bool is_bicolourable2=true;
    for(int i=1; i<=nodes; i++)
    {
        if(visited[i]==0)
        {
            colour[i]=1;
            bool is_ok=dfs(i);
            if(!is_ok)
            {
                is_bicolourable2=false;
                break;
            }
        }
    }
    if(!is_bicolourable2)
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else
    {
        for(int i=1; i<=nodes; i++)
        {
            cout<<colour[i]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    return 0;
}

/*

5 3
1 2
1 3
4 5

*/
