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

int main() {
    ll t;
    in(t);
    while(t--) {
        ll a,b,c;in3(a,b,c);
        vl va = {a,a+1,a-1};
        vl vb = {b,b+1,b-1};
        vl vc = {c,c+1,c-1};
        ll ans= abs(a-b) + abs(a-c)+abs(b-c);
        loop(i,3) loop(j,3) loop(k,3) ans = min(ans, abs(va[i]-vb[j])+abs(va[i]-vc[k])+abs(vb[j]-vc[k]));
        cout<<ans<<endl;
    }
    return 0;
}