#include <bits/stdc++.h>
using namespace std;
 
#define fastIO ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define ll long long
ll mod = 1e9+7;

int main() {
    fastIO
    ll n,k;
    cin>>n>>k;
    ll a[n];
    for (ll int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    
    ll dp[n+1][k+1];
    ll sum[n+1][k+1];
    for (ll int children = 0; children <= n; ++children)
    {
        for (ll int candies = 0; candies <= k; ++candies)
        {
            if(candies==0){
                dp[children][candies] = 1;
                sum[children][candies] = 1;
            }
            else if(children==0){
                dp[children][candies] = 0;
                sum[children][candies] = 1;
            }
            else{
                ll candiesRangeStart = candies - min(candies,a[children-1]);
                dp[children][candies] = (mod + sum[children-1][candies] - sum[children-1][candiesRangeStart])%mod;
                dp[children][candies] = (dp[children][candies] + dp[children-1][candiesRangeStart]) % mod;
                sum[children][candies] = (dp[children][candies] + sum[children][candies-1]) % mod;
            }
        }
    }

    ll ans = dp[n][k];
    cout << ans << endl;
    return 0;
}
