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
    ll n,m;
    in2(n,m);
    vl a(n),b(n);
    for(auto&i:a) in(i);
    for(auto&i:b) in(i);
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    vl v,ans;
    loop(i,n) v.push_back((m+b[i]-a[0])%m);
    loop(i,n) {
        vl tmp = a;
        for(auto&x:tmp) x = (x+v[i])%m;
        bool flag = true;
        sort(tmp.begin(),tmp.end());
        loop(j,n) {
            if(tmp[j]!=b[j]) {
                flag=false;
                break;
            }
        }
        if(flag) ans.push_back(v[i]);
    }
    cout<<*min_element(ans.begin(),ans.end());
    return 0;
}