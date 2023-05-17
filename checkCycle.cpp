#include<bits/stdc++.h>
using namespace std;



bool checkCycleBfs(int start,vector<int> adjList[],vector<bool> &visited)
{
  queue<pair<int,int>>q;
  q.push({start,-1});
  visited[start] = 1;
  while(!q.empty())
  {
    int node = q.front().first;
    int parent = q.front().second;
    q.pop();
    for(auto it : adjList[node])
    {
        if(!visited[it])
        {
            q.push({it,node});
        visited[it] = 1;
        }
        else {
               if(it != parent)
               return true;
        }
    }
  }
 
return false;

}


bool checkCycleDfs(int start, vector<int> adjList[], vector<bool> visited,int parent)
{
    visited[start] = true;
    for(auto it : adjList[start])
    {
        if(!visited[it])
         {
            if(checkCycleDfs(it,adjList, visited,start)) return true;
         }
        else if(it != parent)return true;
        
    }
    return false;
}

bool checkCycle(vector<bool> &visited,vector<int> adjList[],int n)
{
for(int i = 1 ; i <= n;i++)
if(!visited[i])
{
 if(checkCycleDfs(i,adjList,visited, -1)) return true;
}
 return false;
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

vector<bool> visited(n+1);
vector<int> ans;


 cout << checkCycle(visited,adjList,n) ;



    return 0;
}