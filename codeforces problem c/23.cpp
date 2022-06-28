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
       ll n;
       cin>>n;
       ll arr[n];
       for(auto &x:arr)
       {
           cin>>x;
       }
       sort(arr,arr+n);
       for(ll i=0;i<n;i+=2)
     {
        cout<<arr[i]<<" ";
     }
    if(n%2)
    {
        for(ll i=n-2;i>=0;i-=2)
        {
            cout<<arr[i]<<" ";
        }
    }
    else
    {
        for(ll i=n-1;i>=0;i-=2)
        {
            cout<<arr[i]<<" ";
        }
    }
    
    return 0;
}