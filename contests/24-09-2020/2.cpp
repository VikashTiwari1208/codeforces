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
int set_bit(ll x)
{
    return log2(x)+1;
}
int main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
    {
       int n;
       cin>>n;
       map<ll,ll>mp;
       for(int i=0;i<n;i++)
       {
           ll x;
           cin>>x;
        mp[set_bit(x)]++;
       }
      ll sum=0;
       for(auto x:mp)
       {
           if(x.second>1)
           {
             sum+=((x.second)*(x.second-1))/2;
           }
       }
       cout<<sum<<endl;
    }
    return 0;
}