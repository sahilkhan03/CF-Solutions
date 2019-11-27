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
#define inv(v) for(auto&i:v) in(i)
#define vl vector<ll>
#define ml unordered_map<ll,ll> 
#define vpl vector<pair<ll,ll>>
#define INF 0x3f3f3f3f

int main() {
    ll n,x,y;
    cin>>n>>x>>y;
    ll dp[n+1];
    memset(dp,0,sizeof dp);
    dp[0]=0;
    for(ll i=1;i<=n;i++) {
        if(i%2==0) {
            dp[i] = min(dp[i/2]+y,dp[i-1]+x);
        }
        else 
            dp[i] = min(dp[i-1]+x,dp[(i+1)/2]+x+y);
    }
    cout<<dp[n]<<endl;
    return 0;
}