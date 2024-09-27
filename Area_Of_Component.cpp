#include <bits/stdc++.h>
using namespace std;
bool vis[1001][1001];
int ans=INT_MAX;
bool test=false;
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;
char a[1001][1001];
bool valid(int i, int j)
{
  if(i>=0 && j>=0 && i<n && j<m && a[i][j]=='.') return true;
     return false;
}


void bfs(int si, int sj)
{
 queue<pair<int, int>> q;
 q.push({si, sj});
 int area=0;
 test=true;
 while (!q.empty())
 {
pair<int, int> par = q.front();
 int a = par.first, b = par.second;
 q.pop();
 
 for (int i = 0; i < 4; i++)
 {
 int ci = a + d[i].first;
 int cj = b + d[i].second;
 if (valid(ci, cj) == true && vis[ci][cj] == false)
{
   
 q.push({ci, cj});
 vis[ci][cj] = true;
area++;
 }
 }
 }
ans=min(area,ans);
}
int main()
{
    cin>>n>>m;
  vector<pair<int,int>>source;
for (int i = 0; i < n; i++)
 {
 for (int j = 0; j < m; j++)
{
 cin >> a[i][j];
 if(a[i][j]=='.') source.push_back({i,j});
 }
 }

  memset(vis, false, sizeof(vis));
 for(int i=0;i<source.size();i++){
 if(vis[source[i].first][source[i].second]==false){
  bfs(source[i].first,source[i].second);
 }
}
if(test) 
{
    if(ans==0) cout<<"1"<<endl;
    else cout<<ans<<endl;
}
else cout<<"-1"<<endl;
 return 0;
}

