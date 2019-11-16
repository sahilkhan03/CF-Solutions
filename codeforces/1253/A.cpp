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
    ll t;
    in(t);
    while(t--) {
        ll n;
        in(n); 
        vl a(n),b(n),c(n,0);
        for(auto& i:a) in(i);
        for(auto& I:b) in(I);
        loop(i,n) c[i]=b[i]-a[i];
        bool ans = true;
        ll last = INF;
        loop(i,n) {
            if(c[i]<0) {
                ans=false;
                break;
            }
            if(c[i] and last == INF) {
                last = c[i];
            }
            else if(c[i]) {
                if(c[i]!=last) {
                    ans = false;
                    break;
                }
            }
        }
        if(ans) {
            ll co=0;bool up = false;;
            loop(i,n) {
                if(c[i] and !up) {
                    co++;
                    up=1;
                }
                else if(!c[i]) {
                    up=0;
                }
            }
            if(co>1) ans= false;
        }
        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}
