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
    char arr[n][n];
    map<int,int>mp1;
    map<int,int>mp2;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]=='C')
            {
                mp1[i]++;
                mp2[j]++;
            }
        }
    }
    int ans1=0,ans2=0;
    for(auto x:mp1)
    {
       if(x.second>=2)
       {
        ans1+=((x.second)*(x.second-1))/2;
       }
    }
    for(auto x:mp2)
    {
        if(x.second>=2)
       {
        ans2+=((x.second)*(x.second-1))/2;
       } 
    }
    cout<<ans1+ans2;
    return 0;
}