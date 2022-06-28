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
    int n=s.length();
    sort(s.begin(),s.end());
    reverse(s.begin(),s.end());
    string max_pallindrome;
    for(int i=0;i<n;i++)
    {
        if(s[i]==s[i+1])
        {
            max_pallindrome.push_back(s[i]);
        }
        else
        {
            max_pallindrome.push_back(s[i]);
            break;
        }
    }
    cout<< max_pallindrome;
   
   
    return 0;
}