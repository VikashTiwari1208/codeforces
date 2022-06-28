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
vector<pair<int,int>> check(int x,int n,vector<int>v)
{
        multiset<int>s;
        for(int i=0;i<2*n;i++)
          {
             s.insert(v[i]);
          }
   vector<pair<int,int>>res;
   for(int i=0;i<n;i++)
   {
     auto it=s.end();
     it--;
      s.erase(it);
     int b=*it;
     int a=x-b;
    // cout<<b<<" "<<a<<" ";
     auto it2=s.find(a);
     if(it2==s.end())
     {
        return {{1,2}};
     }
     s.erase(it2);
     res.pb(mp(a,b));
     x=max(a,b);
   //   cout<<x<<endl;
   //         for(auto y:s)
   //        {
   //           cout<<y<<" ";
   //        }
   //        cout<<endl;
   }
   if(s.empty()==true)
   {
      return res;
   }
   return {{1,2}};
}
void solve()
{
           int n;
           cin>>n;
           vector<int>v(2*n);
           for(auto &x:v)
           {
               cin>>x;
           }
            sort(v.begin(),v.end());
         for(int i=0;i<2*n-1;i++)
         {
            int y=v[i]+v[(2*n)-1];
           // cout<<y<<endl;
             vector<pair<int,int>>ans=check(y,n,v);
            if(ans.size()==n)
            {
               cout<<"YES"<<endl;
               cout<<y<<endl;
               for(auto x:ans)
               {
                  cout<<x.first<<" "<<x.second<<endl;
               }
               return ;
            }
         }
         cout<<"NO"<<endl;
         return;
}
int32_t main()
{
    fast;
      #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output1.txt","w",stdout);
       #endif
       int t;
       cin>>t;
       while(t--)
       {
         solve();
       }
    return 0;
}