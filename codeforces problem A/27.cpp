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
    string s;
    cin>>s;
    string s1=s;
    string s2=s;
    int frqcaps=0,frqsmall=0;
    for(int i=0;i<s.length();i++)
    {
       if(((s[i]-65)>=0)&&((90-s[i]))>=0)
       {
          frqcaps++;
          s1[i]=tolower(s[i]);
          s2[i]=toupper(s[i]);
       }
       else
       {
            s1[i]=tolower(s[i]);
          s2[i]=toupper(s[i]);
           frqsmall++;
       }
    }
    if(frqsmall>=frqcaps)
    {
        cout<<s1;
    }
    else
    {
        cout<<s2;
    }
    
    return 0;
}