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
#define mod 1e9+7
#define in(x) scanf("%lld",&x)
#define in2(x,y) scanf("%lld %lld",&x,&y)
#define vl vector<ll>
#define mp make_pair


bool compare(pll a, pll b) {
    return b.second<a.second;
}



int main()
{
    ll n,en=0;
    in(n);
    ll ans=0;
    vl v(n+1);
    v[0]=0;
    for(ll i=1;i<=n;i++) in(v[i]);
    for(ll i=1;i<=n;i++) {
        en += v[i-1] - v[i];
        if(en<0) {
            ans+=abs(en);
            en=0;
            // cout<<ans<<endl;
        }
        // cout<<en<<"-"<<endl;
    }
    cout<<ans<<endl;
    return 0;
}