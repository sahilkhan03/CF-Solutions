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
#define mod ((ll)(1e9+7))
#define in(x) scanf("%lld",&x)
#define in2(x,y) scanf("%lld %lld",&x,&y)
#define in3(x,y,z) scanf("%lld %lld %lld",&x,&y,&z)
#define inv(v) for(auto&i:v) in(i)
#define vl vector<ll>
#define ml unordered_map<ll,ll> 
#define vpl vector<pair<ll,ll>>
#define INF 0x3f3f3f3f

int main() {
    ll n;in(n);
    vl v(n);inv(v);
    ll ans=1;
    vl p(n,1),s(n,1);
    for(ll i=n-2;i>=0;i--) {
        if(v[i]<v[i+1]) s[i]=s[i+1]+1;  
    }
    for(ll i=1;i<n;i++) {
        if(v[i]>v[i-1]) p[i]=p[i-1]+1;  
    }
    for(ll i=0;i<n;i++) 
            if(i>0 and i<n-1 and v[i-1]<v[i+1]) ans=max(ans,p[i-1]+s[i+1]);
            else if(i<1) ans = max(ans,s[i]);
            else ans = max(ans,p[i]);
    cout<<ans<<endl;
    return 0;
}