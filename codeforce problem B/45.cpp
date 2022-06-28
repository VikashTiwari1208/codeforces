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
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    if(s[0]=='1')
    {
       if(k==1&&n==1)
       {
           cout<<min(0,int(s[0]));
       }
       else
       {
          ll index=1;
          while(k>0&&index<=n-1)
          {
            if(s[index]!='0')
            {
                s[index]='0';
                k--;
            }
            index++;
          }
          for(int i=0;i<n;i++)
          {
              cout<<s[i];
          }
       }
       
    }
    else
    {
        if(k==0)
        {
            for(auto x:s)
            {
                cout<<x;
            }
        }
        else
        {
            if(k==1&&n==1)
             {
                  cout<<min(0,int(s[0]));
             }
             else
             {
                   ll index=0;
        while(k>0&&index<=n-1)
          {
             if(s[index]!='0')
            {
               if(index==0)
               {
                   s[index]='1';
                   k--;
               }
               else
               {
                    s[index]='0';
                     k--;
               }
               
            }
            index++;
          }
           for(int i=0;i<n;i++)
          {
              cout<<s[i];
          }
        }
             
        }
    }
    
    return 0;
}