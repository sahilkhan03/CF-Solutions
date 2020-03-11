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

int main() {
    ll n,m;in2(n,m);
    vl b(n),g(m);
    loop(i,n) in(b[i]);
    loop(i,m) in(g[i]);
    sort(all(b),greater<ll>());
    sort(all(g),greater<ll>());
    if(b[0]>g[m-1]) {
        cout<<-1<<endl;
        return 0;
    }
    else if(n==1) {
        ll ans=0;
        if(find(all(g),b[0])==g.end()) ans=-1;
        else loop(i,m) ans+=g[i];
        cout<<ans<<endl;
        return 0;
    }
    else if(m==1) {
        loop(i,n) if(b[i]!=g[0]) {
            cout<<-1<<endl;
            return 0;
        }
        cout<<g[0]*n<<endl;
        return 0;
    }
    else if(b[0]<g[m-1]) {
        ll ans=b[0];
        loop(i,m) ans+=g[i];
        ans+=(m-1)*b[1];
        rep(i,2,n-1) ans+=m*b[i];
        cout<<ans<<endl;
        return 0;
    }
    ll i=0,j=0,ans=0;
    while (i<n) {
        ans+=j*b[i];
        while(j<m and b[i]<=g[j]) ans+=g[j++];
        ans+=(m-j)*b[i++];
    }
    cout<<ans<<endl;
    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}