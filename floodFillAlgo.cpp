#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &grid, int sr, int sc, int newColor, 
vector<vector<bool>> &visited,vector<vector<int>> &ans,int row[], int col[],
int initialColor)
{
     int n = grid.size();
  int m = grid[0].size();
queue<pair<int,int>> q;
  q.push({sr,sc});
  visited[sr][sc] = 1;
  ans[sr][sc] = newColor;
  while(!q.empty())
  {
    int row1 = q.front().first;
    int col1 = q.front().second;
    q.pop();
    for(int i = 0; i < 4; i++)
    {
        int newrow = row1 + row[i];
        int newcol = col1 + col[i];

        if(newrow >= 0 and newcol >= 0 and newrow < n and newcol < m and grid[newrow][newcol] == initialColor
        and !visited[newrow][newcol])
        {
            q.push({newrow,newcol});
            visited[newrow][newcol] = 1;
            ans[newrow][newcol] = newColor;
        }
    }
}
}

vector<vector<int>> floodFill(vector<vector<int>> &grid, int sr, int sc, int newColor)
{
       int n = grid.size();
       int m = grid[0].size();
    vector<vector<bool>> visited(n,vector<bool>(m,0));
    vector<vector<int>> ans = grid;
    int initialColor  = grid[sr][sc];
    int row[] = {-1,0,1,0};
    int col[] = {0,1,0,-1};
  for(int i = 0; i < n; i++)
   for(int j = 0; j < m; j++)
   {
     if(!visited[i][j] && grid[i][j] == initialColor)
      bfs(grid,sr,sc,newColor,visited,ans,row,col,initialColor);
   }
  
  

return ans;
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


vector<vector<int>> ans = floodFill(grid,2,0,3);
for(auto it :ans)
 {
    for(auto it1 : it)
      cout << it1 << " "; 
    cout << endl;
 }




return 0; 
}