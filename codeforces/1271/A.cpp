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
#define mod ((ll)(1e9+7))
#define in(x) scanf("%lld",&x)
#define in2(x,y) scanf("%lld %lld",&x,&y)
#define in3(x,y,z) scanf("%lld %lld %lld",&x,&y,&z)
#define inv(v) for(auto&i:v) in(i)
#define vl vector<ll>
#define ml unordered_map<ll,ll> 
#define vpl vector<pair<ll,ll>>
#define INF 0x3f3f3f3f

template<typename T, typename TT>
ostream& operator<<(ostream &os, const pair<T, TT> &t) { return os<<t.first<<" "<<t.second; }
template<typename T>
ostream& operator<<(ostream& os, const vector<T> &t) { for(auto& i: t) os<<i<<" "; return os; }

bool check(string a,string b) {
    ll j=0,l = min(a.size(),b.size());
    for(ll i=0;i<l;i++,j++) {
        if(a[i]<b[j]) return true;
        else if(a[i]>b[j]) return false;
    }
    if(a.size()<b.size()) return true;
    return false;
}

int main() {
    ll a,b,c,d,e,f;
    in3(a,b,c);in3(d,e,f);
    ll ans=0;
    if(e>f) {
        ans+=min(a,d)*e;
        ll t= min(a,d);
        a-=t;
        d-=t;
        ans+=min(b,min(c,d))*f;
    }
    else{
        ans+=min(b,min(c,d))*f;
        ll t = min(b,min(c,d));
        b-=t;
        c-=t;
        d-=t;
        ans+=min(a,d)*e;
    }
    cout<<ans<<endl;
    return 0;
}