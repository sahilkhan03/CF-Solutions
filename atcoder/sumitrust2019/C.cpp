/*                    ___          |\    /|           ____   ____   ____  ____
   |     |    /\    /    \ |     | | \  / |    /\    |    \ |    \ |     |    \
   |_____|   /__\   \____  |_____| |  \/  |   /__\   |____/ |____/ |__   |____/
   |     |  /    \       \ |     | |      |  /    \  |      |      |     |   \
   |     | /      \ \____/ |     | |      | /      \ |      |      |____ |    \
*/
#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define lb lower_bound
#define ub upper_bound
#define pf push_front
#define pb push_back
#define ll long long
#define pi pair<int,int>
#define pl pair<long long,long long>
#define pld pair<long double,long double>
#define endl '\n'
#define loop(i,n) for(ll i=0;i<n;i++)
#define mod ((ll)(1e9+7))
#define in(x) scanf("%lld",&x)
#define in2(x,y) scanf("%lld %lld",&x,&y)
#define in3(x,y,z) scanf("%lld %lld %lld",&x,&y,&z)
#define inv(v) for(auto&i:v) in(i)
#define vl vector<ll>
#define ml unordered_map<ll,ll> 
#define vpl vector<pair<ll,ll>>
#define INF 0x3f3f3f3f

bool  dp[int(1e5) +5];
int main() {
    dp[0]=1;
    ll n;
    in(n);
    for(ll i=1;i<=n;i++) {
        if(i>=100) dp[i] = max(dp[i],dp[i-100]);
        if(i>=101) dp[i] = max(dp[i],dp[i-101]);
        if(i>=102) dp[i] = max(dp[i],dp[i-102]);
        if(i>=103) dp[i] = max(dp[i],dp[i-103]);
        if(i>=104) dp[i] = max(dp[i],dp[i-104]);
        if(i>=105) dp[i] = max(dp[i],dp[i-105]);
    }
    cout<<dp[n]<<endl;
    return 0;
}