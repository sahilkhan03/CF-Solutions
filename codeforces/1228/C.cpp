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
#define ll int64_t
#define pi pair<int,int>
#define pl pair<long,long>
#define pll pair<long long,long long>
#define pld pair<long double,long double>
#define gc getchar_unlocked
#define pc putchar_unlocked
#define endl '\n'
#define loop(i,n) for(ll i=0;i<n;i++)
#define mod 1e9+7
#define in(x) scanf("%lld",&x)
#define in2(x,y) scanf("%lld %lld",&x,&y)
#define vl vector<ll>
#define mp make_pair

ll modpow(ll x,ll n,ll m) {
    if(!n) return 1%m;
    ll u = modpow(x,n/2,m);
    u = (u*u)%m;
    if(n%2 ==1) u = (u*x)%m;
    return u;
}

int main()
{
    ll x,n;
    in2(x,n);
    set<ll> s;
    for(ll i=2;i*i<=x;i++) {
        while(x%i==0) {
            s.insert(i);
            x/=i;
        }
    }
    if(x>1) s.insert(x);
    ll ans=1;
    // for(auto it:s) cout<<it<<endl;
    for(auto it:s) {
        ll w=0,j=1,tmp=1;
        while(pow(it,j)<=n) {
            ll p = pow(it,j);
            w += (n/p);
            // cout<<(tmp*modpow(p,w,(ll)(1e9+7)))%((ll)(1e9+7))<<" "<<it<<" "<<p<<" "<<w<<" "<<tmp<<endl;
            j++;
        }
tmp=modpow(it,w,((ll)(1e9+7)))%((ll)mod);
        ans= (ans*tmp)%((ll)(mod));
    }
    cout<<ans<<endl;
    return 0;   
}