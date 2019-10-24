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

int main()
{
    fast;
    ll n,m;
    in2(n,m);
    ll v[n][m],dp[n+5][m+5],best[n+5];
    memset(best,0,sizeof best);
    loop(i,n) loop(j,m) in(v[i][j]);
    
    for(ll i=1;i<=m;i++) {
        dp[n][i]=1;
    }

    best[n] = 1;
    
    for(ll i=n-1;i>0;i--) {
        for(ll j=1;j<=m;j++) {
            if(v[i-1][j-1]<=v[i][j-1]) dp[i][j]=dp[i+1][j]+1;
            else dp[i][j]=1;
            best[i] = max(best[i],dp[i][j]);
        }
    }

    ll q;in(q);
    while (q--)
    {
        ll l,r;
        in2(l,r);
        if(l+best[l]>= r+1) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    


    return 0;
}