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
 
ll calc(ll n) {
    if(!n) return 1;
    if(n==1) return 2;
    ll u = calc(n/2);
    u = ((u%mod)*(u%mod))%mod;
    if(n%2==1) return (2*u)%mod;
    return u%mod;
}

int main() {
    ll n,q;
    in2(n,q);
    vl v(n+1,0);
    string s; 
    cin>>s;
    loop(i,n) {v[i+1] = (ll)(s[i]-'0');}
    for(ll i = 1 ;i<n+1;i++) v[i]+=v[i-1];
    // loop(i,n+1) cout<<v[i]<<" ";
    // cout<<endl; 
    while ((q--))
    {
        ll l,r;
        in2(l,r);
        // cout<<" --- "<<((calc(v[r]-v[l-1])-1)%mod)<<endl;
        cout<<(((calc(v[r]-v[l-1])-1)%mod)*(calc(r-l+1 - v[r] + v[l-1])%mod))%mod<<endl;
    }
    
    
    return 0;
}