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
#define mod ((ll)(1e9+7))
#define in(x) scanf("%lld",&x)
#define in2(x,y) scanf("%lld %lld",&x,&y)
#define vl vector<ll>
#define ml unordered_map<ll,ll> 
#define vpll vector<pair<ll,ll>>
#define INF 0x3f3f3f3f
#define mp make_pair

double dp[2005][2005];

int main()
{
    ll n,t;
    double p;
    cin>>n>>p>>t;
    dp[0][0]=1;
    for(ll i=1;i<=t;i++) dp[i][0] = dp[i-1][0]*(1-p);
    // for(ll j=1;j<=n;j++) dp[0][j];
    for(ll i=1;i<=t;i++)
    for(ll j=1;j<=n;j++) dp[i][j] = (dp[i-1][j-1]*p) + ((j==n ? (dp[i-1][j]) : (dp[i-1][j]*(1-p))));
    // loop(i,t+1) {
    //      loop(j,n+1) cout<<dp[i][j]<<" "; 
    //      cout<<endl;
    // }
    double ans=0;
    loop(i,n+1) ans+=dp[t][i]*i;
    printf("%.6lf\n",ans);
    return 0;
}