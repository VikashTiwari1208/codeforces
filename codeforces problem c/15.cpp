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
           ll n;
           cin>>n;
           string s;
           cin>>s;
           ll firstone=-1;
           for(ll i=0;i<n;i++)
           {
              if(s[i]=='1')
              {
                  firstone=i;
                  break;
              }
           }
           if(firstone>-1)
           {
              ll arr[n],arr2[n];
              arr[0]=1;
              arr2[0]=1;
              for(ll i=1;i<n;i++)
              {
                  if(i<=firstone)
                  {
                      if(s[i]=='2')
                      {
                        arr[i]=1;
                        arr2[i]=1;
                      }
                      else if(s[i]=='1')
                      {
                        arr[i]=1;
                        arr2[i]=0;
                      }
                      else
                      {
                          arr[i]=0;
                          arr2[i]=0;
                      }
                  }
                  else
                  {
                      arr[i]=0;
                      arr2[i]=s[i]-'0';
                  }
              }
              for(auto x:arr)
              {
                  cout<<x;
              }
              cout<<endl;
              for(auto x:arr2)
              {
                  cout<<x;
              }
              cout<<endl;
           }
           else
           {
            ll arr[n],arr2[n];
              arr[0]=1;
              arr2[0]=1;
              for(ll i=1;i<n;i++)
              {
                      if(s[i]=='2')
                      {
                        arr[i]=1;
                        arr2[i]=1;
                      }
                      else
                      {
                          arr[i]=0;
                          arr2[i]=0;
                      }      
              }
              for(auto x:arr)
              {
                  cout<<x;
              }
              cout<<endl;
              for(auto x:arr2)
              {
                  cout<<x;
              }
              cout<<endl;   
           }
       }
    return 0;
}