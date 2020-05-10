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
#define ordered_set tree<pl, null_type,less<pl>, rb_tree_tag,tree_order_statistics_node_update>
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
#define rep(i, begin, end) for (__typeof(begin) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
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

int main() {
    fast;
    // int t; scanf("%d",&t);
    // while(t--) {
    // }
    ll n,m,x; in3(n,m,x);
    ll v[n][m]; vl c(n);
    loop(i,n) {
        in(c[i]);
        loop(j,m) in(v[i][j]);
    }
    loop(j,m) {
        ll sum=0;
        loop(i,n) sum+=v[i][j];
        if(sum<x) {
            cout<<-1<<endl;
            return 0;
        }
    }
    ll ans = 1e18;
    loop(i,1<<n) {
        ll sum=0;
        vl tmp(m,0);
        bool f=0;
        loop(j,n) {
            if(i&(1<<j)) {
                f=1;sum+=c[j];
                loop(k,m) tmp[k]+=v[j][k];
            }
        }
        if(!f) continue;
        loop(j,m) if(tmp[j]<x) {
            goto skip;
        };
        ans = min(ans,sum);
        // cout<<sum<<"-"<<ans<<"-"<<tmp<<endl;
        skip:;
    }
    cout<<ans<<endl;
    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}