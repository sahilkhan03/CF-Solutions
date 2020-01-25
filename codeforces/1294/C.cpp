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
    fast;
    ll t;
    in(t);
    while(t--) {
        ll n;
        in(n);
        vl v;
        ll tmp=n;
        for(int i=2;i*i<=tmp;i++) {
            while(tmp%i==0) {
                v.push_back(i);
                tmp/=i;
            }
        }
        if(tmp>1) v.push_back(tmp);
        // for(auto x:v) cout<<x<<" ";
        // cout<<endl;
        if(v.size()<3) {cout<<"NO"<<endl;continue;}
        ll a=-1,b=-1,c=-1;
        a=v[0];b=v[1];
        if(b==a) b*=v[2];
        c=n/(a*b);
        if(c==b or c==a or c<=1) cout<<"NO"<<endl;
        else {cout<<"YES"<<endl<<a<<" "<<b<<" "<<c<<endl;}
    }
    return 0;
}