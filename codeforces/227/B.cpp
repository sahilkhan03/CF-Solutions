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
    ll n;
    in(n);
    unordered_map <ll,ll> v;
    for(ll i=0;i<n;i++) {
        ll t;
        in(t);
        v[t] = i+1;
    }
    ll m;in(m);
    ll a=0,b=0;
    while(m--) {
        ll t;
        in(t);
        if(v.count(t)) {
            a+=v[t];
            b+=n-v[t]+1;
        }else {
            a+=n;b+=n;
        } 
    }
    cout<<a<<" "<<b<<endl;
    return 0;
}