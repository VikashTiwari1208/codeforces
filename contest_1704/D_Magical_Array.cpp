// JAI BAJARANG BALI

// manitianajay45

// give me some sunshine, give me some rain, give me another chance to grow up once again....

// sab moh maya hai....

#include <iostream>
#include<vector>
using namespace std;

#define ll long long
#define mod 998244353



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k;
    // cin >> n >> k;
    scanf("%lld %lld",&n,&k);

    ll m = 632;
    vector<ll> ans(n + 1, 0);
    vector<ll> prev(n + 1, 0);
    vector<ll> curr(n + 1, 0);
    prev[0] = 1;
    ll kk;
    for (ll j = 1; j <= m; j++)
    {
        kk = (k + j - 1);
        for (ll i = 0; i <= n-kk; i++)
        {

            curr[i+kk] += prev[i];
            curr[i+kk] += curr[i];
            curr[i+kk] %= mod;
            
            
        }

    

        for (ll i = 0; i <= n; i++)
        {

            ans[i] += curr[i];
            ans[i] %= mod;
            prev[i] = curr[i];
            curr[i] = 0;
        }

    }

    for (ll i = 1; i <= n; i++)
    {
        // cout << ans[i] << " ";
        printf("%lld ",ans[i]);
    }

    return 0;
}