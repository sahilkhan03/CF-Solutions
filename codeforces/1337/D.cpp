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

ll func(vl a, vl b, vl c){
    ll ans=9e18;
    for(auto x:a) {
        ll y,z,i1 = lower_bound(all(b),x)- b.begin(), i2 = lower_bound(all(c),x) - c.begin();
        if(b[0]>x or i2>=c.size()) continue;
        if(i1==b.size() or b[i1]>x) i1--;
        y = b[i1]; z = c[i2];
        ans = min(ans, (x-y)*(x-y) + (y-z)*(y-z) + (z-x)*(z-x));
    }
    return ans;
}


int main() {
    fast;
    ll t;
    in(t);
    while(t--) {
        ll na,nb,nc;in3(na,nb,nc);
        vl va(na),vb(nb),vc(nc);
        inv(va);inv(vb);inv(vc);
        ll ans = 9e18;
        sort(all(va));sort(all(vb));sort(all(vc));
        ans = min(ans,func(va,vb,vc));
        ans = min(ans,func(va,vc,vb));
        ans = min(ans,func(vb,va,vc));
        ans = min(ans,func(vb,vc,va));
        ans = min(ans,func(vc,vb,va));
        ans = min(ans,func(vc,va,vb));
        cout<<ans<<endl;
    }
    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}