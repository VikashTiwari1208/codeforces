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
       ll i=0,j=n-1;
       ll sumi=arr[0],sumj=arr[j],flag=0;
        vector<ll>v;
       while(i<j)
       {
           if(sumi<sumj)
           {
               i++;
               sumi+=arr[i];
           }
           else if(sumi>sumj)
           {
               j--;
               sumj+=arr[j];
           }
           else
           {
               v.push_back(sumi);
               flag=i;
               i++;
               j--;
               sumi+=arr[i];
               sumj+=arr[j];
           }
       }
       if(v.size()==0)
       {
           cout<<0;
       }
       else
       {
           cout<<*max_element(v.begin(),v.end());
       }
       
    return 0;
}