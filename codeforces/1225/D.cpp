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

int main() {
    ll n,k,ans=0;
    in2(n,k);
    vl v(n); ml m;
    for(auto& tmp:v) in(tmp);
    for(auto x:v) {
        map<ll,ll> f;
        for(ll j=2;j*j<=x;j++) {
            while(x%j==0) {
                f[j]++;
                x/=j;
            }  
        }
        if(x>1) f[x]++;
        ll num=1,req=1;
        // for(auto it:f) cout<<it.first<<"-"<<it.second<<endl;
        for(auto it:f) {
            num*=pow(it.first,it.second%k);
            req*=pow(it.first,(k-(it.second%k))%k);
        }
        // cout<<" "<<req<<" "<<m[req]<<" "<<num<<endl<<ans<<endl;;
        ans+=m[req];
        m[num]++;
    } 
    cout<<ans<<endl;
    return 0;
}

