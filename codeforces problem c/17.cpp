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
       ll n,k;
       cin>>n>>k;
       unordered_set<char>st;
       string s;
       cin>>s;
       for(ll i=0;i<k;i++)
       {
        char c;
        cin>>c;
        st.insert(c);
       }
       ll ans=0;
       ll count=0;
       for(ll i=0;i<n;i++)
       {
           if(st.find(s[i])!=st.end())
           {
               count++;
           }
           else
           {
               ans+=((count)*(count+1))/2;
               count=0;
           }
       }
       ans+=((count)*(count+1))/2;
       cout<<ans;
    return 0;
}