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
    ll n;
    pl s;
    in3(n,s.first,s.second);
    vpl v(n);
    for(auto&i:v) in2(i.first,i.second);
    pl p1={s.first+1,s.second},p2={s.first,s.second+1},p3={s.first-1,s.second},p4={s.first,s.second-1};
    vl c(4,0);
    loop(i,n) {
        ll a=v[i].first,b=v[i].second;
        if(((a<=p1.first and p1.first<=s.first)or(a>=p1.first and p1.first>=s.first))and((b<=p1.second and p1.second<=s.second)or(b>=p1.second and p1.second>=s.second))) c[0]++;
        if(((a<=p2.first and p2.first<=s.first)or(a>=p2.first and p2.first>=s.first))and((b<=p2.second and p2.second<=s.second)or(b>=p1.second and p1.second>=s.second))) c[1]++;
        if(((a<=p3.first and p3.first<=s.first)or(a>=p3.first and p3.first>=s.first))and((b<=p3.second and p3.second<=s.second)or(b>=p1.second and p1.second>=s.second))) c[2]++;
        if(((a<=p4.first and p4.first<=s.first)or(a>=p4.first and p4.first>=s.first))and((b<=p4.second and p4.second<=s.second)or(b>=p4.second and p4.second>=s.second))) c[3]++;
    }
    ll ans = *max_element(c.begin(),c.end());
    cout<<ans<<endl;
    ll pos = max_element(c.begin(),c.end()) - c.begin();
    if(pos==0) cout<<p1<<endl;
    else if(pos==1) cout<<p2<<endl;
    else if(pos==2) cout<<p3<<endl;
    else cout<<p4<<endl;
    return 0;
}