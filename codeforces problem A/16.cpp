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

int main()
{
    fast;
    ll n;
    cin>>n;
    vector<int>v1;
    vector<int>v;
    int arr[n];
    int mini=INT_MAX;
    int maxi=INT_MIN;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        mini=min(mini,arr[i]);
        maxi=max(maxi,arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]==maxi)
        {
            v1.push_back(i);
        }
    }
    int a=v1[0];
    int count=0;
   while(arr[0]!=maxi)
   {
      swap(arr[a],arr[a-1]);
      a--;
      count++;
   }
   int index;
   for(int i=0;i<n;i++)
   {
       if(arr[i]==mini)
       {
           v.push_back(i);
       }
   }
   index=v[v.size()-1];
   while(arr[n-1]!=mini)
   {
       count++;
       swap(arr[index],arr[index+1]);
       index++;
   }
 cout<<count;
    return 0;
}