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


vector<int> dijsktra(vector<vector<pair<int,int>>> graph,int start, int n){
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
      vector<int> weight(n+1,100);
      pq.push({0,start});
      weight[start] = 0;
      weight [start] = 0;
      while(!pq.empty()){
        int wt = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto it : graph[node]){
            int edw = it.second;
            int adjNode = it.first;
            if(wt + edw < weight[adjNode])
            {
                weight[adjNode] = wt + edw;
                pq.push({wt+edw,adjNode});
            }
        }
      }
     return weight;
}

void print(vector<int> ans){
    for(auto it : ans)
    {
        cout << it << " ";
    }
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

print(dijsktra(graph,1,n));


   
    return 0;
}