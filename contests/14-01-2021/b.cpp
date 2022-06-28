#pragma GCC optimize("Ofast")
#include <iostream>
#include <bits/stdc++.h>
#define int long long 
using namespace std;
#define endl "\n"
#define M 1000000007LL
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef unordered_map<int,int>umpii;
typedef map<int,int> mpii;
typedef multimap<int,int> mmpii;
typedef unordered_set<int> useti;
typedef set<int> seti;
typedef multiset<int> mseti;
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
bool isValid(string longi,string small)
{  
    string temp=small;
     for(int i=0;i<20;i++)
     {
         if(longi==small)
       {
          // cout<<longi<<" "<<small<<endl;
          return true;
       }
       if(small.length()>longi.length())
       {
           return false;
       }
        small+=temp;
     }
    return false;
}
int32_t main()
{
    fast;
      #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output1.txt","w",stdout);
       #endif
       int t;
       cin>>t;
       while(t--)
       {
        string a,b;
        cin>>a>>b;
        if(a.length()>b.length())
        {
            string temp=a;
            int flag=0;
          for(int i=0;i<20;i++)
          {
             if(isValid(a,b)&&isValid(a,temp))
             {
                // cout<<a;
                 flag=1;
                 break;
             }
           else
           {
                 a+=temp;
               // cout<<a<<" ";
           }
          }
         if(flag)
         {
              cout<<a<<endl;
         }
         else
         {
             cout<<-1<<endl;
         }
         
        }
        else
        {
            string temp=b;
            int flag=0;
              for(int i=0;i<20;i++)
           {
             if(isValid(b,a)&&isValid(b,temp))
             {
                 flag=1;
                 break;
             }
             b+=temp;
            // cout<<b<<" ";
           }
          if(flag)
          {
             cout<<b<<endl; 
          }
          else
          {
              cout<<-1<<endl;
          }
        }
       }
    return 0;
}