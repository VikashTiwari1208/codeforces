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
    ll a,b,n;
    cin>>a>>b>>n;
    int flag=1;
    int chance=0;
    while(n>=0)
    {
     if(chance%2==0)
     {
       if(n>=__gcd(a,n))
      {
          int hcf= __gcd(a,n);
          n=n-hcf;
          chance++;
      }
      else
      {
          flag=0;
          break;
      }
      
     }
       
    else
    {
        if(n>=__gcd(b,n))
    {
        int hcf=__gcd(b,n);
        n=n-hcf;
        chance++;
    }
    else
    {
        flag=2;
        break;
    }
    
    }
    }
    if(flag==0)
    {
        cout<<"1";
    }
     else
     {
         cout<<"0";
     }
    return 0;
}