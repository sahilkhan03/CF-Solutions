/*                    ___          |\    /|           ____   ____   ____  ____
   |     |    /\    /    \ |     | | \  / |    /\    |    \ |    \ |     |    \
   |_____|   /__\   \____  |_____| |  \/  |   /__\   |____/ |____/ |__   |____/
   |     |  /    \       \ |     | |      |  /    \  |      |      |     |   \
   |     | /      \ \____/ |     | |      | /      \ |      |      |____ |    \
*/
#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
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
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define mod ((ll)(1e9+7))
#define in(x) scanf("%lld",&x)
#define in2(x,y) scanf("%lld %lld",&x,&y)
#define in3(x,y,z) scanf("%lld %lld %lld",&x,&y,&z)
#define inv(v) for(auto&i:v) in(i)
#define all(x) x.begin(), x.end()
#define vl vector<ll>
#define ml unordered_map<ll,ll> 
#define vpl vector<pair<ll,ll>>
#define INF 0x3f3f3f3f

template<typename T, typename TT>
ostream& operator<<(ostream &os, const pair<T, TT> &t) { return os<<t.first<<" "<<t.second; }
template<typename T>
ostream& operator<<(ostream& os, const vector<T> &t) { for(auto& i: t) os<<i<<" "; return os; }

ll func(vector<ml> &v, vl &h, vector<bool> &vs, ll node) {
    if(h[node]!=-1) return h[node];
    h[node]=0;
    vs[node]=1;
    for(auto x:v[node]) 
        if(!vs[x.first]) 
            h[node]+=1+func(v,h,vs,x.first);
    return h[node];
}

int main() {
    fast;
    ll n,k;in2(n,k);
    vector<ml> v(n,ml());
    loop(i,n-1) {
        ll a,b;in2(a,b) ;
        a--,b--;
        v[a][b]=1;
        v[b][a]=1;
    }
    vector<bool> vis(n,0);
    vector<ll> dis(n,0);
    queue<pl> q; 
    q.push({0,0});
    while(!q.empty()) {
        auto tp = q.front(); q.pop();
        if(vis[tp.first]) continue;
        vis[tp.first] = 1;
        dis[tp.first] = tp.second;
        for(auto x:v[tp.first]) if(!vis[x.first]) q.push({x.first,tp.second+1});
    }
    vector<ll> h(n,-1);
    vector<bool> vs(n,0);
    func(v,h,vs,0);
    // cout<<h<<endl;
    ll ans=0;
    loop(i,n) dis[i]-=h[i];
    sort(dis.begin(),dis.end(),greater<ll>());
    loop(i,k) ans+=dis[i];
    cout<<ans<<endl;
    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}