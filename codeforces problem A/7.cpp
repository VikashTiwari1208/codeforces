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
    ll m,n;
    cin>>m>>n;
    char arr[m][n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    int row,column;
     for(int i=0;i<m;i++)
    {
        int count=0;
        for(int j=0;j<n;j++)
        {
           if(arr[i][j]=='*')
           {
               count++;
           }
        }
        if(count==1)
        {
            row=i;
    }
    }
 for(int i=0;i<n;i++)
    {
        int count=0;
        for(int j=0;j<m;j++)
        {
           if(arr[j][i]=='*')
           {
               count++;
           }
        }
        if(count==1)
        {
            column=i;
    }
    }
  cout<<row+1<<" "<<column+1;
    return 0;
}