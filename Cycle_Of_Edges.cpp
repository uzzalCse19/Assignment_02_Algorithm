
#include <bits/stdc++.h>
using namespace std;
const int N=1e6+1;
vector<int> v[N];
  int parentArray[N];
  bool vis[N];
  int sum=0;
  void cycle_detection(int parent)
  {
    vis[parent]=true;
    //bool cycle=false;
    for(int child:v[parent])
    {
          if(vis[child]==true && parentArray[parent]!=child)
          {
            sum++;
          }
          if(vis[child]==false)
          {
            parentArray[child]=parent;
            cycle_detection(child);
          }
    }
   

  }
int main()
{
    // Write your code here
    int n,e;
    cin>>n>>e;
    int b,c;
    while(e--)
    {
cin>>b>>c;
v[b].push_back(c);
v[c].push_back(b);
    }
    memset(vis,false,sizeof(vis));
      memset(parentArray,-1,sizeof(parentArray));
      cycle_detection(1);
    cout<<sum/2<<endl;
    return 0;
}