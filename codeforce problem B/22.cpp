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
    int n;
    cin>>n;
    vector<ll>odd;
    vector<ll>even;
    for(int i=0;i<n;i++)
    {
      int x;
      cin>>x;
      if(x%2)
      {
          odd.push_back(x);
      }
      else
      {
          even.push_back(x);
      }
    }
    sort(odd.begin(),odd.end(),greater<int>());
    sort(even.begin(),even.end(),greater<int>());
    if((max(odd.size(),even.size())-min(odd.size(),even.size()))<=1)
    {
        cout<<0;
    }
    else
    {
        if(odd.size()>even.size())
        {
            ll sum=0;
            ll index=odd.size()-even.size()-1;
            for(int i=odd.size()-index;i<odd.size();i++)
            {
                sum+=odd[i];
            }
            cout<<sum;
        }
         if(even.size()>odd.size())
        {
            ll sum=0;
            ll index=even.size()-odd.size()-1;
            for(int i=even.size()-index;i<even.size();i++)
            {
                sum+=even[i];
            }
            cout<<sum;
        }
        
    }
    
    return 0;
}