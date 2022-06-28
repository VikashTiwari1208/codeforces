#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define M 1000000007LL
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

long long binpow(long long base, long long exp, int mod)
{
   long long res = 1;
   while (exp > 0)
   {
      if (exp % 2 == 1)
         res = (res * base) % mod;
      exp = exp >> 1;
      base = (base * base) % mod;
   }
   return res;
}

long long mod(long long x)
{
   return ((x % M + M) % M);
}

long long add(long long a, long long b)
{
   return mod(mod(a) + mod(b));
}

long long mul(long long a, long long b)
{
   return mod(mod(a) * mod(b));
}
bool isPrime(int n) 
{ 
    // Corner case 
    if (n <= 1) 
        return false; 
  
    // Check from 2 to n-1 
    for (int i = 2; i*i<= n; i++) 
        if (n % i == 0) 
            return false; 
  
    return true; 
} 
ll n,m;
ll k;
vector<vector<bool>>vis;
vector<vector<char>>maze;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
bool IsSafe(int x,int y)
{
       if(x>=1 && x<=n && y>=1 && y<=m && maze[x][y]=='.'&&vis[x][y]==false)
              return true;
       return false;
}
void dfs(int x,int y)
{
 for(int i=0;i<4;i++)
       {
              int newx=x+dx[i];
              int newy=y+dy[i];
              if(IsSafe(newx,newy))
              {
                    vis[newx][newy]=true;
                     dfs(newx,newy);
              }
       }
}
int main()
{
    fast;
    cin>>n>>m>>k;
    vis.resize(n+1);
    maze.resize(n+1);
    for(int i=1;i<=n;i++)
    {
        maze[i].resize(m+1);
        vis[i].resize(m+1,false);
    }
    for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                cin>>maze[i][j];
            }
        }
  for(int i=1; i<=n; i++) 
  {
    for(int j=1; j<=m; j++) 
     {
         if(k>0&&vis[i][j]==false&&maze[i][j]=='.')
         {
             vis[i][j]=true;
             dfs(i,j); 
         }   
     } 
  }
         for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                cout<<maze[i][j];
            }
            cout<<"\n";
        }
    return 0;
}