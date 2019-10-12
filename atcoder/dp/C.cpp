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

int main()
{
    ll n;
    in(n);
    ll dp[3][n+1];
    ll v[3][n];
    for(ll i=0;i<n;i++) {
        cin>>v[0][i]>>v[1][i]>>v[2][i];
    }
    dp[0][0] = dp[1][0] = dp[2][0] = 0;
    for(ll i=1;i<=n;i++) {
        dp[0][i] = v[0][i-1] + max(dp[1][i-1],dp[2][i-1]);
        dp[1][i] = v[1][i-1] + max(dp[0][i-1],dp[2][i-1]);
        dp[2][i] = v[2][i-1] + max(dp[0][i-1],dp[1][i-1]);
    }
    cout<<max(dp[0][n],max(dp[1][n],dp[2][n]));
    return 0;
}