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
    int arr[n];
    for(auto &x:arr)
    {
        cin>>x;
    }
    int max_initial=0;
    for(int i=0;i<n;i++)
    {
      if(arr[i]==1)
      {
          max_initial++;
      }
      else
      {
          break;
      }
    }
    int count=0;
    int max_frq=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)
        {
            count=0;
        }
        else
        {
            if(i==n-1)
            {
              if(arr[0]==1)
              {
                  count+=max_initial+1;
                  max_frq=max(max_frq,count);
              }
              else
              {
                count++;
                max_frq=max(max_frq,count);
              }
            }
            else
            {
                count++;
                max_frq=max(max_frq,count);
            }
            
        }
    }
    cout<<max_frq;
    return 0;
}