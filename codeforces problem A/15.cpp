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
    ll digits;
    cin>>digits;
    string s;
    cin>>s;
    int flag=1;
    for(auto x:s)
    {
        if(x=='4'||x=='7')
        {
            continue;
        }
        else
        {
            flag=0;
            break;
        }
        
    }
    if(flag==0)
    {
        cout<<"NO";
    }
    else
    {
         int pointer=1;
    int sum1=0,sum2=0;
    for(int i=0;i<(s.length()/2);i++)
    {
        if(s[i]=='4'||s[i]=='7')
        {
            sum1+=s[i];
        }
    }
    for(int i=s.length()/2;i<(s.length());i++)
    {
        if(s[i]=='4'||s[i]=='7')
        {
            sum2+=s[i];
        }
    }
    if(sum1==sum2&&(sum1>0))
    {
        cout<<"YES";
    }
    else
    {
        //cout<<sum1<<endl<<sum2;
        cout<<"NO";
    }
    }
    return 0;
}