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

int main()
{
    fast;
    ll t;
    cin>>t;
    while(t--)
    {
     ll n;
     cin>>n;
     ll arr[n];
     ll answer=0;
     for(ll i=0;i<n;i++)
     {
        cin>>arr[i];
        if(arr[i]%2==0)
        {
          answer++;
        }
     }
     cout<<(answer*(answer-1))/2<<endl;
    }
    return 0;
}