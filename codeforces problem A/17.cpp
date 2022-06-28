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
    string s1,s2,s3;
    cin>>s1>>s2>>s3;
    map<char,int>mp1;
    map<char,int>mp2;
    for(auto x:s1)
    {
        mp1[x]++;
    }
    for(auto x:s2)
    {
        mp1[x]++;
    }
    for(auto x:s3)
    {
        mp2[x]++;
    }
    string check=s1+s2;
    int flag=1;
    for(auto x:check)
    {
       if(mp1[x]!=mp2[x])
       {
           flag=0;
           break;
       }
    }
    if(flag==1&&(s3.length()==check.length()))
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
    
    return 0;
}