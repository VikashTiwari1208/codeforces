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
        string s;
        cin>>s;
        priority_queue<int>v;
        int count=0;
       for(int i=0;i<s.length();i++)
       {
           if(s[i]=='1')
           {
               count++;
               if(i==s.length()-1)
               {
                   v.push(count);
               }
           }
           else
           {
               v.push(count);
               count=0;
           }
       }
      int sum=0;
      int index=0;
      while(!v.empty())
      {
        if(index%2==0&&v.top()>0)
         {
             sum+=v.top();
         }
         index++;
         if(v.top()==0)
         {
             break;
         }
         v.pop();
      }
      cout<<sum;
        cout<<endl;
    }
    return 0;
}