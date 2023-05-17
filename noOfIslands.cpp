#include<bits/stdc++.h>
using namespace std;


void bfs(int row, int col, vector<vector<int>> grid, vector<vector<bool>> &visited){

 int n = grid.size();
    int m = grid[0].size();
 visited[row][col] = 1;
 queue<pair<int,int>> q;
 q.push({row,col});
 while(!q.empty())
 {
    int row = q.front().first;
    int col = q.front().second;
    q.pop();

    for(int i = -1; i <= 1; i++)
     for(int j = -1; j <= 1; j++)
     {
        int nrow = row + i;
        int ncol = col + j;
        if(nrow >=0 && ncol >= 0 && nrow < n && ncol < m && visited[nrow][ncol] == 0
        &&  grid[nrow][ncol] == 1)
        {
            visited[nrow][ncol] = 1;
            q.push({nrow, ncol});
        }
     }
 }


}

int noOfIslands(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
vector<vector<bool>> visited(n,vector<bool>(m,0));
int count = 0;
for(int i = 0; i < n; i++)
{
    for(int j = 0; j < m; j++)
    {
        if(!visited[i][j] and grid[i][j] == 1)
        {
        count ++;
        bfs(i,j,grid,visited);

        }
    }
};
    return count;
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


for(auto it : grid)
 {
    for(auto it1 : it)
      cout << it1 << " "; 
    cout << endl;
 }

cout << endl;

cout << noOfIslands(grid);




return 0; 
}
