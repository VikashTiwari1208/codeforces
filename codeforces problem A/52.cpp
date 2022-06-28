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
    char arr[n][5];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<5;j++)
        {
            cin>>arr[i][j];
        }
    }
    int flag=0;
    int flag1=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<4;j++)
        {
          if(arr[i][j]=='O'&&arr[i][j+1]=='O')
          {
             flag=1;
             flag1=1;
             cout<<"YES"<<endl;
             arr[i][j]='+';
             arr[i][j+1]='+';
             break;
          }
        }
        if(flag1)
        {
            break;
        }
    }
 if(flag)
 {
for(int i=0;i<n;i++)
    {
        for(int j=0;j<5;j++)
        {
         cout<<arr[i][j];
        }
        cout<<endl;
    }
 }
 else
 {
     cout<<"NO";
 }
 
    
    return 0;
}