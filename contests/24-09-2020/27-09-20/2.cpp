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
    int t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        ll arr[n];
        for(auto &x:arr)
        {
            cin>>x;
        }
        if(k%2!=0)
        {
          for(auto &x:arr)
          {
              if(x<=(k/2))
              {
                  x=0;
              }
              else
              {
                  x=1;
              }
          }
        }
        else
        {
            int index=0;
            for(auto &x:arr)
            {
                if(x==(k/2)&&(index%2==0))
                {
                  index++;
                  x=0;
                }
                else if(x==(k/2)&&(index%2!=0))
                {
                    index++;
                    x=1;
                }
                else if(x<(k/2))
                {
                    x=0;
                }
                else if(x>k/2)
                {
                    x=1;
                }
            }
        }
        for(auto x:arr)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}