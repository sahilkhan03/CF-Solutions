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
    return a.first>b.first;
}


int main()
{
    ll n;
    in(n);
    vector<pair<ll,ll>> v(n);
    for(ll i=0;i<n;i++) {
        in(v[i].first);
        v[i].second = i+1;
    }
    ll ans=0;
    sort(v.begin(),v.end(),compare);
    // for(auto x:v) cout<<x.first<<endl;
    for(ll i=0;i<n;i++) {
        ans+=(v[i].first*i)+1;
    }
    cout<<ans<<endl;
    for(auto x:v) cout<<x.second<<" ";
    return 0;
}