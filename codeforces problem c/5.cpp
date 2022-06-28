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
            ll even=0,odd=0;
           ll arr[n];
           for(auto &x:arr)
           {
               cin>>x;
               if(x%2==0)
               {
                even++;
               }
               else
               {
                   odd++;
               }
           }
           if(even%2!=odd%2)
           {
               cout<<"NO";
           }
           else
           {
               if(even%2==0)
               {
                   //cout<<even;
                   //cout<<"this";
                   cout<<"YES";
               }
               else
               {
                   sort(arr,arr+n);
                   int flag=0;
                   for(int i=0;i<n-1;i++)
                   {
                       if(abs(arr[i]-arr[i+1])==1)
                       {
                           flag=1;
                           break;
                       }
                   }
                   if(flag)
                   {
                       cout<<"YES";
                   }
                   else
                   {
                       cout<<"NO";
                   }
               }
           }
        cout<<endl;
       }
    return 0;
}