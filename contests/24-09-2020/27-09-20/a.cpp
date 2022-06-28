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
     // #ifndef ONLINE_JUDGE
       //freopen("input.txt","r",stdin);
       //freopen("output1.txt","w",stdout);
       //#endif
       ll t;
       cin>>t;
       while(t--)
       {
        ll n,x;
        cin>>n>>x;
        ll arr1[n],arr2[n];
        ll z=n*x;
        for(ll i=0;i<n;i++)
        {
            cin>>arr1[i];
        }
        for(ll i=0;i<n;i++)
        {
           cin>>arr2[i];
       }
       ll flag=1;
        sort(arr1,arr1+n,greater<ll>());
        for(ll i=0;i<n;i++)
        {
            if(arr1[i]+arr2[i]>x)
            {
                cout<<"No"<<endl;
               flag=0;
               break;
            }
        }
        if(flag)
        {
        cout<<"Yes"<<endl;
        }
       }

    return 0;
}