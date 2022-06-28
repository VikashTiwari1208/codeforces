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
}void print(int n)
{
    if(n==1)
    {
        cout<<n;
    }
    else
    {
        cout<<n<<" ";
        print(n-1);
    }
    
}
int main()
{
    fast;
    ll n;
    cin>>n;
    if(n%2!=0)
    {
        cout<<-1;
    }
    else
    {
        print(n);
    }
    
    return  0;
}