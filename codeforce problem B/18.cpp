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
    ll arr2[n];
    int index=0;
    for(auto &x:arr)
    {
        cin>>x;
        arr2[index]=x;
        index++;
    }
    sort(arr2,arr2+n,greater<int>());
    map<int,stack<int>>mp;
    ll answer=0;
    int itr=0;
    for(int i=0;i<n;i++)
    {
         mp[arr[i]].push(i+1);
    }
    for(int i=0;i<n;i++)
    {
        answer+=(itr*arr2[i])+1;
        itr++; 
    }
    cout<<answer<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<mp[arr2[i]].top()<<" ";
        mp[arr2[i]].pop();
    }
    return 0;
}