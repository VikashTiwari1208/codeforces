#include<bits/stdc++.h>
using namespace std;

int maxi=1,maxi2=1;
int ans=0;
int n;
unordered_map<int,vector<int>>adj;
vector<int> vis;
vector<int>w;
void dfs(int src,int par)
{
    maxi=max(maxi,maxi2);
    maxi2=1;
    cout<<maxi<<" ";
    if(w[src]!=0)
    {
        maxi=maxi*w[src];
    }
    vis[src]=1;
    ans=max(ans,maxi);
    for(auto x:adj[src])
    {
        if(x!=par&&vis[x]!=-1)
        {
            dfs(x,src);
        }
    }
    if(src!=0)
    {
        maxi=maxi/src;
        maxi2*=src;
    }
}
int main()
{
    int n;
    cin>>n;
    w.resize(n+1);
    vis.resize(n+1,-1);
    for(int i=1;i<=n;i++)
    {
        cin>>w[i];
    }
    int e,m;
    cin>>e>>m;
    for(int i=1;i<=e;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,-1);
    cout<<ans<<endl;
}
