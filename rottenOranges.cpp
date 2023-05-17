#include<bits/stdc++.h>
using namespace std;

int rottenOranges(vector<vector<int>> grid,vector<vector<bool>> &visited){
    int n = grid.size();
    int m = grid[0].size();
    int count = 0;
    int row[] = {0,1,-1,0};
    int col[] = {1,0,0,-1};
    queue<pair<int,int>>q;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(grid[i][j] == 2)
            {
                q.push({i,j});
                visited[i][j] = 1;
            }
        }
    }
    while(!q.empty())
    {
        int size = q.size();
        for(int i = 0; i < size; i++)
        {if(i == 0) count++;
             int trow = q.front().first;
             int tcol = q.front().second;
             q.pop();
             for(int j = 0 ; j < 4; j++)
             {
                   int nrow = trow + row[j];
                   int ncol = tcol + col[j];
                   if(nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and grid[nrow][ncol] == 1 and visited[nrow][ncol]
                   == 0){
                    q.push({nrow,ncol});
                    visited[nrow][ncol] =  true;
                   }
             }
        }
    } return count - 1;

}




int main(){
    



    int n , m;
  cout << "Enter no of rows : ";
  cin >> n;
  cout << "Enter no of columns : ";
  cin >> m;
  vector<vector<int>> grid;
  for(int i = 0; i < n; i++)
  {
  vector<int> v;
  
   for(int j = 0; j < m; j++)
   {
    int x; 
    cout << "Enter the value : ";
    cin >> x;
    v.push_back(x);
   }
   grid.push_back(v);
  }


vector<vector<bool>> visited(n,vector<bool>(m,0));
for(auto it : grid)
 {
    for(auto it1 : it)
      cout << it1 << " "; 
    cout << endl;
 }

cout << endl;

cout << rottenOranges(grid,visited);



return 0; 
}
