#include<bits/stdc++.h>
using namespace std;
const int N=2000;
int maze[N][N];
int visited[N][N];
int n,m;

int dx[]= {0,0,-1,1};
int dy[]= {1,-1,0,0};


pair<int,int>find_unvisited();
void  bfs(pair<int,int>src);
bool is_safe(pair<int,int>cordn);
bool is_inside(pair<int,int>cordn);



bool is_safe(pair<int,int>cordn)
{
    int x=cordn.first;
    int y=cordn.second;
    if(maze[x][y]==-1)
    {
        return false;
    }
    return true;
}
bool is_inside(pair<int,int>cordn)
{
    int x=cordn.first;
    int y=cordn.second;
    if(x>=0&&x<n&&y>=0&&y<m)
    {
        return true;
    }
    return false;
}





void  bfs(pair<int,int>src)
{
    queue<pair<int,int>>q;
    visited[src.first][src.second]=1;
    q.push(src);
    while(!q.empty())
    {
        pair<int,int>head;
        head=q.front();
        q.pop();
        int x=head.first;
        int y=head.second;
        for(int i=0; i<4; i++)
        {
            int new_x=x+dx[i];
            int new_y=y+dy[i];
            pair<int,int>adj_node= {new_x,new_y};
            if(is_inside(adj_node) && is_safe(adj_node) && visited[new_x][new_y]==0)
            {
                visited[new_x][new_y]=1;
                q.push(adj_node);
            }
        }
    }
}


pair<int,int>find_unvisited()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(visited[i][j]==0 && maze[i][j]==0)
            {
                return{i,j};
            }
        }
    }
    return{-1,-1};
}

int main()
{
    int room_cont=0;
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        string str;
        cin>>str;
        for(int j=0; j<m; j++)
        {
            if(str[j] == '#')
            {
                maze[i][j]=-1;
            }
        }
    }


    while(true)
    {
        pair<int,int>visit_position=find_unvisited();
        if(visit_position == pair<int,int>(-1,-1))
        {
            break;
        }
        bfs(visit_position);
        room_cont++;
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout<<maze[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<endl;
    cout<<room_cont;

    return 0;
}
