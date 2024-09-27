#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e5 + 1;
int parent[N];
int group_size[N];

void dsu_initialize(int n)
{
for (int i = 0; i < n; i++)
{
parent[i] = -1;
group_size[i] = 1;
}
}

int dsu_find(int node)
{
if (parent[node] == -1)
return node;
int leader = dsu_find(parent[node]);
parent[node] = leader;
return leader;
}

void dsu_union_by_size(int node1, int node2)
{
int leaderA = dsu_find(node1);
int leaderB = dsu_find(node2);
if (group_size[leaderA] > group_size[leaderB])
{
parent[leaderB] = leaderA;
group_size[leaderA] += group_size[leaderB];
}
else
{
parent[leaderA] = leaderB;
group_size[leaderB] += group_size[leaderA];
}
}

class Edge
{
public:
int u, v;
ll w;
Edge(int u, int v, ll w)
{
this->u = u;
this->v = v;
this->w = w;
}
};


bool cmp(Edge a, Edge b)
{
return a.w < b.w;
}
int main()
{
int n,e;
cin>>n>>e;
int ed_num=e;
dsu_initialize(n);
vector<Edge>vec;
set<int>st;
int u,v;
ll w;
while(e--){
cin>>u>>v>>w;
vec.push_back(Edge(u,v,w));
vec.push_back(Edge(v,u,w));
st.insert(u);
st.insert(v);
}
sort(vec.begin(),vec.end(),cmp);
ll totalCost=0,accessible=0;
for(Edge ed:vec)
{
    int leaderU=dsu_find(ed.u);
    int leaderV=dsu_find(ed.v);
    if(leaderU==leaderV) continue;
    else
    {
        dsu_union_by_size(ed.u,ed.v);
        totalCost+=ed.w;
        accessible++;
    }
}
if(st.size()!=n) cout<<"Not Possible"<<endl;
else cout<<ed_num-accessible<<" "<<totalCost<<endl;
return 0;
}

