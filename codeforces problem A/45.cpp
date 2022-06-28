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
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int index_g,index_t;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='G')
        {
            index_g=i;
        }
        if(s[i]=='T')
        {
            index_t=i;
        }
    }
    int flag=1;
    int flag1=1;
    if(index_g-index_t>0)
    {
       while(index_g>=0)
       {
          if(s[index_g-k]!='#')
          {
            index_g=index_g-k;
            if(s[index_g]=='T')
            {
                flag1=0;
                flag=0;
                cout<<"YES";
                break;
            }
          }
          else
          {
                flag1=0;
                flag=0;
              cout<<"NO";
              break;
          }
          
       }
    }
    else
    {
      while(index_g<=n-1)
       {
          if(s[index_g+k]!='#')
          {
            index_g=index_g+k;
            if(s[index_g]=='T')
            {
                 flag1=0;
                flag=0;
                cout<<"YES";
                break;
            }
          } 
          else
          {
                flag1=0;
                flag=0;
              cout<<"NO";
              break;
          }
            
       }
    }
    if(flag)
    {
        cout<<"NO";
    }
    return 0;
}