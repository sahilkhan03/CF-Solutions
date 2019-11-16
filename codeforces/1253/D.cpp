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
 
vector<vector<ll>> v(200005);
vector<bool> visited(200005);
ll mx=0;
void dfs(ll node) {
    if(visited[node]) return; 
    visited[node] = true;
    mx = max(mx,node);
    for(auto x:v[node]) dfs(x);
}

int main() {
    ll n,m,ans=0;
    in2(n,m);
    while(m--) {
        ll a,b;
        in2(a,b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(ll i=1;i<=n;i++){
        if(!visited[i]) {
            if(i<mx) ans++;
            dfs(i);
        }
    }
    cout<<ans<<endl;
    return 0;
}