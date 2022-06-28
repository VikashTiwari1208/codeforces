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
       int t;
       cin>>t;
       while(t--)
       {
           int n,k;
           cin>>n>>k;
           int h[n];
           for(auto &x:h)
           {
               cin>>x;
           }
           bool possible=true;
           int maxi=h[0],mini=h[0];
           for(int i=1;i<n-1;i++)
           {
              if((mini>=h[i]+((2*k)-1))||(maxi+k<=h[i]))
              {
                 possible=false;
                 break;
              }
              else
              {
               mini=max(mini-k+1,h[i]);
               maxi=min(maxi+k-1,h[i]+k-1);  
              }
           }
           if(possible==false)
           {
              cout<<"NO"<<endl;
           }
           else
           {
              if((mini<h[n-1]+k)&&(maxi+k>h[n-1]))
              {
                 cout<<"YES"<<endl;
              }
              else
              {
                 cout<<"NO"<<endl;
              }
           }
       }
    return 0;
}