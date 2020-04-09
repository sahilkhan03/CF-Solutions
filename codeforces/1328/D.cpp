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

struct node
{
    pl cur,dest;
};

bool cmp(node a, node b ) {
    return abs(a.dest.first-a.cur.first) + abs(a.dest.second - a.cur.second) > abs(b.dest.first-b.cur.first) + abs(b.dest.second - b.cur.second);
}

int main() {
    ll t;
    in(t);
    while(t--) {
        ll n;in(n);
        vl v(n);
        loop(i,n) in(v[i]);
        vl ans(n,1);
        ll c=1,pos=-1;
        rep(i,1,n-1) {
            if(v[i]==v[i-1]) ans[i]=ans[i-1], pos=i;
            else if(ans[i-1]==1) ans[i]=2;
            else ans[i]=1;
            c = max(c,ans[i]);
        }
        if(v[0]!=v[n-1] and ans[0]==ans[n-1]) {
            if(pos==-1) ans[n-1]=3,c=3;
            else if(ans[pos]==1) ans[pos]=2;
            else ans[pos]=1;
            if(pos!=-1) rep(i,pos+1,n-1) if(ans[i]==1) ans[i]=2; else ans[i]=1;
        }
        cout<<c<<endl<<ans<<endl;
    }
    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}