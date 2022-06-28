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
       ll t;
       cin>>t;
       while(t--)
       {
           ll pi,qi;
           cin>>pi>>qi;
           if(pi%qi>0)
           {
               cout<<pi<<endl;
           }
           else
           {
               vector<ll>div;
               ll temp=qi;
               for(ll i=2;i*i<=temp;i++)
               {
                 if(temp%i==0)
                 {
                     div.push_back(i);
                     while(temp%i==0)
                     {
                         temp=temp/i;
                     }
                 }
               }
               if(temp>1)
               {
                   div.push_back(temp);
               }
              ll smll=pi;
              for(ll i=0;i<div.size();i++)
              {
                  ll a=pi;
                  ll b=qi;
                  ll cnta=0,cntb=0;
                  while(a%div[i]==0)
                  {
                      a=a/div[i];
                      cnta++;
                  }
                  while(b%div[i]==0)
                  {
                      b=b/div[i];
                      cntb++;
                  }
                  ll ans=1;
                  while(cnta>=cntb)
                  {
                      ans=ans*div[i];
                      cnta--;
                  }
                  smll=min(smll,ans);
              }
               cout<<pi/(smll)<<endl;
           }
       }
    return 0;
}