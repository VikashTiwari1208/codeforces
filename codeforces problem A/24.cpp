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
    string a,b;
    cin>>a>>b;
   for(auto &x:a)
   {
       x=tolower(x);
   }
  for(auto &y:b)
  {
      y=tolower(y);
  }
  if(a==b)
  {
      cout<<0;
  }
  else if(a>b)
  {
      cout<<1;
  }
  else if(a<b)
  {
      cout<<-1;
  }


    return 0;
}