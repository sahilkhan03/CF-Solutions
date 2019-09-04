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
#define mp make_pair

int main()
{
    ll n,m;
    in2(n,m);
    vl v(m+1,0);
    for(ll i=2;i*i<=m;i++) {
        if(!v[i]) {
            for(ll j=2*i;j<=m;j+=i) v[j] = i;
            // cout<<i<<endl;
        }
        // cout<<i<<endl;
    }
    // for(auto x:v) cout<<x<<endl;
    ll ans = m;
    for(ll i=n+1;i<=m;i++) if(!v[i]) {
        ans=i;
        break;
    }
    // cout<<ans;
    cout<<((v[m] or ans!=m) ? "NO" : "YES")<<endl;
    return 0;
}