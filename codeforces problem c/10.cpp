#pragma GCC optimize("Ofast")
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define endl "\n"
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
int main()
{
    fast;
       #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output1.txt","w",stdout);
       #endif
       ll t;
       cin>>t;
       while(t--)
       {
           ll n;
           cin>>n;
           ll arr[n];
           ll mini=INT64_MAX;
           ll maxi=INT64_MIN;
           unordered_map<ll,ll>mp;
           for(auto &x:arr)
           {
            cin>>x;
            mp[x]++;
            mini=min(mini,x);
            maxi=max(maxi,x);
           }
           ll ans=-1;
           for(ll i=2*mini;i<=2*maxi;i++)
           {
               ll pairs=0;
              for(ll j=1;j<(i+1)/2;j++)
              {
                pairs+=min(mp[j],mp[i-j]);
              }
              if(i%2==0)
              {
                  pairs+=mp[i/2]/2;
              }
              ans=max(ans,pairs);
           }
       cout<<ans<<endl;
       }
    return 0;
}