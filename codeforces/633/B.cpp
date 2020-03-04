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

ll func(ll n) {
    ll c=0;
    while(n) {
        c+=n/5;
        n/=5;
    }
    return c;
}

int main() {
    fast;
    ll m;
    in(m);
    ll b = 5*m;
    while(true) {
        if(func(b)<m) {
            cout<<0<<endl;
            return 0;
        }
        else if(func(b)==m) break;
        b-=5;
    }
    cout<<5<<endl<<b<<" "<<b+1<<" "<<b+2<<" "<<b+3<<" "<<b+4<<endl;
    return 0;
}