#include<bits/stdc++.h>
using namespace std;
const int N=2002;
int maze[N][N];
int visited[N][N];
int level[N][N];
int n,m;
int dx[]= {0,0,-1,1};
int dy[]= {1,-1,0,0};
void  bfs(pair<int,int>src);
bool is_inside(pair<int,int>cordn);
bool is_safe(pair<int,int>cordn);


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
    level[src.first][src.second]=0;
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
                level[new_x][new_y]=level[x][y]+1;
                q.push(adj_node);
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    pair<int,int>src,dst;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            visited[i][j]=-1;
        }
    }

    for(int i=0; i<n; i++)
    {
        string input;
        cin>>input;
        for(int j=0; j<m; j++)
        {
            if(input[j]=='#')
            {
                maze[i][j]=-1;
            }
            else if(input[j]=='A')
            {
                src= {i,j};
            }
            else if(input[j]=='B')
            {
                dst= {i,j};
            }
        }
    }


    bfs(src);

//    for(int i=0; i<n; i++)
//    {
//        for(int j=0; j<m; j++)
//        {
//            cout<<maze[i][j]<<"\t";
//        }
//        cout<<endl;
//    }
    cout<<endl;
    if(level[dst.first][dst.second]==-1)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
        cout<<level[dst.first][dst.second]<<endl;
    }
    return 0;
}








/*



5 8
########
#.A#...#
#.##.#B#
#......#
########








*/

