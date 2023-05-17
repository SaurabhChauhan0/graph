#include<iostream>
#include<vector> 
#include<queue>
using namespace std;


void printGraph(vector<vector<pair<int,int>>> graph)
{
    for(int i = 0; i < graph.size(); i++){
        cout << i << " --> ";

        for(auto it : graph[i])
        {
            cout << it.first <<" " <<  it.second << " | ";
        }
            cout << endl;
    }
}


int prim(vector<vector<pair<int,int>>> graph,int n){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> vis(n+1,0);
    pq.push({0,1});
    int sum = 0;
    while(!pq.empty()){
         int node = pq.top().second;
         int weight = pq.top().first;
         pq.pop();
         if(!vis[node]){
            vis[node] = 1;
            sum += weight;
            for(auto it : graph[node])
            {
                int adjNode = it.first;
                int wt  = it.second;
                if(!vis[adjNode]){
                    pq.push({wt,adjNode});
                }
            }
         }

    }
    return sum;
}

int main(){
 

 int n; int m;
 cout << "Enter no of vertices: ";
 cin >> n;
 cout << "Enter no of edges: ";
 cin >> m;

 vector<vector<pair<int,int>>> graph(n+1);

    int x, y , wt;
 for(int i = 0; i < m; i ++){
    cin >> x >> y >> wt;
    
    
    graph[x].push_back({y,wt});
    graph[y].push_back({x,wt});

 }

printGraph(graph);  

cout << prim(graph,6);

   
    return 0;
}