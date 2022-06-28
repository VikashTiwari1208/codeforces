#pragma GCC optimize("Ofast")
#include <iostream>
#include <bits/stdc++.h>
#define int long long 
using namespace std;
#define endl "\n"
#define M 1000000007LL
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef unordered_map<int,int>umpii;
typedef map<int,int> mpii;
typedef multimap<int,int> mmpii;
typedef unordered_set<int> useti;
typedef set<int> seti;
typedef multiset<int> mseti;
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
int n;
bool chk(int x,vi v)
{
  unordered_map<int,int>mp;
  for(int i=0;i<n;i++)
  {
     v[i]=v[i]%x;
     mp[v[i]]++;
  }
  int pair=0;
  for(int i=0;i<n;i++)
  {
    if((mp[x-v[i]]>0)&&(v[i]>0))
    {
      if(((2*v[i])==x)&&(mp[x-v[i]]>1))
      {
             pair++;
             mp[v[i]]=mp[v[i]]-2;
      }
      else
      {
            pair++;
            mp[v[i]]--;
            mp[x-v[i]]--;
      }
    }
    
         if((v[i]==0)&&(mp[v[i]]>=2))
      {
         pair++;
        mp[v[i]]=mp[v[i]]-2;
      }
  }
  if(pair==n/2)
  {
      return true;
  }
  else
  {
      return false;
  }
}
int32_t main()
{
    fast;
      #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output1.txt","w",stdout);
       #endif
       cin>>n;
       vi v;
       v.resize(n);
       int sum=0;
       for(auto &x:v)
       {
           cin>>x;
           sum+=x;
       }
       int ans=INT64_MIN;
       for(int i=1;i*i<=sum;i++)
       {
        if(sum%i==0)
        {
             if(chk(i,v))
         {
             ans=max(ans,i);
         }
         if(chk(sum/i,v))
         {
             ans=max(ans,sum/i);
         }
        }
       }
       if(ans==INT64_MIN)
       {
           cout<<1;
       }
      else
      {
           cout<<ans;
      }
    return 0;
}