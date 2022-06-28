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
typedef unordered_map<int,int>ump;
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
           string s,t,p;
           cin>>s>>t>>p;
           unordered_map<char,int>map1,map2;
           for(auto x:s)
           {
             map1[x]++;
           }
           for(auto x:p)
           {
             map1[x]++;
           }
           for(auto x:t)
           {
               map2[x]++;
           }
           bool condition1=true;
            for(auto x:t)
            {
                if((map1[x]-map2[x]<0))
                {
                  //  cout<<x<<" ";
                    condition1=false;
                    break;
                }
            }
            bool condition2=true;
            int it1=0,it2=0;
            while(it1<s.size())
            {
                if(it2>=t.size())
                {
                   // cout<<it2<<endl;
                    condition2=false;
                    break;
                }
               if(s[it1]==t[it2])
               {
                   it1++,it2++;
                   continue;
               }
              it2++;
            }
            if(condition1&&condition2)
            {
                cout<<"YES"<<endl;
            }
            else
            {
                cout<<"NO"<<endl;
            } 
       }
    return 0;
}