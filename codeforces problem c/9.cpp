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
       ll n,max_sum;
       cin>>n>>max_sum;
       vector<ll>songs(n);
       ll flag_sum=0;
       ll curr_sum=0;
       for(auto &x:songs)
       {
           ll a,b;
           cin>>a>>b;
          songs.push_back(a-b);
          flag_sum+=b;
          curr_sum+=a;
       }
     if(flag_sum>max_sum)
     {
         cout<<-1;
     }
     else
     {
      sort(songs.begin(),songs.end(),greater<int>());
      ll ans=0;
      ll index=0;
      while(curr_sum>max_sum)
      {
           if(curr_sum<=max_sum)
         {
            break;
         }
        curr_sum=curr_sum-songs[index];
         ans++;
         index++;
      }
      cout<<ans<<"\n";
     }
    
    return 0;
}