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
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        string s;
        cin>>s;
        ll first_one=-1,last_one=-1;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
                first_one=i;
                break;
            }
        }
         for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='1')
            {
                last_one=i;
                break;
            }
        }
        if(first_one==-1&&last_one==-1)
        {
            cout<<n;
        }
        else
        {
            int room1=(last_one+1)*2;
            int room2=(n-first_one)*2;
            cout<<max(room1,room2);
        }
        cout<<endl;
    }
    return 0;
}