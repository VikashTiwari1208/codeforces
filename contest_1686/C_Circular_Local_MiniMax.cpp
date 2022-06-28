/* Author: Vikas007_Code */

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
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
        // designedtempy Sebastiano Vigna and found on Neal'stemplog
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


//lower_bound if x not present points to next greater element
//upper_bound return first element in the range which has value greater than given value 
// ye dekhlena
int32_t main()
{
    fast;
       test 
       {
         int n;
         cin>>n;         vi v;
         input(v,n);
         sortall(v);

        map<int,int>mp;
        for(auto x:v)
        {
            mp[x]++;
        }
        vi temp(n);
        int j=0;
        
        for(int i=0;i<n;i+=2)
        {
           temp[i]=v[j];
           j++;
        }
        for(int i=1;i<n;i+=2)
        {
           temp[i]=v[j];
           j++;
        }
       bool flag=true;
        for(int i=1;i<n-1;i++)
        {
            if(temp[i]>temp[i-1]&&temp[i]>temp[i+1])
            {
               continue;
            }
            else if(temp[i]<temp[i-1]&&temp[i]<temp[i+1])
            {
               continue;
            }
            else
            {
              flag=false;
            }
            
        }
          if(!(temp[0]>temp[1]&&temp[0]>temp[n-1])&&!(temp[0]<temp[1]&&temp[0]<temp[n-1]))
          {
              flag=false;
          }
          if(!(temp[n-1]>temp[n-2]&&temp[n-1]>temp[0])&&!(temp[n-1]<temp[n-1]&&temp[n-1]<temp[0]))
          {
              flag=false;
          }
    
       if(flag)
       {
           cout<<"YES"<<endl;
           for(auto x:temp)
           {
               cout<<x<<" ";
           }
           
       }
       else
       {
           cout<<"NO";
       }
  cout<<endl;    
       } 
    return 0;
}