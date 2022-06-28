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
int sx,sy;
bool isValid(int x,int y,int a,int b)
{
   int a1=min(sx,a);
   int a2=min(sy,b);
   int a3=max(sx,a);
   int a4=max(sy,b);
   if((x>=a1&&x<=a3)&&(y>=a2&&y<=a4))
   {
       return true;
   }
   return false;
}
int32_t main()
{
    fast;
      #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output1.txt","w",stdout);
       #endif
       int n;
       cin>>n>>sx>>sy;
       vpii home;
       for(int i=0;i<n;i++)
       {
           int a,b;
           cin>>a>>b;
           home.push_back({a,b});
       }
     int count=0;
     auto one=mp(sx+1,sy);
     auto two=mp(sx,sy+1);
     auto three=mp(sx-1,sy);
     auto four=mp(sx,sy-1);
     vpii tent{one,two,three,four};
     int ans=INT64_MIN;
     pii pos;
     for(int i=0;i<4;i++)
     {
         int count=0;
         for(int j=0;j<n;j++)
         {
            if(isValid(tent[i].first,tent[i].second,home[j].first,home[j].second))
            {
               count++;
            }
         }
         if(ans<count)
         {
             pos={tent[i].first,tent[i].second};
             ans=count;
         }
     }
     cout<<ans<<endl;
     cout<<pos.first<<" "<<pos.second;
    return 0;
}