/*                    ___          |\    /|           ____   ____   ____  ____
   |     |    /\    /    \ |     | | \  / |    /\    |    \ |    \ |     |    \
   |_____|   /__\   \____  |_____| |  \/  |   /__\   |____/ |____/ |__   |____/
   |     |  /    \       \ |     | |      |  /    \  |      |      |     |   \
   |     | /      \ \____/ |     | |      | /      \ |      |      |____ |    \
*/
#include<bits/stdc++.h>
using namespace std;
#define lb lower_bound
#define ub upper_bound
#define pf push_front
#define pb push_back
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define pi pair<int,int>
#define pl pair<long,long>
#define pll pair<long long,long long>
#define pld pair<long double,long double>
#define gc getchar_unlocked
#define pc putchar_unlocked
#define endl '\n'
#define loop(i,n) for(ll i=0;i<n;i++)
#define mod ((ll)(1e9+7))
#define in(x) scanf("%lld",&x)
#define in2(x,y) scanf("%lld %lld",&x,&y)
#define vl vector<ll>
#define ml unordered_map<ll,ll> 
#define vpll vector<pair<ll,ll>>
#define INF 0x3f3f3f3f
#define mp make_pair

int main()
{
    ll t;
    in(t);
    while(t--) {
        ll n,k,d;
        cin>>n>>k>>d;
        vl v(n);
        for(auto&i :v) in(i);
        ll ans = k,c=0;
        ml m;
        for(ll i=0;i<d;i++) {
            if(!m[v[i]]) {
                c++;
            }
            m[v[i]]++;
        } 
        ans = min(ans,c);
        for(ll i=d;i<n;i++) {
            m[v[i-d]]--;
            if(!m[v[i-d]]) c--;
            if(!m[v[i]]) {
                c++;
            }
            m[v[i]]++;
            ans= min(ans,c);
            // cout<<c<<" "<<ans<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}