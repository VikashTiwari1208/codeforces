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
           int n,x;
           cin>>n>>x;
           int arr[n];
           for(auto &y:arr)
           {
               cin>>y;
           }
           int flag1=1,flag2=1;
        queue<pii> q;
        int a=0;
        int sum=accumulate(arr,arr+n,a);
        for(int i=0;i<n;i++)
        {
            if(arr[i]%x)
            {
                flag1=0;
                break;
            }
            else
            {
                int z=arr[i]/x;
                q.push(mp(x,z));
               // sum+=(x*z);
            }
        }
        if(flag1)
        {
            while(q.empty()==false)
         {
            if(q.front().second%x)
            {
                flag2=0;
                break;
            }
            else
            {
                sum+=(q.front().first)*(q.front().second);
                q.push(mp(x*(q.front().first),q.front().second/x));
                q.pop();
            }
          }
        }
            while(q.empty()==false)
           {
                sum+=(q.front().first)*(q.front().second);
                //q.push(mp(x*(q.front().first),q.front().second/x));
                q.pop();
           }
        cout<<sum<<endl;
       }
    return 0;
}