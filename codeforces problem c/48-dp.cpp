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
           string s;
           cin>>s;
           int LongestEvenSequence=0;
           int MostFrequentCount=0;
           umpii frq;
           vvi dp;
           dp.resize(10,vi(10,0));
           for(int i=0;i<s.length();i++)
           {
               int val=s[i]-'0';
               frq[val]++;
               for(int j=0;j<=9;j++)
               {
                   dp[val][j]=dp[j][val]+1;
                   if(dp[val][j]%2==0)
                   {
                       LongestEvenSequence=max(LongestEvenSequence,dp[val][j]);
                   }
               }
           }
           for(auto x:dp)
           {
               for(auto y:x)
               {
                   cout<<y<<" ";
               }
               cout<<endl;
           }
           for(auto x:frq)
           {
               MostFrequentCount=max(x.second,MostFrequentCount);
           }
          cout<<min(s.length()-MostFrequentCount,s.length()-LongestEvenSequence)<<endl;
       }
    return 0;
}