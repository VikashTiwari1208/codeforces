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
    ll n;
    cin>>n;
    ll arr[n];
    ll index;
    ll i=0;
    for(auto &x:arr)
    {
        cin>>x;
        if(x==n)
        {
            index=i;
        }
        i++;
    }
    if(index==0)
    {
        int flag=1;
        for(ll j=0;j<n-1;j++)
        {
            if(arr[j]<arr[j+1])
            {
                flag=0;
                cout<<"NO";
                break;
            }
        }
        if(flag)
        {
            cout<<"YES";
        }
    }
    else
    {
         int flag=0,flag1=0;
         for(ll j=0;j<index;j++)
         {
           if(arr[j]>arr[j+1])
           {
               flag=1;
               break;
           }
         }
         if(flag)
         {
             cout<<"NO";
         }
         else
         {
             for(ll j=index+1;j<n-1;j++)
         {
           if(arr[j]<arr[j+1])
           {
               flag1=1;
               break;
           }
         }
           if(flag1)
           {
             cout<<"NO";
           }
           else
           {
             cout<<"YES";
           }
         }
    }
    
    return 0;
}