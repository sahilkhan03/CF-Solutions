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
    ll n,k;
    in2(n,k);
    vector<string> s(n);
    unordered_map<string,ll> m;
    loop(i,n) {
        cin>>s[i];
        m[s[i]]=i;
    }
    ll ans=0;
    loop(i,n) {
        rep(j,i+1,n-1) {
            string a = s[i], b=s[j],req;
            loop(it,k) {
                char c = 'S';
                if(a[it]==b[it]) c=a[it];
                else if((a[it]=='S' and b[it]=='T') or (a[it]=='T' and b[it]=='S')) c='E';
                else if((a[it]=='E' and b[it]=='T') or (a[it]=='T' and b[it]=='E')) c='S';
                else if((a[it]=='S' and b[it]=='E') or (a[it]=='E' and b[it]=='S')) c='T';
                req+=c;
            }
            if(m.count(req) and m[req]>j) ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}