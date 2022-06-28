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
int floodfill(vector<vector<char>>&arr,int x,int y,int i,int j)
{
  if(j+1<=(arr[0].size()-1)&&arr[i][j+1]=='.')
  {
      arr[i][j]='*';
      arr[i][j+1]='*';
      return min(x*2,y);
  }
  else
  {
      arr[i][j]='*';
      return x;
  }
  
}
int main()
{
    fast;
   ll t;
   cin>>t;
   while(t--)
   {
        int n,m,x,y;
    cin>>n>>m>>x>>y;
    vector<vector<char>>arr( n,vector<char>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
    int sum=0;
    for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
    {
        if(arr[i][j]=='.')
        {
          sum+=floodfill(arr,x,y,i,j);
        }
    }
}
cout<<sum<<endl;
   }
    return 0;
}