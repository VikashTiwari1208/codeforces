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
int main()
{
    fast;
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll cnt2=0,cnt3=0;
        while(n%2==0)
        {
            n=n/2;
            cnt2++;
        }
        while(n%3==0)
        {
            n=n/3;
            cnt3++;
        }
        if(n==1)
        {
          if(cnt2>cnt3)
          {
              cout<<-1;
          }
          else
          {
              cout<<cnt3+(cnt3-cnt2);
          }
          
        }
        else
        {
            cout<<-1;
        }
        cout<<endl;
    }
    return 0;
}