#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long unsigned llu;
#define pll pair<ll,ll>
#define pb push_back
#define ff first
#define ss second

const ll M = 1e9+7;
const ll N = 1e3+5;
const ll LOG = 26;

vector<ll> dist(N,INT_MAX);

void bfs(){
    queue<ll> q;
    q.push(1);
    dist[0]=0;
    dist[1] = 0;
    while(!q.empty()){
        ll cur = q.front();
        q.pop();
        for(ll x = 1; x<=cur; x++){
            ll n_node = cur + cur/x;
            if(n_node>N)continue;
            if(dist[n_node]==INT_MAX){
                dist[n_node] = dist[cur]+1;
                q.push(n_node);
            }
        }
    }
}

// ll solve(ll ind,ll k,vector<ll>& w,vector<ll>& v,vector<vector<ll>>& dp){
//     if(ind<0) return 0;

//     if(dp[ind][k] != -1)return dp[ind][k];

//     //not pick
//     ll ans = solve(ind-1,k,w,v,dp);

//     //pick
//     if(k-w[ind]>=0)
//         ans = max(ans,solve(ind-1,k-w[ind],w,v,dp)+v[ind]);

//     return dp[ind][k] = ans;
// }

int32_t main()
{
    bfs();
    ll mx = *max_element(dist.begin(),dist.end());

    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        vector<ll> w(n),v(n);
        ll sum=0;
        for(ll i = 0; i<n; i++){
            ll x;
            cin>>x;
            w[i] = dist[x];
            sum+=w[i];
        }
        for(ll i = 0; i<n; i++)cin>>v[i];

        if(k>sum)k = sum;
        vector<vector<ll>> dp(n+1,vector<ll>(k+1,0));

        for(ll i = 1; i<=n; i++){
            for(ll j = 0; j<=k; j++){
                if(j-w[i-1]>=0){
                    dp[i][j] = dp[i-1][j-w[i-1]]+v[i-1];
                }
                dp[i][j] = max(dp[i][j],dp[i-1][j]);
            }
        }
        cout<<dp[n][k]<<"\n";
        
        // cout<<solve(n-1,k,w,v,dp)<<"\n";
    }

   
    return 0;
}