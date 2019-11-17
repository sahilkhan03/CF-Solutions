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
    ll n;
    in(n);
    vl v;
    for(ll i=1;i*i<=n;i++) {
        if(n%i==0) {
            if(i*i==n) v.push_back(i);
            else {
                v.push_back(i);
                v.push_back(n/i);
            };
        }
    }
    ll ans=0;
    ml m;
    
    while(n) {
        m[n%10]++;
        n/=10;
    }
    loop(i,v.size()) {
        while (v[i])
        {
            if(m[v[i]%10]) {ans++;break;}
            v[i]/=10;
        }
    }
        cout<<ans<<endl;
    return 0;
}