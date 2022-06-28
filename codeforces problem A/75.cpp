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
int max_sum(vector<vector<int>>&v,int row,int column)
{
  if(row==0||column==0)
  {
      return 1;
  }
  return max_sum(v,row,column-1)+max_sum(v,row-1,column);
  
}
int main()
{
    fast;
    int n;
    cin>>n;
     vector<vector<int>>arr(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {

        for(int j=0;j<n;j++)
        {
           if(i==0||j==0)
           {
               arr[i][j]=1;
           }
           else
           {
               arr[i][j]=arr[i-1][j]+arr[i][j-1];
           }
        }
    }
   cout<<max_sum(arr,n-1,n-1);
    return 0;
}