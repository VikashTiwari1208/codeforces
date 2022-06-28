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
    ll n,m;
    cin>>n>>m;
    ll sum=(n*(n+1))/2;
      m= m%sum;
      if(m==0)
      {
          cout<<0;
      }
      else
      {
         ll arr[n],prefix[n];
     for(ll i=0;i<n;i++)
     {
         arr[i]=i+1;
     }
        prefix[0]=1;
        for(ll i=1;i<n;i++)
        {
           prefix[i]=prefix[i-1]+arr[i];
        }
        int index=0;
        ll answer=0;
        while(prefix[index]<=m)
        {
            if(prefix[index]==m)
            {
                cout<<0;
                break;
            }
            index++;
            if(prefix[index]==m)
            {
                cout<<0;
                break;
            }
            else if(prefix[index]>m)
            {
                index--;
                answer=m-prefix[index];
                break;
            }
        }
         if(answer)
        {
           cout<<answer;
         } 
      }
    return 0;
}