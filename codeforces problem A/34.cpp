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
    int n;
    cin>>n;
    int arr[n];
    for(auto &x:arr)
    {
        cin>>x;
    }
    int min_dif=abs(arr[0]-arr[n-1]);
    unordered_map<int,pair<int,int>>mp;
    mp[abs(arr[0]-arr[n-1])]={1,n};
    for(int i=0;i<n;i++)
    {
            mp[abs(arr[i]-arr[i+1])]={i+1,i+2};
            min_dif=min(min_dif,abs(arr[i]-arr[i+1]));
    }
    cout<<mp[min_dif].first<<" "<<mp[min_dif].second;
    return 0;
}