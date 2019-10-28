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

ll calc (ll l) {
    ll n = log2(l+1);
    if(n%2==1) {
        ll odd = (n/2)+1;
        ll even = n/2;
        ll odd_count = (((ll)pow(2,2*odd)-1)/3);
        ll even_count = (2*(((ll)pow(2,2*even)-1)/3));
        ll sum_odd = ((odd_count%mod) * (odd_count%mod))%mod;
        ll sum_even = ((even_count%mod)*((even_count%mod)+1))%mod;
        ll num_rem=l- (odd_count+even_count);
        ll last = 2*(even_count+1);
        ll rem = ((num_rem%mod)*((last%mod) + (num_rem-1)%mod)%mod)%mod;
        return ((sum_even%mod) + (sum_odd%mod) + (rem%mod))%mod;
    }
    else {
        ll odd = (n/2);
        ll even = n/2;
        ll odd_count = (((ll)pow(2,2*odd)-1)/3);
        ll even_count = (2*(((ll)pow(2,2*even)-1)/3));
        ll sum_odd = ((odd_count%mod)*(odd_count%mod))%mod;
        ll sum_even = ((even_count%mod)*((even_count%mod)+1))%mod;
        ll num_rem = l- (odd_count+even_count);
        ll last = 2*(odd_count)+1;
        ll rem = ((num_rem%mod)*((last%mod) + (num_rem-1)%mod)%mod)%mod;
        return ((sum_even%mod) + (sum_odd%mod) + (rem%mod))%mod;
    }
}

int main() {
    ll l,r;
    in2(l,r);
    cout<<(mod + calc(r) - calc(l-1))%mod<<endl;
    return 0;
}

