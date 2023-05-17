#include<bits/stdc++.h>
using namespace std;


void topologicalDFS(int start,vector<vector<int>> graph,vector<bool> &visited, vector<int> &ans){
visited[start] = 1;
for(auto it : graph[start]){
    if(!visited[it]){
        topologicalDFS(it,graph,visited,ans);
    }
}
        ans.push_back(start);
}


// Topological Sort using BFS

void kahnsAlgo(vector<vector<int>> graph,vector<int> &indegree,vector<int> &ans){
    queue<int> q;
    for(int i = 1; i <= indegree.size(); i++){
        if(indegree[i] == 0) 
        q.push(i);
    }
    while(!q.empty()){
        int temp = q.front(); 
        q.pop();
        ans.push_back(temp);
        for(auto it : graph[temp])
        {
            indegree[it]--;
            if(indegree[it] == 0)
            q.push(it);
        }
        
    }

}









 main(){
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
    //  topologicalDFS(1,graph,visited,ans);
    //  ans.push_back(1);
    //  reverse(ans.begin(),ans.end());

   kahnsAlgo(graph,indegree,ans);
for(auto it : indegree) cout << it << " ";

    
}