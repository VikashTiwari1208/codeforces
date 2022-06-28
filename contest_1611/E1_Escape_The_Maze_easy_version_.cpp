/* Author: Vikas007_Code */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template<typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using max_heap = priority_queue<T>;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define int long long 
#define endl "\n"
#define M 1000000007LL
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mpr make_pair
#define pb push_back
#define fi first
#define se second
#define ceilof(x,y) (x+y-1)/y
#define midof(l,r) l+((r-l)/2)
#define test  \
    int t;     \
    cin >> t; \
    while (t--)
#define input(v, n) \
   fr(i, 0, n)     \
   {                \
      int x;         \
      cin >> x;     \
      v.pb(x);      \
   }
#define print(v, n) \
    inc(i, 0, n) { cout << v[i] << " "; }
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define fr(i, a, n) for (int i = a; i < n; i++)
#define rfr(i, a, n) for (int i = n - 1; i >= a; i--)
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;
typedef vector<vi> vvi;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // designed by Sebastiano Vigna and found on Neal's blog
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
typedef unordered_map<int,int,custom_hash>u_mp;
typedef map<int,int>mp;
typedef multimap<int,int>m_mp;
typedef unordered_set<int> u_seti;
typedef set<int> seti;
typedef multiset<int> m_seti;
long long binpow(long long base, long long exp)
{
    int mod=M;
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
const int N=(int)1e6;
void sieve(int N)
{
    // Create a boolean array 
    // "prime[0..n]" and initialize
    // all entries it as true. 
    // A value in prime[i] will
    // finally be false if i is 
    // Not a prime, else true.
    bool prime[N + 1];
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= N; p++)
    {
        // If prime[p] is not changed, 
        // then it is a prime
        if (prime[p] == true) 
        {
            // Update all multiples 
            // of p greater than or
            // equal to the square of it
            // numbers which are multiple 
            // of p and are less than p^2 
            // are already been marked.
            for (int i = p * p; i <= N; i += p)
                prime[i] = false;
        }
    }
}
// for factorial
int fact(int n) {
  int res = 1;
  for (int i = 1; i <= n; i++) {
    res = res * 1ll * i % M;
  }
  return res;
}
int C(int n, int k) {
  return fact(n) * 1ll * binpow(fact(k),M - 2) %M * 1ll *binpow(fact(n - k), M - 2) %M;
}
//lower_bound if x not present points to next greater element
//upper_bound return first element in the range which has value greater than given value 
// ye dekhlena
int32_t main()
{
    fast;
       test 
       {
         int n,k;
         cin>>n>>k;
         unordered_map<int,vi>adj;
         vi frns;
         input(frns,k);
         vi dis(n+1,1e7);
         vi dis2(n+1,1e7);
         for(int i=1;i<=n-1;i++)
         {
             int a,b;
             cin>>a>>b;
             adj[a].pb(b);
             adj[b].pb(a);
         }
         queue<int>q;
         for(auto x:frns)
         {
             dis[x]=0;
             q.push(x);
         }
         int level=0;
         while(q.empty()==false)
         {
             auto x=q.front();
             q.pop();
             for(auto node:adj[x])
             {
                 if(dis[node]>dis[x]+1)
                 {
                     dis[node]=dis[x]+1;
                     q.push(node);
                 }
             }
             level++;
         }
         queue<int>q2;
         q2.push(1);
         dis2[1]=0;
          level=0;
         while(q2.empty()==false)
         {
             auto x=q2.front();
             q2.pop();
             for(auto node:adj[x])
             {
                 if(dis2[node]>dis2[x]+1)
                 {
                     dis2[node]=dis2[x]+1;
                     q2.push(node);
                 }
             }
             level++;
         }
         bool flag=false;
         for(int i=1;i<=n;i++)
         {
             if(i!=1&&adj[i].size()==1)
             {
                 if(dis2[i]<dis[i])
                 {
                     flag=true;
                     break;
                 }
             }
         }
         if(flag)
         {
             cout<<"YES";
         }
         else
         {
             cout<<"NO";
         }
         cout<<endl;
       } 
    return 0;
}