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
int32_t main()
{
    fast;
      #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output1.txt","w",stdout);
       #endif
       int n;
       cin>>n;
       vi v(n);
       int sum=0;
       for(auto &x:v)
       {
           cin>>x;
           sum+=x;
       }
       if((sum%3!=0)||n<3)
       {
           cout<<0;
       }
       else
       {
           int prefix[n];
           prefix[0]=v[0];
           for(int i=1;i<n;i++)
           {
             prefix[i]=prefix[i-1]+v[i];
           }
        //    for(int i=0;i<n;i++)
        //    {
        //      cout<<prefix[i]<<" ";
        //    } 
          // cout<<endl;
           int ans=0;
           int cnt=0;
          for(int i=0;i<n;i++)
          {
              int x=prefix[i];
                if((x==(2*(sum/3)))&&(i<=n-2))
               {
                   ans+=cnt;
               }
               if((x==(sum/3))&&(i<=n-3))
               {
                   cnt++;
               }
          }
           cout<<ans;
       }
    return 0;
}