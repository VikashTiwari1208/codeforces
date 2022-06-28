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
    string s;
    cin>>s;
    stack<char>a,b,c;
    int index=1;
    for(ll i=0;i<n;i++)
    {
        if(index%2)
        {
            a.push(s[i]);
        }
        else
        {
            b.push(s[i]);
        }
        index++;
    }
    if(n%2==0)
    {
      while(b.size()>0)
      {
          c.push(b.top());
          b.pop();
      }
      while (a.size()>0)
      {
         cout<<a.top();
         a.pop();
      }
      while(c.size()>0)
      {
          cout<<c.top();
          c.pop();
      }
    }
    else
    {
        while(a.size()>0)
      {
          c.push(a.top());
          a.pop();
      }
      while (b.size()>0)
      {
         cout<<b.top();
         b.pop();
      }
      while(c.size()>0)
      {
          cout<<c.top();
          c.pop();
      }
    }
    
    return 0;
}