#include<bits/stdc++.h>
using namespace std;


bool checkCycle(int start,vector<vector<int>> graph,vector<bool>&visited,vector<bool>&pathVisited){
   visited[start] = 1;
   pathVisited[start] = 1;

    for(auto it:graph[start])
     {
        if(!visited[it])
    {
        if(checkCycle(it,graph,visited,pathVisited)) return true;
    }
    else if(pathVisited[it]) return true;
     }
   
        pathVisited[start] = 0;

 return false;
}







int main(){
  
 int n,m;
    cout << "Enter no of vertices: ";
    cin >> n;
    cout << "Enter no of Edges: ";
    cin >> m;
    vector<vector<int>> graph(n+1);
    vector<int> indegree(n+1,0);
     int u,v;
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        indegree[v]++;
    }

    for(auto it : graph){
        for(auto it1 : it)
        {
            cout << it1 << " ";
        }
        cout << endl;
    }

     vector<bool> visited(n+1,0);
     vector<int> ans;
     vector<bool>pathVisited(n+1,0);

// for(int i = 1; i <= n; i++){
//     if(!visited[i]); }
    cout << checkCycle(1, graph, visited,pathVisited);






    return 0;
}