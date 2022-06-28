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
       ll n,m;
       cin>>n>>m;
       ll arr[n][m];
       for(int i=0;i<n;i++)
       {
          for(int j=0;j<m;j++)
          {
              cin>>arr[i][j];
          }
       }
       for(int i=n-2;i>=1;i--)
       {
           for(int j=m-2;j>=1;j--)
           {
               if(arr[i][j]==0)
               {
                   ll z=arr[i][j+1];
                   ll y=arr[i+1][j];
                   arr[i][j]=min(z,y)-1;
               }
           }
       }
       /*for(int i=0;i<n;i++)
       {
          for(int j=0;j<m;j++)
          {
              cout<<arr[i][j]<<" ";
          }
          cout<<endl;
       }*/
       ll sum=0;
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               sum+=arr[i][j];
               if((arr[i][j]<=arr[i][j-1]&&j>=1)||(arr[i][j]<=arr[i-1][j]&&i>=1))
               {
                   cout<<-1;
                   return 0;
               }
           }

       }
       cout<<sum;
    return 0;
}