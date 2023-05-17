#include <bits/stdc++.h>
using namespace std;

bool bipartiteBfs(int start, vector<int> & visited,vector<int> grid[]){
     queue<int> q;
     q.push(start);
     visited[start] = 0;
     while(!q.empty())
     {
          int temp = q.front();
          q.pop();

          for(auto it : grid[temp])
          {
            if(visited[it] == -1)
            {
            visited[it] = !visited[temp];
            q.push(it);
            }
            else if(visited[it] == visited[temp])
            return false;
          }
     } return true;
}

bool bipartiteDfs(int start,int color, vector<int> visited, vector<int> grid[])
{
    visited[start] = color;
    for(auto it : grid[start])
    {
        if(visited[it] == -1)
        {
          if(!bipartiteDfs(it,!color,visited,grid)) return false;
        }
        else if(visited[it] == visited[start])
        return false;
    }
    return true;
}

bool check(int n, vector<int> &visited,vector<int> grid[])
{
for(int i = 1 ; i <= n;i++)
{
    if(visited[i] == -1)
{
    if(!bipartiteDfs(i,0,visited,grid))
    {
        return false;
    }
}
}
return true;
}

int main()
{
    int n, m;

    cout << "Enter no of vertices: ";
    cin >> n;
    cout << "Enter no of edges: ";
    cin >> m;
    vector<int> adjList[n+1];
    for(int i = 0 ; i < m; i++)
    {
        int u ,  v;
        cin >> u >> v;
       adjList[u].push_back(v);
       adjList[v].push_back(u);
    }

vector<int> visited(n+1,-1);
vector<int> ans;


cout << check(n,visited,adjList);


    return 0;
}