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
           int n;
           string str;
           cin>>n>>str;
           vector<int>s(n);
           for(int i=0;i<n;i++)
           {
               if(str[i]=='0')
               {
                   s[i]=0;
               }
               else
               {
                   s[i]=1;
               }
           }
           vector<int>temp(n);
           temp[0]=1;
           for(int i=1;i<n;i++)
           {
               int a=temp[i-1]+s[i-1];
             //  cout<<a<<endl;
               if(a==0)
               {
                  temp[i]=1;
               }
               else if(a==1)
               {
                 if(s[i]==1)
                 {
                     temp[i]=1;
                 }
                 else
                 {
                     temp[i]=0;
                 }
               }
               else
               {
                 if(s[i]==1)
                 {
                     temp[i]=0;
                 }
                 else
                 {
                     temp[i]=1;
                 }
               }
           }
          for(auto x:temp)
          {
              cout<<x;
          }
          cout<<endl;
       }
    return 0;
}