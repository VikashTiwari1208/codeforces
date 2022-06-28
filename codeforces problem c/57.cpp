#pragma GCC optimize("Ofast")
#include <iostream>
#include <bits/stdc++.h>
#define int long long 
using namespace std;
#define endl "\n"
#define M 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mpr make_pair
#define pb push_back
#define fi first
#define se second
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;
typedef vector<vi> vvi;
typedef unordered_map<int,int>ump;
typedef map<int,int> mp;
typedef multimap<int,int> mmp;
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
class comp{
  public:
   bool operator()(const int &a,const int &b)
   {
      return a>b;
   }
};
int32_t main()
{
     fast;
      #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output1.txt","w",stdout);
       #endif
       int n,q;
       cin>>n>>q;
        vector<int> a(n+2,0);
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    vector<int> qq(n+2,0);
    for(int i =0;i<q;i++){
        int a,b;
 
        cin>>a>>b;
        qq[a] +=1;
        qq[b+1] -=1;
    }
//   for(auto x:qq)
//   {
//      cout<<x<<" ";
//   }
  //cout<<endl;
    for(int i =1;i<=n;i++){
        qq[i] += qq[i-1];
    }
//  for(auto x:qq)
//   {
//      cout<<x<<" ";
//   }
//   cout<<endl;
    sort(qq.begin(),qq.end());
//      for(auto x:qq)
//   {
//      cout<<x<<" ";
//   }
//   cout<<endl;
 
    int ans =0;
    for(int i =n+1;i>0;i--){
      // cout<<a[i]<<" ";
        ans += qq[i] * a[i];
    }
 
     cout<<ans<<endl; 
    return 0;
}