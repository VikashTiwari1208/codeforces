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
    ll n;
    cin>>n;
    int arr[n][2];
    for(ll i=0;i<n;i++)
    {
        for(int j=0;j<2;j++)
        {
            cin>>arr[i][j];
        }
    }
    int ans=arr[0][1];
    vector<int>v;
    v.push_back(ans);
    for(ll i=1;i<n;i++)
    {
        ans=ans-arr[i][0];
        ans=ans+arr[i][1];
        v.push_back(ans);
    }
    cout<<*max_element(v.begin(),v.end());
    return 0;
}