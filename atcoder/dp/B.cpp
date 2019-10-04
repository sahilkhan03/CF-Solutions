/*                    ___          |\    /|           ____   ____   ____  ____
   |     |    /\    /    \ |     | | \  / |    /\    |    \ |    \ |     |    \
   |_____|   /__\   \____  |_____| |  \/  |   /__\   |____/ |____/ |__   |____/
   |     |  /    \       \ |     | |      |  /    \  |      |      |     |   \
   |     | /      \ \____/ |     | |      | /      \ |      |      |____ |    \
*/
#include<bits/stdc++.h>
using namespace std;
#define lb lower_bound
#define ub upper_bound
#define pf push_front
#define pb push_back
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define pi pair<int,int>
#define pl pair<long,long>
#define pll pair<long long,long long>
#define pld pair<long double,long double>
#define gc getchar_unlocked
#define pc putchar_unlocked
#define endl '\n'
#define loop(i,n) for(ll i=0;i<n;i++)
#define mod 1e9+7
#define in(x) scanf("%lld",&x)
#define in2(x,y) scanf("%lld %lld",&x,&y)
#define vl vector<ll>
#define vpll vector<pair<ll,ll>>
#define INF 0x3f3f3f3f
#define mp make_pair

ll calc(vl &dp,vl v,ll cost,ll pos, ll n) {
    if(dp[pos] == -1) {
        if(pos == n) return  dp[pos] = cost;
        if(pos == n-1) return dp[pos] = calc(dp,v,cost+abs(v[pos-1]-v[pos]),pos+1,n);
        dp[pos] = cost + min(calc(dp,v,abs(v[pos-1]-v[pos]),pos+1,n), calc(dp,v,abs(v[pos-1]-v[pos+1]),pos+2,n));
    }
    return dp[pos];
}

int main()
{
    ll n,k;
    if(in2(n,k)!=2) return 0;
    vl v(n),dp(n+1,INF);
    loop(i,n) in(v[i]);
    dp[n] = 0;
    dp[n-1] = abs(v[n-1]-v[n-2]);
    for(ll i=n-2;i>0;i--) {
        for(ll j=1;j<=k;j++)
            if(i+j<=n)
                dp[i] = min(dp[i+j] + abs(v[i-1]-v[i+j-1]),dp[i]);
    }
    cout<<dp[1]<<endl;
    // for(auto x:dp) cout<<x<<" ";
    return 0;
}