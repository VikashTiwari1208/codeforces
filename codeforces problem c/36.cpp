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
           int n,k;
           cin>>n>>k;
           string s;
           cin>>s;
           if(count(s.begin(),s.end(),'0')==n)
           {
               cout<<(n+k)/(k+1)<<endl;
           }
           else
           {
               int ans=0;
           for(int i=0;i<n;)
           {
               int j=i+1;
               while(j<n&&s[j]!='1')
               {
                   j++;
               }
               //cout<<j<<" "<<i<<" ";
               int len=j-i;
               int left=(s[i]=='1')?(k):0;
               int right=(j<n&&s[j]=='1')?(k):0;
               len-=left+right;
               if(left==k)
               {
                   len--;
               }
              //cout<<left<<" "<<right<<" "<<len<<endl;
               if(len>0)
               {
                   ans+=(len+k)/(k+1);
               }
               i=j;
           }
           cout<<ans<<endl;
           }
       }

    return 0;
}