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
#define it(i,a,b) for(i=a;i<b;i++)
#define mod 1e9+7
#define in(x) scanf("%lld",&x)
#define in2(x,y) scanf("%lld %lld",&x,&y)
#define vl vector<ll>
#define mp make_pair

int main()
{
    fast
    ll n;
    in(n);
    ll ans=0;
    ll neg = 0;
    vector<ll> v(n);
    for(ll i=0;i<n;i++) in(v[i]);
    sort(v.begin(),v.end());
    auto zero = equal_range(v.begin(),v.end(),0);
    ll neg_count = zero.first - v.begin();
    ll neg_sum = 0;
    for(ll i=0;i<neg_count;i++) neg_sum+=v[i];
    ans+=(-1*neg_count)-neg_sum;
    // cout<<neg_count<<" "<<neg_sum<<" "<<ans<<endl;
    ll pos_start = zero.second- v.begin(),pos_sum=0;
    for(ll i=pos_start;i<v.size();i++) pos_sum+=v[i];
    ans+=pos_sum-(v.size()-pos_start);
    // cout<<pos_sum<<" "<<ans<<endl;
    ans+=zero.second-zero.first;
    // cout<<zero.second-zero.first<<endl;
    if(neg_count%2!=0) {
       if(!(zero.second-zero.first)) ans+=2;
    }
    cout<<ans<<endl;
    return 0;
}