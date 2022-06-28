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
        ll arr[n];
        for(auto &x:arr)
        {
            cin>>x;
        }
        sort(arr,arr+n);
        ll index=n;
        int flag=1;
        for(ll i=n-1;i>=0;i--)
        {
           if(index>=arr[i])
           {
               flag=0;
               cout<<index+1;
               break;
           }
           index--;
        }
        if(flag)
        {
            cout<<1;
        }
        cout<<endl;
    }
    return 0;
}