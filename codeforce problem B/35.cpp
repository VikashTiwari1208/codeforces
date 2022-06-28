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
bool mysort(pair<ll,ll>a,pair<ll,ll>b)
{
 if(a.second>b.second)
 {
     return true;
 }
 else
 {
     return false;
 }
}
int main()
{
    fast;
    ll n,m;
    cin>>n>>m;
     vector<pair<ll,ll>>v;
     for(int i=0;i<m;i++)
     {
         ll a,b;
         cin>>a>>b;
         v.push_back({a,b});
     }
     sort(v.begin(),v.end(),mysort);
    ll sum=0;
    ll answer=0;
  for(int i=0;i<v.size();i++)
  {
      sum+=v[i].first;
      if(sum<=n)
      {
          answer+=v[i].first*v[i].second;
      }
      else
      {
          answer+=(n-sum+v[i].first)*v[i].second;
          break;
      }
  }
  cout<<answer;
    return 0;
}