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

bool  compare(pll a, pll b ) {
    return min(a.first*2,a.second)-min(a.first,a.second)>min(b.first*2,b.second)-min(b.first,b.second);
}

int main()
{
    ll n,x;
    in2(n,x);
    vector<pll> v(n);
    for(auto& i:v) in2(i.first,i.second);
    sort(v.begin(),v.end(),compare);
    ll ans=0,c=0;
    // for(auto y:v) cout<<y.second<<" ";
    for(ll i=0;i<x;i++) {ans+=min(2*v[i].first,v[i].second);}
    for(ll i=x;i<n;i++) ans+=min(v[i].first,v[i].second);
    cout<<ans<<endl;
    return 0;
}