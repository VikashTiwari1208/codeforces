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

int main()
{
    fast;
    int n;
    cin>>n;
    ll k;
    cin>>k;
    ll arr[n];
    for(auto &x:arr)
    {
        cin>>x;
    }
    map<int,vector<pair<ll,ll>>>mp;
    for(int i=0;i<n;i++)
    {
           for(int j=i+1;j<n;j++)
           {
               if(abs(arr[i]-arr[j])<=k)
               {
                   mp[abs(arr[i]-arr[j])].push_back({i,j});
               }
           }
    }
    ll size=0;
  for(auto x:mp)
  {
      size+=(x.second.size()*2);
  }
  cout<<size;
    return 0;
}