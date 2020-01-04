/*                    ___          |\    /|           ____   ____   ____  ____
   |     |    /\    /    \ |     | | \  / |    /\    |    \ |    \ |     |    \
   |_____|   /__\   \____  |_____| |  \/  |   /__\   |____/ |____/ |__   |____/
   |     |  /    \       \ |     | |      |  /    \  |      |      |     |   \
   |     | /      \ \____/ |     | |      | /      \ |      |      |____ |    \
*/
#include<bits/stdc++.h>
using namespace std;
#define isko_lga_dala_to_life_jhinga_la_la ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
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

int main() {
    ll n;in(n);
    vector<ll> ar,ar1;
    ll c=0;
    for(ll i=0;i<n;i++) {
        ll m;in(m);
        bool flag = false;
        ll mn=INT64_MAX,mx=INT64_MIN;
        for(ll j=0;j<m;j++) {
            ll tmp;in(tmp);
            if(tmp>mn) {
                flag = 1;
            }
            if(tmp>mx) mx=tmp;
            if(tmp<mn) mn=tmp;
        }
        if(flag) c++;
        else ar.push_back(mn),ar1.push_back(mx);
    }
    ll ans = 0;
    ans+=2*((c*n) - (((c-1)*c)/2)) -c;
    // cout<<c<<" "<<ans<<endl;
    sort(ar.begin(),ar.end());
    sort(ar1.begin(),ar1.end());
    for(ll i=0;i<ar.size();i++) ans+=ar1.end()-upper_bound(ar1.begin(),ar1.end(),ar[i]);
    cout<<ans<<endl;
    return 0;
}