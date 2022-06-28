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
        int n,m;
        cin>>n>>m;
        if(m%2==0)
        {
         int arr[2*n][2];
         for(int i=0;i<2*n;i++)
         {
             for(int j=0;j<2;j++)
             {
                 cin>>arr[i][j];
             }
         }
         int flag=1;
         for(int i=0;i<2*n;i+=2)
         {
             if(arr[i+1][0]==arr[i][1])
            {
                flag=0;
                cout<<"YES";
                break;
            }
         }
         if(flag)
         {
             cout<<"NO";
         }
        }
        else
        {
            int arr[2*n][2];
         for(int i=0;i<2*n;i++)
         {
             for(int j=0;j<2;j++)
             {
                 cin>>arr[i][j];
             }
         }
            cout<<"NO";
        }
        cout<<endl;
    }
    return 0;
}