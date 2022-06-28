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
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int k;
        cin>>k;
        ll arr[n];
        ll mini=INT64_MAX;
        ll maxi=INT64_MIN;
       for(auto &x:arr)
       {
           cin>>x;
           mini=min(mini,x);
           maxi=max(maxi,x);
       }
       if(maxi>k)
       {
           cout<<0;
       }
       else
       {
          sort(arr,arr+n);
         ll ans=0;
       for(int i=1;i<n;i++)
      {
         ans+=((k-arr[i])/mini);
       } 
       cout<<ans;
       }
       
      cout<<endl;
    }
    return 0;
}