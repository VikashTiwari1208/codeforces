/* Author: Vikas007_Code */

#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"
#define M 1000000007LL
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mpr make_pair
#define pb push_back
#define fi first
#define se second

#define test  \
    int t;     \
    cin >> t; \
    while (t--)
#define input(v, n) \
   inc(i, 0, n)     \
   {                \
      int x;         \
      cin >> x;     \
      v.pb(x);      \
   }
#define print(v, n) \
    inc(i, 0, n) { cout << v[i] << " "; }
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define inc(i, a, n) for (int i = a; i < n; i++)
#define dec(i, a, n) for (int i = n - 1; i >= a; i--)
#define maxheap priority_queue<int>
#define minheap priority_queue<int, vector<int>, greater<int>>
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;
typedef vector<vi> vvi;
typedef unordered_map<int,int>u_mp;
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
int32_t main()
{
    fast;
      #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output1.txt","w",stdout);
       #endif
       test 
       {
          int x,y;
          cin>>x>>y;
          string s;
          cin>>s;
          int l=0,r=0,u=0,d=0;
          for(int i=0;i<s.length();i++)
          {
            if(s[i]=='L')
            {
                l++;
            }
            else if(s[i]=='R')
            {
                r++;
            }
           else if(s[i]=='U')
            {
                u++;
            }
           else if(s[i]=='D')
            {
                d++;
            } 
          }
          bool flag1=false;
          bool flag2=false;
          if(x>=0&&r>=x)
          {
            flag1=true;
          }
          if(x<=0&&l>=abs(x))
          {
              flag1=true;
          }
          if(y>=0&&u>=y)
          {
            flag2=true;
          }
          if(y<=0&&d>=abs(y))
          {
              flag2=true;
          }
          if(flag1&&flag2)
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