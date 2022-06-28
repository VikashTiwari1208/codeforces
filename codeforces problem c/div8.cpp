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
    string s;
    cin>>s;
    ll n=s.length(),i,j,k;
    ll x,y,z;
    for(i=0;i<n;i++)
    {
        if((s[i]-'0')%8==0)
        {
            cout<<"YES"<<"\n";
            cout<<s[i];
            return 0;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            x=s[i]-'0',y=s[j]-'0';
            if((10*x+y)%8==0)
            {
                cout<<"YES"<<"\n";
                cout<<x<<y;
                return 0;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            for(k=j+1;k<n;k++)
            {
                x=s[i]-'0',y=s[j]-'0',z=s[k]-'0';
                if((100*x+10*y+z)%8==0)
                {
                    
                     cout<<"YES"<<"\n";
                    cout<<x<<y<<z;
                    return 0;
                }
            }
        }
    }
    cout<<"NO";
    return 0;
}