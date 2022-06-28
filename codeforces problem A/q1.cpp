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
        ll n,k,l;
        cin>>n>>k>>l;
        if(n>(k*l))
        {
            cout<<"-1"<<endl;
        }
        else
        {
            ll arr[k];
            for(long long int i=0;i<k;i++)
            {
              arr[i]=i+1;
            }
            ll index=1;
            ll loop=n;
          while(loop--)
          {
            cout<<arr[((index)%k)-1]<<" ";
            index++;
          }
          cout<<endl;
        }
    }
    return 0;
}