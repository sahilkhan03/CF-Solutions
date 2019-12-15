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

int main() {
    string s;
    cin>>s;
    ll ans=0,n=s.size();
    vl c(n,-1),d(n,-1);
    stack<ll> st;
    loop(i,n) {
        if(s[i]=='(') st.push(i); 
        else {
            if(st.empty()) continue;
            d[i]=st.top();
            st.pop();
            c[i] = i - d[i] +1;
            if(d[i]>0) c[i]+=(c[d[i]-1]==-1 ? 0  : c[d[i]-1]);
            ans = max(ans,c[i]);
        }
    }
    // cout<<c<<endl<<d<<endl;
    if(ans) {
        ll count=0;
        loop(i,n) if(c[i]==ans) count++;
        cout<<ans<<" "<<count<<endl;
    }
    else cout<<0<<" "<<1<<endl;
    return 0;
}