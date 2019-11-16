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
    vpll v(n);
    for(auto &i:v) in2(i.first,i.second);
    sort(v.begin(),v.end());
    double sum=0,c=0;
    do {
        c++;
        double ans=0,a=v[0].first,b=v[0].second;
        for (ll i=1;i<n;i++) {
            ans+=hypot((double)(v[i].first-a),(double)(v[i].second-b));
            a = v[i].first;b=v[i].second;
        }
        // cout<<ans<<endl;
        sum+=ans;
    } while (next_permutation(v.begin(),v.end()));
    // cout<<c<<endl;
    printf("%.10lf\n",sum/(c));
    return 0;
}

