#include <bits/stdc++.h>
using namespace std;


void dfs(int start,vector<bool> &visited, vector<int> adjList[],vector<int> &ans)
{

visited[start] = true;
ans.push_back(start);
for(auto it : adjList[start])
{
    if(!visited[it])
    {
      dfs(it,visited,adjList,ans);
    }
}

}


void bfs(int start, vector<bool> &visited, vector<int> adjList[], vector<int> &ans){

    queue<int>q;
    q.push(start);

    while(!q.empty())
    {
       int temp = q.front();
       q.pop();
       visited[temp] = 1;
       ans.push_back(temp);
       for(auto it : adjList[temp])
       {
        if(!visited[it])
        q.push(it);
       }

    }

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



for(int i = 1 ; i <= n;i++)
if(!visited[i])
bfs(1,visited,adjList,ans);


for(auto it : ans)
cout << it << " ";


    return 0;
}