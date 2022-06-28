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
    int n,c;
    cin>>n>>c;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int arr2[n];
    for(auto &x:arr2)
    {
        cin>>x;
    }
    int prefix[n];
    int rprefix[n];
    rprefix[n-1]=arr2[n-1];
    prefix[0]=arr2[0];
    for(int i=1;i<n;i++)
    {
        prefix[i]=prefix[i-1]+arr2[i];
    }
     for(int i=n-2;i>=0;i--)
    {
        rprefix[i]=rprefix[i+1]+arr2[i];
    }
    int ans1=0;
    for(int i=0;i<n;i++)
    {
        ans1+=max(0,(arr[i]-(c*prefix[i])));
    }
    int ans2=0;
   for(int i=n-1;i>=0;i--)
    {
        ans2+=max(0,(arr[i]-(c*rprefix[i])));
    }
    if(ans1>ans2)
    {
        cout<<"Limak";
    }
    else if(ans1<ans2)
    {
        cout<<"Radewoosh";
    }
    else
    {
        cout<<"Tie";
    }
    
    return 0;
}