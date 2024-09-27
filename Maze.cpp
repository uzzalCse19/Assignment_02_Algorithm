#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
bool vis[N][N];
int dx[4] = {0, 0, -1, 1}; 
int dy[4] = {1, -1, 0, 0}; 
map<pair<int, int>, pair<int, int>> par;

int n, m;

char graph[N][N];


bool valid(int ci, int cj)
{

    if (ci >= 0 && ci < n && cj >= 0 && cj < m && (graph[ci][cj]=='.' || graph[ci][cj]=='D'))
    {
        return true;
    }
    else
        return false;
}

void bfs(int si, int sj)
{
    vis[si][sj] = true;

    queue<pair<int, int>> q;
    q.push({si, sj});

    while (!q.empty())
    {
        pair<int, int> node = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ci = node.first + dx[i];
            int cj = node.second + dy[i];

            if (valid(ci, cj) && !vis[ci][cj])
            {
                vis[ci][cj] = true;
                q.push({ci, cj});
                par[{ci, cj}] = {node.first, node.second};
            }
        }
    }
}

int main()
{

    cin >> n >> m;
 int si,sj,di,dj;
    memset(vis, false, sizeof(vis));

    for (int i= 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
            if(graph[i][j]=='R'){
             si=i,sj=j;
            }
            if(graph[i][j]=='D') {
            di=i,dj=j;
            }
        }
    }
    bfs(si, sj);
    //cout<<endl<<endl;
    if(vis[di][dj]==false)
    {
        for (int i = 0; i < n; i++)
       {
        for (int j = 0; j < m; j++)
        {
            cout << graph[i][j];
        }
        cout << endl;
    }
     return 0;
    }

    int sti = di,stj=dj;
    while(graph[sti][stj]!='R')
    {
        graph[sti][stj]='X';
        pair<int,int>nextNode=par[{sti,stj}];
        sti=nextNode.first;
        stj=nextNode.second;
    }
    //cout<<endl<<endl;
    graph[di][dj]='D';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << graph[i][j];
        }
        cout << endl;
    }

    cout << endl;
}