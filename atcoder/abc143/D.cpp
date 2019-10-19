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
#define mod (ll)(1e9+7)
#define in(x) scanf("%lld",&x)
#define in2(x,y) scanf("%lld %lld",&x,&y)
#define vl vector<ll>
#define vpll vector<pair<ll,ll>>
#define INF 0x3f3f3f3f
#define mp make_pair

ll dp[1005][1005];

int main()
{
    ll n,ans=0;
    in(n);
    vl v(n);
    for(auto& i:v) in(i);
    sort(v.begin(),v.end());
    ll sum=0;
    for(ll dif=1;dif<n;dif++) {
        sum=0;
        for(ll i=dif;i<n;i++) {
            sum=v[i]+v[i-dif];
            ll lt = lower_bound(v.begin(),v.end(),sum) - v.begin();
            ans+=lt-i-1;
            // cout<<sum<<" "<<lt-i-1<<endl;
        }
    }
    cout<<ans<<endl;
}